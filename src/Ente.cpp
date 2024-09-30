#include "Ente.hpp"

// Gerenciadores::Gerenciador_Grafico* Ente::pGG = NULL;
// Gerenciadores::Gerenciador_Eventos* Ente::pGE = NULL;

int Ente::cont_Ente = 0;

Ente::Ente(sf::Vector2f vP) : id(++cont_Ente), vPosicao(vP)
{  
    // vPosicao = vP
}

Ente::Ente() : id(++cont_Ente)

{  
}

Ente::~Ente()
{
}


void Ente::desenhar()
{
}

void Ente::mover(const sf::Vector2f vMove)
{
    vPosicao = sf::Vector2f(vPosicao.x + vMove.x, vPosicao.y + vMove.y);
}

void Ente::setPos(const sf::Vector2f vPos)
{
    vPosicao = vPos;
}

