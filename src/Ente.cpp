#include "Ente.hpp"


int Ente::cont_id(0);
GerenciadorGrafico* Ente::pGG = GerenciadorGrafico::getInstancia();

/* Construtoras/Destrutoras */

Ente::Ente() :
id(cont_id++),
corpo(new RectangleShape()),
deltaTime(0.0)
{
    setGGrafico();
}

Ente::~Ente()
{
    if (corpo != NULL) {
        delete corpo;
    }
    corpo = NULL;
}

/* Métodos base */

void Ente::desenhar() {
    pGG->getRenderWindow()->draw(*corpo);
    
}

void Ente::setCorpo(RectangleShape *pC) {
    if (pC) {
        corpo = pC;
    } else { cout << "Ente::setCorpo(RectangleShape *pC) -> ponteiro nulo." << endl; }
}

void Ente::moverSprite(Vector2f vMove) {
//     // posicao_inicial = sf::Vector2f(
//     //     posicao_inicial.x + vMove.x, 
//     //     posicao_inicial.y + vMove.y
//     // );
    corpo->move(vMove);
}


// /* Métodos set e get */
// void Ente::setPos(const sf::Vector2f posicao)
// {
//     posicao_inicial = posicao;
// }

