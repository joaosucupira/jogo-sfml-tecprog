#include "Inimigo.hpp"

Personagens::Inimigo::Inimigo(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial),
maldade(1)
{
}

Inimigo::~Inimigo()
{
}