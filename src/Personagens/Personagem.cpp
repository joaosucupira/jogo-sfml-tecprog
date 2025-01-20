#include "Personagem.hpp"

/* Construtoras/Destrutora */
Personagem::Personagem(const float x,  const float y) :
Entidade(x,y),
num_vidas(1),
velocidade(0.0,0.0),
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

void Personagens::Personagem::atualizaParaFiguraInicial() {
    if (figura) {
        figura->setSecaoInicial();
    } else { cout << "Personagem::atualizaParaFiguraInicial() -> figura nula" << endl; }
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

void Personagem::atualizarFigura() { //testar ponteiro figura
    if(estaAndando && figura)
        figura->atualizarSecao();
}

void Personagem::figuraInicial() { //testar ponteiro figura e criar booleano para estaParado
    figura->setSecaoInicial();
}

FloatRect Personagem::hitBox() const {
    // Alterando uma cópia, logo, não é necessario restaurar a hitbox
    FloatRect lim = getLimites();
    const float ajuste = TAM_JOGADOR / 5.0f;

    lim.left += ajuste;
    lim.width -= 2 * ajuste;
    lim.top += ajuste;
    lim.height -= ajuste;

    return lim;
}
