#include "Obstaculo.hpp"


Obstaculos::Obstaculo::Obstaculo(const float x, const float y) :
Entidade(x, y),
sentidos(NULL)
{
}

Obstaculo::~Obstaculo() {
    
}

void Obstaculos::Obstaculo::setSentidos(int *s) {
    if (s) {
        sentidos = s;
    }
}

FloatRect Obstaculo::hitBox() const {
    // Alterando uma cópia, logo, não é necessario restaurar a hitbox
    FloatRect lim = getLimites();
    const float ajuste = ALT_PLATAFORMA / 10.0f;

    lim.left -= ajuste;
    lim.width += 2 * ajuste;
    lim.top -= ajuste;
    lim.height += ajuste;
    return lim;
}