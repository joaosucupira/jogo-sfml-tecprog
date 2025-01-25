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

void Personagens::Personagem::operator--() {
    (num_vidas > 0) ? num_vidas-- : vivo = false;
}

void Personagens::Personagem::operator--(const int dano) {
    (num_vidas > 0) ? num_vidas -= dano : vivo = false;
  
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

FloatRect Personagem::hitBox() const {
    
    FloatRect lim = getLimites();
    const float ajuste = TAM_JOGADOR / 5.0f;
    

    lim.left += ajuste;
    lim.width -= 2 * ajuste;
    lim.top += ajuste;
    lim.height -= ajuste;

    return lim;
}
