#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade(float x_inicial, float y_inicial) :
Ente(),
x(x_inicial),
y(y_inicial),
velocidade(0.0,0.0)
{
}

Entidade::~Entidade() {
}

/*void Entidade::setPosicaoFigura(const float x, const float y) {

    if (figura) 
        figura->setPosicao(x, y);
    else 
        cout << "Entidade::setPosicaoFigura(const float x, const float y) -> ponteiro figura nulo!" << endl;
}*/

void Entidade::setXY(const float novoX, const float novoY){
    x = novoX;
    y = novoY;
}

void Entidade::posicionar(const float x, const float y) {
    setXY(x, y);
    setPosicaoFigura(x, y);
}

/*
void Entidade::setTamanhoFigura(const float tX, const float tY) { //em Ente faz mais sentido
    figura->setTamanho(tX, tY);
}

void Entidades::Entidade::setCorFigura(const Color &cor) { //em Ente faz mais sentido
    figura->setCor(cor);
}
*/

void Entidade::exibirHitbox(FloatRect &lim) {
    // 10/1 - Verificando o que pode estar comprometendo detecção de colisões

    RectangleShape hitbox;

    hitbox.setPosition(lim.left, lim.top);
    hitbox.setSize(sf::Vector2f(lim.width, lim.height));
    hitbox.setFillColor(sf::Color::Transparent); // Sem preenchimento
    hitbox.setOutlineColor(sf::Color::Red);      // Cor da borda
    hitbox.setOutlineThickness(1.0f); 

    pGG->getPJanela()->draw(hitbox);
}




