#include "Personagem.hpp"

/* Construtoras/Destrutora */
Personagem::Personagem(const float x,  const float y) :
Entidade(x,y),
num_vidas(1),
estaAndando(false),
estaPulando(true)
{
    calcVivo();
}

Personagem::~Personagem() {
    num_vidas = -1;
}

/* Métodos principais*/
void Personagem::mover(){
    x += velocidade.x *  PIXEL_METRO * pGG->getDeltaTime();
    y += velocidade.y *  PIXEL_METRO * pGG->getDeltaTime();

    setPosicaoFigura(x,y);
}

void Personagens::Personagem::operator--() {
    (num_vidas > 0) ? num_vidas-- : vivo = false;
}

void Personagens::Personagem::operator--(const int dano) {
    if (num_vidas > 0) {
        num_vidas -= dano;
    } else {
        vivo = false;
    }
}

// Trocar para ser feita no gerenciador de colisões:: Dica do monitor -> Monitor é ruim kkkkk
void Personagem::aplicarGravidade() {  //testar ponteiro pGG
    velocidade.y += GRAVIDADE * pGG->getDeltaTime();
}

void Personagem::atualizarFigura() {

    if(!figura){
        cout << "Personagem::atualizarFigura() -> ponteiro figura nulo!";
        return;
    }
    
    if(estaAndando)
        figura->atualizarSecao();
    else
        atualizaParaFiguraInicial();
}

