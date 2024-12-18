#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade(float x_inicial, float y_inicial) :
Ente(),
x(x_inicial),
y(y_inicial)
{
}

Entidade::~Entidade() {
}

void Entidade::setPosicaoFigura(const float x, const float y) {

    if (figura) 
        figura->setPosicao(x, y);
    else 
        cout << "Entidade::setPosicaoFigura(const float x, const float y) -> ponteiro figura nulo!" << endl;
}

void Entidade::setXY(const float novoX, const float novoY){
    x = novoX;
    y = novoY;
}

void Entidade::setTamanhoFigura(const float tX, const float tY) { //em Ente faz mais sentido
    figura->setTamanho(tX, tY);
}

void Entidades::Entidade::setCorFigura(const Color &cor) { //em Ente faz mais sentido
    figura->setCor(cor);
}




