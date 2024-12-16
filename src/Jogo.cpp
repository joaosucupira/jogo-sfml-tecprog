#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GC(),
GE(),
jog1((LARGURA - 100.0f) / 2, (ALTURA + 100.0f) / 2)
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
}

void Jogo::distribuir() {
    
    pGG->setGE(&GE);
    pGG->setGC(&GC);

    pGG->incluiEnte(static_cast<Ente*>(&jog1));
    GE.setPJog(&jog1);
    GC.setPJogador(&jog1);
}

void Jogo::executar()
{
    pGG->executar();
}
