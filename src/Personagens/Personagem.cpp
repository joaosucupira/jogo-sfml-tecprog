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

    // cout << pGG->getDeltaTime() << endl;
}

void Personagens::Personagem::atualizaParaFiguraInicial() {
    if (figura) {
        figura->setSecaoInicial();
    } else { cout << "Personagem::atualizaParaFiguraInicial() -> figura nula" << endl; }
}

void Personagens::Personagem::operator--() {
    (num_vidas > 0) ? num_vidas-- : vivo = false;
    figura->mostrarDano();
}

// Trocar para ser feita no gerenciador de colisões:: Dica do monitor -> Monitor é ruim kkkkk
void Personagem::aplicarGravidade(){  //testar ponteiro pGG
        velocidade.y += GRAVIDADE * pGG->getDeltaTime();
}

void Personagens::Personagem::aplicarGravidadeAnomola() {
        velocidade.x += GRAVIDADE * pGG->getDeltaTime();
}

void Personagem::atualizarFigura() { //testar ponteiro figura

    if(estaAndando)
        figura->atualizarSecao();
}

void Personagem::figuraInicial() {//testar ponteiro figura e criar booleano para estaParado
    figura->setSecaoInicial();
}

