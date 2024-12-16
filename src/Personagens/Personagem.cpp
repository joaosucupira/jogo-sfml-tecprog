#include "Personagem.hpp"

/* Construtoras/Destrutora */
Personagem::Personagem(const float x,  const float y) :
Entidade(x,y),
num_vidas(1),
velocidade(0.0,0.0),
estaAndando(false),
estaPulando(false)
{
}

Personagem::~Personagem() {
    num_vidas = -1;
}

/* Métodos principais*/
void Personagem::mover(){
    x += velocidade.x *  PIXEL_METRO * pGG->getDeltaTime();
    y += velocidade.y *  PIXEL_METRO * pGG->getDeltaTime();

    setPosicaoCorpo(x,y);
}

// Trocar para ser feita no gerenciador de colisões:: Dica do monitor -> Monitor é ruim kkkkk
void Personagem::aplicarGravidade(){

    if(estaPulando)
        velocidade.y += GRAVIDADE * pGG->getDeltaTime();
}

void Personagem::atualizarSprite() {

    if(estaAndando)
        figura->setProximaSecaoSprite();
}

void Personagem::spriteInicial() {
    figura->setSpriteInicial();
}
