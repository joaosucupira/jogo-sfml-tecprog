#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade(float dx, float dy) :
Ente(),
x(dx),
y(dy)
{
    //setPosicaoFigura(dx, dy);
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

void Entidade::setTamanhoFigura(const float tX, const float tY) {
    figura->setTamanho(tX, tY);
}

void Entidades::Entidade::setCorFigura(const Color &cor) {
    figura->setCor(cor);
}




