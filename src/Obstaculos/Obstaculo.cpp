#include "Obstaculo.hpp"


Obstaculos::Obstaculo::Obstaculo(const float x, const float y) :
Entidade(x, y)
{
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

