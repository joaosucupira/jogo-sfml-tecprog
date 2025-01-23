#include "Fase.hpp"

using namespace Fases;

Fase::Fase() :
gravidade(1.0),
GE(),
GC()
// entidades()
{
    entidades = new ListaEntidades();
    entidades->excluiTodos();
    criarPlataformas();
    
}

Fase::~Fase() {
    entidades->excluiTodos();
    if (entidades) delete entidades;
    entidades = NULL; 
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

    gerenciarColisoes();

    gerenciarEventos();

    renderizarEntidades();


}

void Fase::criarPlataformas() {
    for (int i = 0; i < 2; i++) {
        construirPlano(16, Vector2f(0.0f, ALTURA - (LARG_PLATAFORMA) * i));
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


void Fase::setJogador(Jogador *pJ)
{
    if (pJ) {
        pJ->posicionar(
            PLATAFORMA_LARGURA + 10.0f,
            ALTURA - (TAM_JOGADOR + ALT_PLATAFORMA + 1.0f)
        );
        // pJ->posicionar(100.0f, 100.0f);
        GC.setPJog1(pJ);
        GE.setPJog(pJ);
        entidades->adiciona(static_cast<Entidade*>(pJ));

    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
