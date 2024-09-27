#include "Personagem.hpp"

Personagem::Personagem(float x0, float y0, const char* pathTextura) :
    x(x0), y(y0), corpo(sf::Vector2f(200.f, 200.f))
{
    tex = new sf::Texture();
    tex->loadFromFile(pathTextura);
}

Personagem::~Personagem()
{
}

void Personagem::atualizar()
{
    x += 0.8;
    y += 0.6;
    corpo.setPosition(sf::Vector2f(x,y));
}

void Personagem::desenhar(sf::RenderWindow *janela)
{
    corpo.setTexture(tex);
    janela->draw(corpo);
}

