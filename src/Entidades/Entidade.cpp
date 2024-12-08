#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade(float dx, float dy) :
Ente(),
x(dx),
y(dy)
{
    setPosicaoCorpo(static_cast<float>(dx), static_cast<float>(dy));
    setTamanho(100.0f, 100.0f);
    setCor(Color::Yellow);
}

Entidade::~Entidade() {
}

void Entidade::setPosicaoCorpo(const float x, const float y) {
    if (corpo) {
        corpo->setPosition(x, y);
    } cout << "Entidade::setPosicaoCorpo(const float x, const float y) -> ponteiro nulo." << endl;
}

void Entidade::setXY(const float novoX, const float novoY){
    x = novoX;
    y = novoY;
}

void Entidade::setTamanho(const float x, const float y) {
    Vector2f tamanho(x, y);
    if (corpo) {
        corpo->setSize(tamanho);
    } else { cout << "Entidade::setTamanho(const float x, const float y) -> ponteiro nulo." << endl; }
}

void Entidade::setCor(const Color &cor) {
    if (corpo) {
        corpo->setFillColor(cor);
    } else { cout << "Entidade::setCor(const Color &cor) -> ponteiro nulo." << endl; }
}



