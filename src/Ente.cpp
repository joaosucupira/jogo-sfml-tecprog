#include "Ente.hpp"
int Ente::cont_id(1);
GerenciadorGrafico* Ente::pGG = NULL;

/* Construtoras/Destrutoras */


Ente::Ente(const float x, const float y, const float largura, const float altura) :
id(cont_id++),
posicao_inicial(x, y),
corpo(NULL)
{
    corpo = new RectangleShape(Vector2f(largura, altura));
    setGGrafico();
}


Ente::~Ente() {
    if (corpo != NULL) {
        delete corpo;
    }
    corpo = NULL;
}

/* Métodos base */

void Ente::moverSprite(const sf::Vector2f vMove) {
    posicao_inicial = sf::Vector2f(
        posicao_inicial.x + vMove.x, 
        posicao_inicial.y + vMove.y
    );
}

void Ente::desenhar() {
    pGG->desenharEnte(this);
}

/* Métodos set e get */
void Ente::setPos(const sf::Vector2f posicao)
{
    posicao_inicial = posicao;
}

