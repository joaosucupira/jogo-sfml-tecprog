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

// void Fase::posicionarEntidade(Entidade *pE, const float x, const float y) {
//     if (!pE) {
//         cout << "void Fase::posicionarEntidade(Entidade *pE) -> ponteiro nulo" << endl;
//         return;
//     }
//     // Por alguma razao a entidade soh eh movida se os dois metodos forem chamados
//     pE->setXY(x, y);
//     pE->setPosicaoFigura(x, y);
// }

void Fase::renderizarEntidades()
{
    if (entidades->vazia()) {
        cout << "void Fase::renderizarEntidades() -> Lista vazia." << endl;
        return;
    }

    for (int i = 0; i < (*entidades).getTamanho(); i++) {
        (*entidades)[i]->executar();
        // pGG->desenharEnte((*entidades)[i]); // isso vai mudar
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

    construirPlano(52, Vector2f(0.0f, ALTURA - PLATAFORMA_ALTURA));

    construirPlano(10, Vector2f(300.0f, ALTURA - 300.0f));

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

void Fases::Fase::criarAlienigenas() {
    Alienigena* pA = NULL;
    const int max = 0;

    for (int i = 0; i < max; i++) {
        pA = new Alienigena((LARGURA - TAM_JOGADOR) / 2, 1);
        entidades->adiciona(pA);
        GC.incluirInim(pA);
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Fase::setJogador(Jogador *pJ) {
    if (pJ) {
        pJ->posicionar(0.0f, 0.0f);
        GC.setPJog1(pJ);
        GE.setPJog(pJ);
        entidades->adiciona(static_cast<Entidade*>(pJ));

    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}
