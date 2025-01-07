#include "Fase.hpp"

using namespace Fases;

Fase::Fase() :
GE(),
GC()
// entidades()
{
    entidades = new ListaEntidades();
    entidades->excluiTodos();
    criarPlataformas();
    criarAlienigenas();
}

Fase::~Fase() {
    entidades->excluiTodos();
    if (entidades) delete entidades;
    entidades = NULL; 
}

void Fase::renderizarEntidades() {
    if (entidades->vazia()) {
        cout << "void Fase::renderizarEntidades() -> Lista vazia." << endl;
        return;
    }

    for (int i = 0; i < (*entidades).getTamanho(); i++) {
        (*entidades)[i]->executar();
        pGG->desenharEnte((*entidades)[i]); // isso vai mudar
    }
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
    Plataforma* pP = NULL;
    const int max = 1;

    for (int i = 0; i < max; i++) {
        pP = new Plataforma(0.0f, ALTURA - ALT_PLATAFORMA);
        entidades->adiciona(pP);
        GC.incluirObst(pP);
        pP = NULL;
    }
    if (pP) delete pP;
    pP = NULL;
}

void Fases::Fase::criarAlienigenas() {
    Alienigena* pA = NULL;
    const int max = 1;

    for (int i = 0; i < max; i++) {
        pA = new Alienigena((LARGURA - TAM_JOGADOR)/2.5, (ALTURA + TAM_JOGADOR ) / 2);
        entidades->adiciona(pA);
        GC.incluirInim(pA);
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Fase::setJogador(Jogador *pJ) {
    if (pJ) {
        // Pensando pensamentos sobre isso
        GC.setPJog1(pJ);
        GE.setPJog(pJ);
        entidades->adiciona(static_cast<Entidade*>(pJ));

    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
