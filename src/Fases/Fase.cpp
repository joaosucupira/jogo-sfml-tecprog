#include "Fase.hpp"

using namespace Fases;

Fase::Fase():
pJog1(NULL),
pJog2(NULL),
ativa(false),
pGE(NULL),
GC(),
vencida(false)
{
    GC.adicionarObservador(this); // Gerenciador de colisoes é observado pela fase
    srand(time(NULL));
    entidades = new ListaEntidades();
    entidades->excluiTodos();
}


Fase::~Fase() {
    pJog1 = NULL;
    pJog2 = NULL;
    entidades->excluiTodos();
    if (entidades) delete entidades;
    entidades = NULL; 
    ativa = false;
    GC.removerObservador(this);
}

void Fase::salvar(){
    if(entidades)
        entidades->salvar();
    else
        cout << "Fase::salvar() -> ponteiro nulo entidades" << endl;
}

void Fase::configurarJogador() {

    if (!pJog1) {
        cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 1 nao configurado" << endl;
        return;
    }

    GC.setPJog1(pJog1);
    entidades->adiciona(static_cast<Entidade*>(pJog1));
    pJog1->setXY(LARG_PLATAFORMA * 4.0, ALTURA - (LARG_PLATAFORMA * 2));

    if(!pJog2) {
        cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 2 nao configurado" << endl;
        return;
    }

    GC.setPJog2(pJog2);
    entidades->adiciona(static_cast<Entidade*>(pJog2));
    pJog2->setXY(LARG_PLATAFORMA * 5.0, ALTURA - (LARG_PLATAFORMA * 2));
}

void Fase::recuperarJogador()
{
    if (!pJog1) {
        cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 1 nao configurado" << endl;
        return;
    }

    GC.setPJog1(pJog1);
    entidades->adiciona(static_cast<Entidade*>(pJog1));

    if(!pJog2) {
        cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 2 nao configurado" << endl;
        return;
    }

    GC.setPJog2(pJog2);
    entidades->adiciona(static_cast<Entidade*>(pJog2));
}

void Fase::renderizarEntidades()
{
    if (entidades->vazia()) {
        cout << "void Fase::renderizarEntidades() -> Lista vazia." << endl;
        return;
    }
    int tamanho = (*entidades).getTamanho();

    Entidade* pE = NULL;
    for (int i = 0; i < tamanho; i++) {
        pE = (*entidades)[i];
        if (pE) {
           pE->executar();
        } else { cout << "void Fase::renderizarEntidades() -> ponteiro nulo" << endl; }
        pE = NULL;
    }
    if (pE) delete pE;
    pE = NULL;
}

void Fase::gerenciarEventos()
{
    if(pGE)
        pGE->executar();
    else
        cout << "Fase::gerenciarEventos() -> ponteiro nulo" << endl;
}

void Fase::gerenciarColisoes() {
    
    GC.executar();
}

void Fase::criarCenario() {

    
    // chao e teto
    Vector2f inicio(0.0f, ALTURA - ALT_PLATAFORMA);
    construirPlano(LARGURA, inicio);

    Vector2f inicio6(0.0f, -ALT_PLATAFORMA);
    construirPlano(LARGURA, inicio6);

    
    // paredes
    Vector2f inicio2(0.0f - LARG_PLATAFORMA / 2.0f, 0.0f);
    construirParede(ALTURA, inicio2);

    Vector2f inicio3(LARGURA - LARG_PLATAFORMA / 2.0f, 0.0f);
    construirParede(ALTURA, inicio3);


}

void Fase::construirPlano(const float tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;


    pP = new Plataforma(inicio.x , inicio.y);
    pP->setTamanhoFigura(tamanho, ALT_PLATAFORMA);
    entidades->adiciona(static_cast<Entidade*>(pP));
    GC.incluirObst(static_cast<Obstaculo*>(pP));
    pP = NULL;


    if (pP) delete pP;
    pP = NULL;
}

void Fase::construirParede(const float tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;


    pP = new Plataforma(inicio.x , inicio.y);
    pP->setTamanhoFigura(LARG_PLATAFORMA, tamanho);
    entidades->adiciona(static_cast<Entidade*>(pP));
    GC.incluirObst(static_cast<Obstaculo*>(pP));
    pP = NULL;


    if (pP) delete pP;
    pP = NULL;
}

void Fase::setJogador(Jogador *pJ, const int num_jogador)
{
    if (pJ) {
        if (num_jogador == 1) {
            pJog1 = pJ;
        } else {
            pJog2 = pJ;
        }
        
    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}

void Fase::setPGEventos(GerenciadorEventos *pG)
{
    if(pG)
        pGE = pG;
    else
        cout << "Fase::setPGEventos(GerenciadorEventos *pG) -> ponteiro nulo" << endl;
}

void Fase::recuperarViajantesMaus()
{
    float x,y;
    int num_vidas;
    bool andando,planando;
    ifstream buffer(VIAJANTE_MAU_SALVAR_PATH);
    ViajanteMau* pViaMau = NULL;

    while(buffer >> x >> y >> num_vidas >> andando >> planando){

        pViaMau = new ViajanteMau(x,y);

        pViaMau->setAndando(andando);
        pViaMau->setVidas(num_vidas);
        pViaMau->calcVivo();
        pViaMau->setPlanando(planando);

        entidades->adiciona(static_cast<Entidade*>(pViaMau));
        GC.incluirInim(static_cast<Inimigo*>(pViaMau));

        pViaMau = NULL;
    }

    buffer.close();
}

void Fase::recuperarPlataformas()
{

    float x,y;
    Vector2f tam;

    ifstream buffer(PLATAFORMA_SALVAR_PATH);
    Plataforma* pPlat = NULL;

    while(buffer >> x >> y >> tam.x >> tam.y){

        pPlat = new Plataforma(x,y);

        pPlat->setTamanhoFigura(tam.x,tam.y);

        entidades->adiciona(static_cast<Entidade*>(pPlat));
        GC.incluirObst(static_cast<Obstaculo*>(pPlat));

        pPlat = NULL;

    }

    buffer.close();
}
// Notificação do observer
void Fase::notificar() {
    cout << "Notificacao!!" << endl;

    cout << "inimigos = " << GC.getInimigosVivos() << endl;
    
    if (GC.getInimigosVivos() <= 0) {
        vencida = true;
        cout << "FASE VENCIDA" << endl;
    }

}