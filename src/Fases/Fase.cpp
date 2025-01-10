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
    // chao
    for (int i = 0; i < 2; i++) {
        construirPlano(20, Vector2f(0.0f, ALTURA - PLATAFORMA_ALTURA * i));
    }
    // teto
    for (int i = 0; i < 1; i++) {
        construirPlano(20, Vector2f(0.0f, 0.0f));
    }
    // parede esquerda
    for (int i = 0; i < 20; i ++) {
        construirPlano(1, Vector2f(0.0f, ALTURA - PLATAFORMA_ALTURA * i));
    }
    // parede direita
    for (int i = 0; i < 20; i ++) {
        construirPlano(1, Vector2f(LARGURA - PLATAFORMA_LARGURA, ALTURA - PLATAFORMA_ALTURA * i));
    }

    for (int i = 0; i < 1; i++) {
        construirPlano(3, Vector2f(
                300.f,
                300.0f
            )
        );
    }
    for (int i = 0; i < 1; i++) {
        construirPlano(3, Vector2f(
                400.f,
                400.0f
            )
        );
    }




    // for (int i = 6; i < 7; i++)
    //     construirPlano(2, Vector2f(150.0f, ALTURA - PLATAFORMA_ALTURA * i));

    // for (int i = 0; i < 15; i++)
    //     construirPlano(1, Vector2f(750.0f, ALTURA - PLATAFORMA_ALTURA * i));

    

}

void Fases::Fase::construirPlano(const int tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;

    for (int i = 0; i < tamanho; i++) {
        pP = new Plataforma(i * PLATAFORMA_LARGURA + inicio.x, inicio.y);
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
    Alienigena* pA = NULL;
    const int max = 1;

    for (int i = 0; i < max; i++) {
        pA = new Alienigena((LARGURA - TAM_JOGADOR) / 2, (ALTURA - TAM_JOGADOR) / 2);
        entidades->adiciona(pA);
        GC.incluirInim(pA);
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Fase::setJogador(Jogador *pJ) {
    if (pJ) {
        pJ->posicionar((ALTURA - TAM_JOGADOR) / 2, ALTURA - 4 * (ALT_PLATAFORMA + TAM_JOGADOR));
        GC.setPJog1(pJ);
        GE.setPJog(pJ);
        entidades->adiciona(static_cast<Entidade*>(pJ));

    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
