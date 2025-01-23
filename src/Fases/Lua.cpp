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
