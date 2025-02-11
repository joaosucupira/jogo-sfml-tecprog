#include "Obstaculo.hpp"


Obstaculos::Obstaculo::Obstaculo(const float x, const float y) :
Entidade(x, y)
{
    antiGrav = gravidade;
}

Obstaculo::~Obstaculo() {
}

FloatRect Obstaculo::hitBox() const {
    
    FloatRect lim = getLimites();
    const float ajuste = figura->getAjuste();
        

    lim.left -= ajuste;
    lim.width += 2 * ajuste;
    lim.top -= ajuste;
    lim.height += ajuste;
    return lim;
}

void Obstaculo::gravitar()
{
    aplicarGravidade();
    planar();

    float aux;

    if(!pGG){
        cout<< "Obstaculo::gravitar() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = pGG->getDeltaTime();
    aux *= PIXEL_METRO;

    x += velocidade.x * aux;
    y += velocidade.y * aux;

    setPosicaoFigura(x,y);

}
