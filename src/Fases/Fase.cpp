#include "Fase.hpp"

using namespace Fases;

Fase::Fase() :
GC(),
entidades()
{
    criarPlataformas();
    criarAlienigenas();
}

Fase::~Fase()
{
}

void Fase::gerenciarColisoes()
{
}

void Fase::executar() {    
    GC.executar();

    for (int i = 0; i < entidades.getTamanho(); i++) {
        entidades[i]->executar();
        pGG->desenharEnte(entidades[i]);
    }

}

void Fase::criarPlataformas() {
    Plataforma* pP = NULL;
    const int max = 1;

    for (int i = 0; i < max; i++) {
        pP = new Plataforma(0.0f, ALTURA - ALT_PLATAFORMA);
        entidades.adiciona(pP);
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
        entidades.adiciona(pA);
        GC.incluirInim(pA);
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Fase::setJogador(Jogador *pJ) {
    if (pJ) {
        GC.setPJog1(pJ);
    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
