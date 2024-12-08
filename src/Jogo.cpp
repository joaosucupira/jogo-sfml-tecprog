#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GC(),
GE(),
janela()
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
}

void Jogo::distribuir() {
    distribuirJanela();
}

void Jogo::distribuirJanela()
{
    pGG->setJanela(&janela);
    GE.setJanela(&janela);

    pGG->setGE(&GE);
    pGG->setGC(&GC);

    pGG->incluiEnte(static_cast<Ente*>(GC.getJogador()));
    GE.setPJog(GC.getJogador());

}

void Jogo::executar()
{
    pGG->executar();
}
