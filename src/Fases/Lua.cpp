#include "Lua.hpp"

Lua::Lua() : Fase(),
maxViajantesMaus(0)
{
    gravidade = 0.65f;
    figura = new Figura(
        1309, 736, 
        1, 1, 
        0, 0,
        0, 0
    );
    carregarFigura();
    criarObstaculos();
    criarAlienigenas();
    criarViajantesMaus();
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
    const int max = 1;
    cout << max << endl;

    for (int i = 1; i < max + 1; i++) {
        pA = new Alienigena(
            LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - i * 200.0f,
            ALTURA - (TAM_JOGADOR + ALT_PLATAFORMA)
        );

        entidades->adiciona(static_cast<Entidade*>(pA));
        GC.incluirInim(static_cast<Inimigo*>(pA));
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Lua::criarViajantesMaus(){
    ViajanteMau* pVM = NULL;
    pVM = new ViajanteMau(LARGURA-TAM_JOGADOR,0);
    if(pVM){
        entidades->adiciona(static_cast<Entidade*>(pVM));
        GC.incluirInim(static_cast<Inimigo*>(pVM));
    }
    else
        cout<< "Fase::criarViajantesMaus() -> Erro na alocacao dinamica" << endl;
}


void Fases::Lua::carregarFigura() {
    if (!figura) {
        cout << "void Fases::Lua::carregarFigura() -> ponteiro nulo" << endl;
        return;
    }

    figura->carregarTextura(LUA_PATH);

}
