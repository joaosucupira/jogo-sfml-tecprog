#include "Obstaculo.hpp"


Obstaculos::Obstaculo::Obstaculo(const float x, const float y) :
Entidade(x, y)
{
}

Obstaculo::~Obstaculo() {
}

FloatRect Obstaculo::hitBox() const {
    
    FloatRect lim = getLimites();
    const float ajuste = ALT_PLATAFORMA / 10.0f;
        

    lim.left -= ajuste;
    lim.width += 2 * ajuste;
    lim.top -= ajuste;
    lim.height += ajuste;
    return lim;
}

