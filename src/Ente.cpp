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


void Ente::desenhar() {
    // Completo requisito de operador this e rel. bidirecional
    pGG->desenharEnte(this);
}

FloatRect Ente::getLimites() const{

    if(!figura){
        cout << "Ente::getLimites() -> ponteir figura nulo" << endl;
        return FloatRect();
    }

    return figura->getLimites();

}

