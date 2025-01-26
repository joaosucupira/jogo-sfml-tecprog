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
    const float largura_plataforma = LARGURA / 5.0f;
    
    // planos
    Vector2f inicio(0.0f, ALTURA - ALT_PLATAFORMA);
    construirPlano(LARGURA, inicio);

    Vector2f inicio6(0.0f, -ALT_PLATAFORMA);
    construirPlano(LARGURA, inicio6);

    // Vector2f inicio4( LARG_PLATAFORMA * 0, ALTURA - ALT_PLATAFORMA * 5);
    // construirPlano( largura_plataforma, inicio4);

    // Vector2f inicio5(LARGURA - (LARG_PLATAFORMA * 0 + largura_plataforma), ALTURA - ALT_PLATAFORMA * 5);
    // construirPlano( largura_plataforma, inicio5);
    
    // paredes
    Vector2f inicio2(0.0f - LARG_PLATAFORMA / 2.0f, 0.0f);
    construirParede(ALTURA, inicio2);

    Vector2f inicio3(LARGURA - LARG_PLATAFORMA / 2.0f, 0.0f);
    construirParede(ALTURA, inicio3);


}


void Fases::Fase::construirPlano(const float tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;


    pP = new Plataforma(inicio.x , inicio.y);
    pP->setTamanhoFigura(tamanho, ALT_PLATAFORMA);
    entidades->adiciona(static_cast<Entidade*>(pP));
    GC.incluirObst(static_cast<Obstaculo*>(pP));
    pP = NULL;


    if (pP) delete pP;
    pP = NULL;
}
void Fases::Fase::construirParede(const float tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;


    pP = new Plataforma(inicio.x , inicio.y);
    pP->setTamanhoFigura(LARG_PLATAFORMA, tamanho);
    entidades->adiciona(static_cast<Entidade*>(pP));
    GC.incluirObst(static_cast<Obstaculo*>(pP));
    pP = NULL;


    if (pP) delete pP;
    pP = NULL;
}

void Fases::Fase::criarCenario() {

    criarPlataformas();
}

void Fase::setJogador(Jogador *pJ)
{
    if (pJ) {
        // pJ->posicionar(
        //     PLATAFORMA_LARGURA + 100.0f,
        //     ALTURA - (TAM_JOGADOR + ALT_PLATAFORMA + 100.0f)
        // );
        pJ->posicionar(100.0f, 100.0f);
        pJ->setModificadorGravidade(gravidade);
        
        GC.setPJog1(pJ);
        GE.setPJog(pJ);
        entidades->adiciona(static_cast<Entidade*>(pJ));
        ViajanteMau::setPJog(pJ);
        AberracaoEspacial::setPJog(pJ);
    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
