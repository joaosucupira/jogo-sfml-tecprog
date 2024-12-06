#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade(int dx, int dy) :
Ente(),
x(dx),
y(dy)
{
    setPosicao(static_cast<float>(dx), static_cast<float>(dy));
    setTamanho(100.0f, 100.0f);
    setCor(Color::Yellow);
}

Entidade::~Entidade() {
}

void Entidade::setPosicao(const float x, const float y) {
    corpo->setPosition(x, y);
}

void Entidade::setTamanho(const float x, const float y) {
    Vector2f tamanho(x, y);
    corpo->setSize(tamanho);
}

void Entidades::Entidade::setCor(const Color &cor) {
    corpo->setFillColor(cor);
}

void Entidade::setVelocidade(const float x, const float y) {
    velocidade = Vector2f(x,y);
}


