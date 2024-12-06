#include "Personagem.hpp"

Personagem::Personagem() :
Entidade(),
num_vidas(1),
vivo(true)
{
}

Personagem::~Personagem() {
    num_vidas = -1;
    vivo = false;
}

void Personagem::mover() {
    if (vivo) {
        corpo->move(velocidade);
    }
}
