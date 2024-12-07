#include "Personagem.hpp"

Personagem::Personagem(const float x,  const float y) :
Entidade(x,y),
num_vidas(1),
velocidade(0.0,0.0),
estaPulando(false)
{
}

Personagem::~Personagem() {
    num_vidas = -1;
}

void Personagem::mover(){

    x += velocidade.x *  PIXEL_METRO * deltaTime;
    y += velocidade.y *  PIXEL_METRO * deltaTime;

    setPosicaoCorpo(x,y);
    cout << "dt = " << deltaTime << endl;
    
}

void Personagem::aplicarGravidade(){

    if(estaPulando)
        velocidade.y += GRAVIDADE * deltaTime;
}


/*
void Personagem::mover(const int direcaoX, const int direcaoY) {
    if (vivo) {
        float x = direcaoX * velocidade.x;
        float y = direcaoY * velocidade.y; 
        corpo->move(x, y);
    }
}*/