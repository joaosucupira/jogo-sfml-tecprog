#include "Ente.hpp"

int Ente::cont_id(0);
GerenciadorGrafico* Ente::pGG = GerenciadorGrafico::getInstancia();

/* Construtoras/Destrutoras */

Ente::Ente() :
id(cont_id++),
corpo(new RectangleShape()),
figura(new Figura()),
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

    if (figura != NULL) {
        delete figura;
    }
    figura = NULL;
}

/* Métodos principais */

// Gambiarra
void Ente::desenhar() {
    // pGG->getRenderWindow()->draw(*corpo);
    pGG->getPJanela()->draw(*(figura->getSprite()));

}

void Ente::setCorpo(RectangleShape *pC) {
    if (pC) {
        corpo = pC;
    } else { cout << "Ente::setCorpo(RectangleShape *pC) -> ponteiro nulo." << endl; }
}

