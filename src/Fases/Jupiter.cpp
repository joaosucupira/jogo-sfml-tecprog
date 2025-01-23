
#include "Jupiter.hpp"

Jupiter::Jupiter() : Fase(),
maxAberracoesEspaciais(0)
{
    figura = new Figura(
        2819, 1589,
        1,1,
        0,0,
        0,0
    );
    carregarFigura();
    figura->setTamanho(1309, 736);
    criarObstaculos();
    criarAlienigenas();
}

Fases::Jupiter::~Jupiter()
{
}

void Fases::Jupiter::criarObstaculos() {
    criarPilares();
    criarPortais();
    criarBuracosNegros();
}

void Fases::Jupiter::criarPortais() {
    Portal* pP = NULL;

    for (int i = 1; i < 4; i++) {
        pP = new Portal(250.0f * i, ALTURA - ALT_PLATAFORMA * 2 - 150.0f);
        if (pP) {
            if (i == 2) {
                continue;
            }
            else {

                entidades->adiciona(static_cast<Entidade*>(pP));
                GC.incluirObst(static_cast<Obstaculo*>(pP));
            }
        }
        pP = NULL;
    }
    if (pP) delete pP;
    pP = NULL;
}

void Fases::Jupiter::carregarFigura() {
    if (figura) {
        figura->carregarTextura(JUPITER_PATH);
    }
}

void Fases::Jupiter::criarBuracosNegros(){
    BuracoNegro* pB = NULL;

    for (int i = 1; i < 4; i++) {
        pB = new BuracoNegro(215.0f * i, ALTURA - ALT_PLATAFORMA * 2 - 240.0f);
        if (pB) {
            if (i == 2) {
                entidades->adiciona(static_cast<Entidade*>(pB));
                GC.incluirObst(static_cast<Obstaculo*>(pB));
            }

        }
        pB = NULL;
    }
    if (pB) delete pB;
    pB = NULL;
}

void Fases::Jupiter::criarAlienigenas() {
    Alienigena* pA = NULL;
    const int max = 1;

    for (int i = 0; i < max; i++) {
        pA = new Alienigena(
            LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - i * 470.0f,
            10.0f
        );

        entidades->adiciona(static_cast<Entidade*>(pA));
        GC.incluirInim(static_cast<Inimigo*>(pA));
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Fases::Jupiter::criarPilares()
{
    const int max = 5;
    for (int i = 3; i < max + 3; i++) {
        construirPlano(1, Vector2f(150.0f, ALTURA - ALT_PLATAFORMA * i));
        construirPlano(1, Vector2f(400.0f, ALTURA - ALT_PLATAFORMA * i));
        construirPlano(1, Vector2f(650.0f, ALTURA - ALT_PLATAFORMA * i));
        construirPlano(1, Vector2f(900.0f, ALTURA - ALT_PLATAFORMA * i));
        
    }
}
