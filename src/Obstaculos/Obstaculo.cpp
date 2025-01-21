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

