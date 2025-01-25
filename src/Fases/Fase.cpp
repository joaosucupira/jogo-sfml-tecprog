#include "Fase.hpp"

using namespace Fases;

Fase::Fase() :
ativa(false),
gravidade(1.0),
GE(),
GC()
// entidades()
{
    srand(time(NULL));
    entidades = new ListaEntidades();
    entidades->excluiTodos();
    criarCenario();
    
}

Fase::~Fase() {
    entidades->excluiTodos();
    if (entidades) delete entidades;
    entidades = NULL; 
    ativa = false;
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
    GE.executar();
}

void Fase::gerenciarColisoes() {
    
    GC.executar();
}

void Fase::executar() { 

    ativa = true;
    pGG->desenharEnte(this);

    gerenciarColisoes();

    gerenciarEventos();

    renderizarEntidades();


}

void Fase::criarPlataformas() {
    for (int i = 1; i < 3; i++) {
        construirPlano(16, Vector2f(0.0f, ALTURA - (ALT_PLATAFORMA) * i));
    }
    for (int i = 0; i < 20; i++) {
        construirPlano(1, Vector2f(0.0f - LARG_PLATAFORMA / 2, ALTURA - (ALT_PLATAFORMA) * i));
        construirPlano(1, Vector2f(LARGURA - LARG_PLATAFORMA / 2, ALTURA - (ALT_PLATAFORMA) * i));
    }
}

void Fases::Fase::construirPlano(const int tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;

    for (int i = 0; i < tamanho; i++) {
        pP = new Plataforma(i * (LARG_PLATAFORMA) + inicio.x, inicio.y);
        entidades->adiciona(static_cast<Entidade*>(pP));
        GC.incluirObst(static_cast<Obstaculo*>(pP));
        pP = NULL;
    }

    if (pP) delete pP;
    pP = NULL;
}

void Fases::Fase::criarCenario() {

    criarPlataformas();
}

void Fase::criarViajantesMaus(){
    ViajanteMau* pVM = NULL;
    pVM = new ViajanteMau(LARGURA-TAM_JOGADOR,0);
    if(pVM){
        entidades->adiciona(static_cast<Entidade*>(pVM));
        GC.incluirInim(static_cast<Inimigo*>(pVM));
    }
    else
        cout<< "Fase::criarViajantesMaus() -> Erro na alocacao dinamica" << endl;
}

void Fase::criarAberracoesEspaciais(){
    AberracaoEspacial* pAB = NULL;

    pAB = new AberracaoEspacial(1,1);
    if(pAB){
        entidades->adiciona(static_cast<Entidade*>(pAB));
        GC.incluirInim(static_cast<Inimigo*>(pAB));
    }
    else
        cout<< "Fase::criarAberracoesEspaciais() -> Erro na alocacao dinamica" << endl;

}

void Fase::criarPlasmas() {
    Plasma* pPla = NULL;

    pPla = new Plasma(0,0);

    if(pPla){
        entidades->adiciona(static_cast<Entidade*>(pPla));
        GC.incluirPlas(pPla);
        AberracaoEspacial::setPPlasma(pPla);
    }
    else
        cout<< "Fase::criarAberracoesEspaciais() -> Erro na alocacao dinamica" << endl;


}

void Fase::setJogador(Jogador *pJ)
{
    if (pJ) {
        pJ->posicionar(
            PLATAFORMA_LARGURA + 10.0f,
            ALTURA - (TAM_JOGADOR + ALT_PLATAFORMA + 1.0f)
        );
        pJ->setModificadorGravidade(gravidade);
        
        GC.setPJog1(pJ);
        GE.setPJog(pJ);
        entidades->adiciona(static_cast<Entidade*>(pJ));
        ViajanteMau::setPJog(pJ);
        AberracaoEspacial::setPJog(pJ);
    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
