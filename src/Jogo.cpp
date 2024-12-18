#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GC(),
GE(),
jog1((LARGURA - TAM_JOGADOR)/2, (ALTURA + TAM_JOGADOR ) / 2),
plat1(0.0f, ALTURA + ALT_PLATAFORMA)
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
}

void Jogo::distribuir() {
    

    pGG->setGE(&GE);
    pGG->setGC(&GC);

    // pGG->incluiEnte(static_cast<Ente*>(&plat1));
    pGG->incluiEnte(static_cast<Ente*>(&jog1), 0);
    pGG->incluiEnte(static_cast<Ente*>(&plat1), 1);

    GE.setPJog(&jog1);
    GC.setPJog1(&jog1);
    GC.incluirObst(static_cast<Obstaculo*>(&plat1));    
}

void Jogo::executar()
{
    pGG->executar();
}
