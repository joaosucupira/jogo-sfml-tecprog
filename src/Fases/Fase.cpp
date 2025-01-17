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
    criarPortais();
    criarBuracosNegros();
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

    Entidade* pE = NULL;
    for (int i = 0; i < (*entidades).getTamanho(); i++) {
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
    criarPlataformasA();

}

void Fases::Fase::criarPlataformasA() {
    // chao
    for (int i = 0; i < 2; i++) {
        construirPlano(5, Vector2f(0.0f, ALTURA - PLATAFORMA_ALTURA * i));
    }
    for (int i = 0; i < 2; i++) {
        construirPlano(5, Vector2f(900.0f, ALTURA - PLATAFORMA_ALTURA * i));
    }
    // teto
    for (int i = 0; i < 1; i++) {
        construirPlano(20, Vector2f(0.0f, 0.0f));
    }

    for (int i = 0; i < 20; i++) {
        construirPlano(1, Vector2f(0.0f, ALTURA - PLATAFORMA_ALTURA * i));
    }
    
    for (int i = 0; i < 1; i++) {
        construirPlano(4, Vector2f(
            (LARGURA - AJUSTE_CENTRO) / 2.5f,
            (ALTURA - AJUSTE_CENTRO) / 1.0f

        ));
    }
}

void Fases::Fase::criarPlataformasB() {
    // chao
    for (int i = 0; i < 2; i++) {
        construirPlano(20, Vector2f(0.0f, ALTURA - PLATAFORMA_ALTURA * i));
    }
}

void Fases::Fase::construirPlano(const int tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;

    for (int i = 0; i < tamanho; i++) {
        pP = new Plataforma(i * (PLATAFORMA_LARGURA) + inicio.x, inicio.y);
        entidades->adiciona(static_cast<Entidade*>(pP));
        GC.incluirObst(static_cast<Obstaculo*>(pP));
        pP = NULL;
    }

    if (pP) delete pP;
    pP = NULL;
}

void Fases::Fase::construirParede(const int tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;

    for (int i = 0; i < tamanho; i++) {
        pP = new Plataforma(inicio.x, i * PLATAFORMA_ALTURA + inicio.y);
        entidades->adiciona(static_cast<Entidade*>(pP));
        GC.incluirObst(static_cast<Obstaculo*>(pP));
        pP = NULL;
    }

    if (pP) delete pP;
    pP = NULL;
}

void Fases::Fase::criarAlienigenas() {
    criarAlienigenasB();
    // criarAlienigenasA();
}

void Fases::Fase::criarAlienigenasA() {
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

void Fases::Fase::criarAlienigenasB() {
    // Alienigena* pA = new Alienigena(
    //     LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - 400.0f,
    //     TAM_JOGADOR - 450.0f
    // );
    Alienigena* pA = new Alienigena(
        450.0f,
        50.0f
    );

    entidades->adiciona(static_cast<Entidade*>(pA));
    GC.incluirInim(static_cast<Inimigo*>(pA));

    // delete pA;
    // pA = NULL;
}

void Fases::Fase::criarPortais() {
    Portal* pP = NULL;
    pP = new Portal(750.0f, 350.0f);
    if (pP) {
        entidades->adiciona(static_cast<Entidade*>(pP));
        GC.incluirObst(static_cast<Obstaculo*>(pP));
    }
}

void Fases::Fase::criarBuracosNegros() {
    BuracoNegro* pB = NULL;
    pB = new BuracoNegro(450.0f, 250.0f);
    if (pB) {
        entidades->adiciona(static_cast<Entidade*>(pB));
        GC.incluirObst(static_cast<Obstaculo*>(pB));
    }
}

void Fase::setJogador(Jogador *pJ)
{
    if (pJ) {
        pJ->posicionar(
            PLATAFORMA_LARGURA + 10.0f,
            ALTURA - (TAM_JOGADOR + ALT_PLATAFORMA + 10.0f)
        );
        // pJ->posicionar(100.0f, 100.0f);
        GC.setPJog1(pJ);
        GE.setPJog(pJ);
        entidades->adiciona(static_cast<Entidade*>(pJ));

    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
