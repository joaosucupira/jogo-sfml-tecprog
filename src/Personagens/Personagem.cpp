#include "Personagem.hpp"

Personagem::Personagem(const int x,  const int y) :
Entidade(x,y),
num_vidas(1),
velocidade(0.0,0.0),
estaPulando(false)
{
}

Personagem::~Personagem() {
    num_vidas = -1;
}

void Personagem::aplicarVelocidade(){

    x += velocidade.x * (*pDeltaTime) * PIXEL_METRO;
    y += velocidade.y * (*pDeltaTime) * PIXEL_METRO;

    moverSprite(Vector2f(x,y));
}

void Personagem::aplicarGravidade(){

    if(estaPulando)
        velocidade.y += GRAVIDADE * (*pDeltaTime);
}

void Personagem::mover(const int direcaoX, const int direcaoY) {
    if (vivo) {
        float x = direcaoX * velocidade.x;
        float y = direcaoY * velocidade.y; 
        corpo->move(x, y);
    }
}