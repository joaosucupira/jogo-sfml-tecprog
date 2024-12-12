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
    corpo->setPosition(x, y);
    if (figura) figura->getSprite()->setPosition(x, y);
    else cout << "Entidade::setPosicaoCorpo(const float x, const float y) -> ponteiro nulo!" << endl;
}

void Entidade::setXY(const float novoX, const float novoY){
    x = novoX;
    y = novoY;
}

void Entidade::ajustarSprite() {
    Vector2f tamanho = corpo->getSize();
    if (figura && figura->getSprite() && figura->getSprite()->getTexture()) {
        Vector2u tamanhoTex = figura->getSprite()->getTexture()->getSize();

        figura->getSprite()->setScale(
            tamanho.x / tamanhoTex.x,
            tamanho.y / tamanhoTex.y
        );
        // ficou pequeno, testando antes de tentar fazer ser automatico
        figura->getSprite()->setScale(10.0f, 10.0f);

    } else { cout << "void Entidade::ajustarSprite() -> ponteiro nulo / textura nao carregada" << endl; }
}

void Entidade::setTamanho(const float x, const float y) {
    Vector2f tamanho(x, y);
    corpo->setSize(tamanho);
}

void Entidades::Entidade::setCor(const Color &cor) {
    corpo->setFillColor(cor);
}



