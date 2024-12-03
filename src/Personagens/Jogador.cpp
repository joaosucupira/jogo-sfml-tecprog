#include "Jogador.hpp"

Personagens::Jogador::Jogador(const bool j1) : joga1(j1)
{
}

Jogador::~Jogador()
{
}

void Jogador::operator+=(int pts) { pontos += pts; }
