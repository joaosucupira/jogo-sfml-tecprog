#include "Fase.hpp"

using namespace Fases;

Fase::Fase() :
pJog1(NULL),
pJog2(NULL),
ativa(false),
GE(),
GC()

{
    srand(time(NULL));
    entidades = new ListaEntidades();
    entidades->excluiTodos();
    criarCenario();
    
}

Fase::~Fase() {
    pJog1 = NULL;
    pJog2 = NULL;
    entidades->excluiTodos();
    if (entidades) delete entidades;
    entidades = NULL; 
    ativa = false;
}

void Fase::renderizarEntidades()
{
    if (entidades->vazia()) {
        cout << "void Fase::renderizarEntidades() -> Lista vazia." << endl;
        return;
    }
    int tamanho = (*entidades).getTamanho();

    Entidade* pE = NULL;
    for (int i = 0; i < tamanho; i++) {
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

void Fases::Fase::atualizaPerseguido() {
    if (!pJog1->getVivo() && pJog2->getVivo()) {
        AberracaoEspacial::setPJog(pJog2);
        ViajanteMau::setPJog(pJog2);
    }
}

void Fases::Fase::configurarPerseguido() {
    ViajanteMau::setPJog(pJog1);
    AberracaoEspacial::setPJog(pJog1);

}

void Fase::executar() {
    ativa = true;

    desenhar();

    gerenciarColisoes();

    gerenciarEventos();

    renderizarEntidades();

    atualizaPerseguido();
}

void Fase::criarPlataformas() {
    
    // chao e teto
    Vector2f inicio(0.0f, ALTURA - ALT_PLATAFORMA);
    construirPlano(LARGURA, inicio);

    Vector2f inicio6(0.0f, -ALT_PLATAFORMA);
    construirPlano(LARGURA, inicio6);

    
    // paredes
    Vector2f inicio2(0.0f - LARG_PLATAFORMA / 2.0f, 0.0f);
    construirParede(ALTURA, inicio2);

    Vector2f inicio3(LARGURA - LARG_PLATAFORMA / 2.0f, 0.0f);
    construirParede(ALTURA, inicio3);


}


void Fases::Fase::construirPlano(const float tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;


    pP = new Plataforma(inicio.x , inicio.y);
    pP->setTamanhoFigura(tamanho, ALT_PLATAFORMA);
    entidades->adiciona(static_cast<Entidade*>(pP));
    GC.incluirObst(static_cast<Obstaculo*>(pP));
    pP = NULL;


    if (pP) delete pP;
    pP = NULL;
}
void Fases::Fase::construirParede(const float tamanho, Vector2f inicio) {
    Plataforma* pP = NULL;


    pP = new Plataforma(inicio.x , inicio.y);
    pP->setTamanhoFigura(LARG_PLATAFORMA, tamanho);
    entidades->adiciona(static_cast<Entidade*>(pP));
    GC.incluirObst(static_cast<Obstaculo*>(pP));
    pP = NULL;


    if (pP) delete pP;
    pP = NULL;
}

void Fases::Fase::criarCenario() {
    criarPlataformas();
}

void Fase::setJogador(Jogador *pJ, const int num_jogador)
{
    if (pJ) {
        if (num_jogador == 1) {
            pJog1 = pJ;
        } else {
            pJog2 = pJ;
        }
        
    } else { cout << "void Fase::setJogador(Jogador *pJ) -> ponteiro nulo." << endl; }
}

void Fase::configurarJogador(const int num_jogador) {

    Jogador* pJog = NULL;
    if (num_jogador == 1) {
        if (!pJog1) {
            cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 1 nao configurado" << endl;
            return;
        }
        pJog = pJog1;

    } else {
        if(!pJog2) {
            cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 2 nao configurado" << endl;
            return;
        }
        pJog = pJog2;
    }



    // pJog->setModificadorGravidade(gravidade);
    
    if (num_jogador == 1) {
        GC.setPJog1(pJog);
    } else {
        GC.setPJog2(pJog);
    }

    GE.setPJog(pJog);

    if (num_jogador == 1) {
        pJog->posicionar(LARG_PLATAFORMA * 4, ALTURA - (LARG_PLATAFORMA * 2));
    } else {
        pJog->posicionar(LARG_PLATAFORMA * 5, ALTURA - (LARG_PLATAFORMA * 2));
    }

    entidades->adiciona(static_cast<Entidade*>(pJog));
    configurarPerseguido();
    
}
