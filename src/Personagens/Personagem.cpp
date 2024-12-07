#include "Personagem.hpp"

Personagem::Personagem(const int x_inicial, const int y_inicial) :
Entidade(x_inicial, y_inicial),
num_vidas(1),
vivo(true)
{
}

Personagem::~Personagem() {
    num_vidas = -1;
    vivo = false;
}

void Personagem::mover(const int direcaoX, const int direcaoY) {
    if (vivo) {
        float x = direcaoX * velocidade.x;
        float y = direcaoY * velocidade.y; 
        corpo->move(x, y);
    }
}
