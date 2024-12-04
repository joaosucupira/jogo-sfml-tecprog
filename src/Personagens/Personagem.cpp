#include "Personagem.hpp"

Personagem::Personagem() :
Entidade(),
num_vidas(1)
{
}

Personagem::~Personagem() {
    num_vidas = -1;
}
