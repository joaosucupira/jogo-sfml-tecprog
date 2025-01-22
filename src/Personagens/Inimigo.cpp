#include "Inimigo.hpp"

Personagens::Inimigo::Inimigo(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial),
maldade(1)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::parar() {
    setVelocidadeX(0);
    setVelocidadeY(0);
    setEstaAndando(false);
}
