#include "Jogo.hpp"
GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GE()
{
    GE.setWindow(&(pGG->getJanela()));
    GE.executar();
}

Jogo::~Jogo()
{
}