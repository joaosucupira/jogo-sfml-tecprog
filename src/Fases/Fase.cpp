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


void Fase::renderizarEntidades()
{
    if (entidades->vazia()) {
        cout << "void Fase::renderizarEntidades() -> Lista vazia." << endl;
        return;
    }

    for (int i = 0; i < (*entidades).getTamanho(); i++) {
        (*entidades)[i]->executar();

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

    // // parede esquerda
    // for (int i = 0; i < 20; i ++) {
    //     construirPlano(1, Vector2f(0.0f, ALTURA - PLATAFORMA_ALTURA * i));
    // }
    // // parede direita
    // for (int i = 0; i < 20; i ++) {
    //     construirPlano(1, Vector2f(LARGURA - PLATAFORMA_LARGURA, ALTURA - PLATAFORMA_ALTURA * i));
    // }
    
    for (int i = 0; i < 1; i++) {
        construirPlano(4, Vector2f(
            (LARGURA - AJUSTE_CENTRO) / 2.5f,
            (ALTURA - AJUSTE_CENTRO) / 1.0f

        ));
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
    Alienigena* pA = new Alienigena(
        LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - 500.0f,
        TAM_JOGADOR - 100.0f
    );

    entidades->adiciona(static_cast<Entidade*>(pA));
    GC.incluirInim(static_cast<Inimigo*>(pA));

    // delete pA;
    // pA = NULL;
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
