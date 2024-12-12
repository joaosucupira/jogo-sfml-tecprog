#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GC(),
GE()
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
}

void Jogo::distribuir() {
    
    pGG->setGE(&GE);
    pGG->setGC(&GC);

    pGG->incluiEnte(static_cast<Ente*>(GC.getJogador()));
    GE.setPJog(GC.getJogador());
}

void Jogo::executar()
{
    pGG->executar();
}
