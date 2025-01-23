#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

Entidade::Entidade(float x_inicial, float y_inicial) :
Ente(),
sentidos(NULL),
x(x_inicial),
y(y_inicial)
{
}

Entidade::~Entidade() {
    sentidos = NULL;
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

void Entidades::Entidade::posicionar(const float x, const float y) {
    setXY(x, y);
    setPosicaoFigura(x, y);
}

void Entidade::setTamanhoFigura(const float tX, const float tY) { //em Ente faz mais sentido
    figura->setTamanho(tX, tY);
}

void Entidades::Entidade::setCorFigura(const Color &cor) { //em Ente faz mais sentido
    figura->setCor(cor);
}

void Entidades::Entidade::exibirHitbox(FloatRect &lim) {
    // 10/1 - Verificando o que pode estar comprometendo detecção de colisões

    RectangleShape hitbox;

    hitbox.setPosition(lim.left, lim.top);
    hitbox.setSize(sf::Vector2f(lim.width, lim.height));
    hitbox.setFillColor(sf::Color::Transparent); // Sem preenchimento
    hitbox.setOutlineColor(sf::Color::Red);      // Cor da borda
    hitbox.setOutlineThickness(1.0f); 

    pGG->getPJanela()->draw(hitbox);
}

void Entidades::Entidade::verificarSentido(Entidade *pE) {
    if (!pE) {
        cout << "void Entidades::Entidade::verificarSentido(Entidade *pE) -> ponteiro nulo" << endl;
        return;
    }
    
    FloatRect lim1 = this->getLimites();
    FloatRect lim2 = pE->getLimites();

    Vector2f pos1(lim1.left, lim1.top);
    Vector2f pos2(lim2.left, lim2.top);

    Vector2f res = pos1 - pos2;

    for (int i = 0; i < 4; i++) {
        sentidos[i] = 0;
    }
    const int margem = 10;

    // Verificação do sentido de colisão mais relevante
    if (std::abs(res.x) > std::abs(res.y)) {
        if (res.x > margem) {
            sentidos[0] = 1; // Esquerda
        } else if (res.x < -margem) {
        // } else {
            sentidos[1] = 1; // Direita
        }
    }

    else {
        if (res.y > margem) {
            sentidos[3] = 1; // Baixo
        } else {
            sentidos[2] = 1; // Cima
        }
    } 

}

void Entidades::Entidade::setSentidos(int *s) {
    if (s) {
        sentidos = s;
    }
}
