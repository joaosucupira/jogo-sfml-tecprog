#include "Ente.hpp"

/* Construtoras/Destrutoras */
Ente::Ente(ID::ids idEnte, sf::Vector2f vP) : id(idEnte), vPosicao(vP)
{ 
    // Instanciar novo objeto animador
}

Ente::Ente()
{  
    this->id = ID::empty;
    // Aterrar ponteiro para sprite
}

Ente::~Ente()
{
    // deletar ponteiro para sprite
}


/* Métodos base */

void Ente::carregar()
{
    // carregar sprite
}

void Ente::moverSprite(const sf::Vector2f vMove)
{
    vPosicao = sf::Vector2f(vPosicao.x + vMove.x, vPosicao.y + vMove.y);
}

/* Métodos set e get */
void Ente::setPos(const sf::Vector2f vPos)
{
    vPosicao = vPos;
}

