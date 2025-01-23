#include "Lua.hpp"

Lua::Lua() : Fase(),
maxViajantesMaus(0)
{
    criarObstaculos();
}

Lua::~Lua()
{
}

void Fases::Lua::criarObstaculos() {
    criarPortais();
}

void Fases::Lua::criarPortais() {
    Portal* pP = NULL;
    pP = new Portal(300.0f, 200.0f);
    if (pP) {
        entidades->adiciona(static_cast<Entidade*>(pP));
        GC.incluirObst(static_cast<Obstaculo*>(pP));
    }
}

void Fases::Lua::criarAlienigenas() {
    Alienigena* pA = NULL;
    const int max = 2;

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
