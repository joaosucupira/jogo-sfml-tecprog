
#include "Jupiter.hpp"

Jupiter::Jupiter() : Fase(),
maxAberracoesEspaciais(0)
{
    criarObstaculos();
}

Fases::Jupiter::~Jupiter()
{
}

void Fases::Jupiter::criarObstaculos() {
    criarPortais();
    criarBuracosNegros();
}

void Fases::Jupiter::criarPortais() {
    Portal* pP = NULL;
    pP = new Portal(700.0f, 200.0f);
    if (pP) {
        entidades->adiciona(static_cast<Entidade*>(pP));
        GC.incluirObst(static_cast<Obstaculo*>(pP));
    }
}

void Fases::Jupiter::criarBuracosNegros(){
    BuracoNegro* pB = NULL;
    pB = new BuracoNegro(900.0f, 350.0f);
    if (pB) {
        entidades->adiciona(static_cast<Entidade*>(pB));
        GC.incluirObst(static_cast<Obstaculo*>(pB));
    }
}

void Fases::Jupiter::criarAlienigenas() {
    Alienigena* pA = NULL;
    const int max = 4;

    for (int i = 0; i < max; i++) {
        pA = new Alienigena(
            LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - i * 500.0f,
            ALTURA - (TAM_JOGADOR + ALT_PLATAFORMA)
        );

        entidades->adiciona(static_cast<Entidade*>(pA));
        GC.incluirInim(static_cast<Inimigo*>(pA));
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}
