#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes(const Vector2f grav) :
gravidade(grav) {
            
}

GerenciadorColisoes::~GerenciadorColisoes() {
}

void GerenciadorColisoes::aplicarGravidade(Entidades::Entidade *pE) {
    if (pE) {
        pE->moverSprite(gravidade);
    } else { cout << "GerenciadorColisoes::aplicarGravidade(Entidades::Entidade *pE) -> Ponteiro nulo." << endl; }
}
