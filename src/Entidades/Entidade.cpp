#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade(int dx, int dy) :
Ente()
{
    // setPos(Vector2f((float)dx, (float)dy));
}

Entidade::~Entidade() {
}


/* Métodos set e get*/
// void Entidade::setPosicao(sf::Vector2f vMudaP) {
//     Ente::setPos(vMudaP);
// }

// void Entidades::Entidade::setCorpo(sf::Vector2f vMudaC)
// {
//     corpo = vMudaC;
// }

// void Entidade::setVelocidade(sf::Vector2f vMudaV) {
//     velocidade = vMudaV;
// }