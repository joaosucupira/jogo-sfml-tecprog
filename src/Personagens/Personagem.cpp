#include "Personagem.hpp"

/* Construtoras/Destrutora */
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

/* Métodos principais*/
void Personagem::mover(){
    x += velocidade.x *  PIXEL_METRO * deltaTime;
    y += velocidade.y *  PIXEL_METRO * deltaTime;

    setPosicaoCorpo(x,y);
}

// Trocar para ser feita no gerenciador de colisões:: Dica do monitor
void Personagem::aplicarGravidade(){

    if(estaPulando)
        velocidade.y += GRAVIDADE * deltaTime;
}

void Personagens::Personagem::atualizarSprite() {
    figura->setProximaSecaoSprite();
}

void Personagens::Personagem::spriteInicial() {
    figura->setSpriteInicial();
}
