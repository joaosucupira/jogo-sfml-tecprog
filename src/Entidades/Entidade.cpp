#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade()
{
    corpo = sf::Vector2f(0.0f, 0.0f);
    velocidade = sf::Vector2f(0.0f, 0.0f);
}

Entidade::~Entidade()
{
}


/* Métodos set e get*/
void Entidade::setPosicao(sf::Vector2f vMudaP) {
    Ente::setPos(vMudaP);
}

void Entidades::Entidade::setCorpo(sf::Vector2f vMudaC)
{
    corpo = vMudaC;
}

void Entidade::setVelocidade(sf::Vector2f vMudaV) {
    velocidade = vMudaV;
}