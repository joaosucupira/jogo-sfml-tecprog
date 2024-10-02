#include "Jogador.hpp"

Jogador::Jogador(const bool j1) :
pontos(0),
jogador1(j1)
{
}

Jogador::~Jogador()
{
}

void Jogador::operator+=(int pts) { pontos += pts; }
