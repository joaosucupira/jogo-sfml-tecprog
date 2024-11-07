#include "Jogador.hpp"


Personagens::Jogador::Jogador(const bool j1 ) : 
Personagem(ID::jogador1, sf::Vector2f(0, 0), sf::Vector2f(200,200), 6),
pontos(0), 
joga1(j1)
{
}

Jogador::~Jogador()
{
}

void Jogador::operator+=(int pts) { pontos += pts; }
