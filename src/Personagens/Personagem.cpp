#include "Personagem.hpp"

/* Construtoras/Destrutora */
Personagem::Personagem(const float x,  const float y) :
Entidade(x,y),
num_vidas(1),
andando(false)
{
    calcVivo();
}

Personagem::~Personagem() {
    num_vidas = -1;
}

/* Métodos principais*/
void Personagem::mover(){

    float aux;

    if(!pGG){
        cout<< "Personagem::mover() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = pGG->getDeltaTime();
    aux *= PIXEL_METRO;

    x += velocidade.x * aux;
    y += velocidade.y * aux;

    setPosicaoFigura(x,y);
}

void Personagem::atualizarFigura() {

    if(!figura){
        cout << "Personagem::atualizarFigura() -> ponteiro figura nulo!";
        return;
    }
    
    if(andando)
        figura->atualizarSecao();
    else
        atualizaParaFiguraInicial();
}

FloatRect Personagem::hitBox() const {
    
    FloatRect lim = getLimites();
    const float ajuste = TAM_JOGADOR / 5.0f;
    

    lim.left += ajuste;
    lim.width -= 2 * ajuste;
    lim.top += ajuste;
    lim.height -= ajuste;

    return lim;
}

void Personagem::parar() {
    setVelocidadeX(0);
    setVelocidadeY(0);
    andando = false;
}

void Personagens::Personagem::operator--() {
    num_vidas--;
    calcVivo();
}

void Personagens::Personagem::operator--(const int dano) {
    num_vidas -= dano;
    calcVivo();
}


