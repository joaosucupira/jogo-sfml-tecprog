#include "Ente.hpp"

int Ente::cont_id(0);
GerenciadorGrafico* Ente::pGG = GerenciadorGrafico::getInstancia();

/* Construtoras/Destrutoras */

Ente::Ente() :
id(cont_id++),
figura(NULL)
{
    setGGrafico();
}

Ente::~Ente()
{
    if (figura != NULL) {
        delete figura;
    }
    figura = NULL;
}

/* Métodos principais */

// Gambiarra
void Ente::desenhar() {
    //pGG->getPJanela()->draw(*corpo);
    pGG->getPJanela()->draw(figura->getSprite());

}

FloatRect Ente::getLimites() const{

    if(!figura){
        cout << "Ente::getLimites() -> ponteir figura nulo" << endl;
        return FloatRect();
    }

    return figura->getLimites();

}

