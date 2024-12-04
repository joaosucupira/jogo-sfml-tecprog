#include "Jogador.hpp"

Jogador::Jogador(const bool j1) :
Personagem(), 
joga1(j1) {
    escolheCor();
}

Jogador::~Jogador()
{
}

void Personagens::Jogador::escolheCor() {
    if (joga1) {
        setCor(Color::Green);
    } else {
        setCor(Color::Yellow);
    }
}

void Personagens::Jogador::setCor(Color cor)
{
    corpo->setFillColor(cor);
}

void Jogador::operator+=(int pts) { pontos += pts; }

void Jogador::salvaDataBuffer() {
}

void Jogador::executar() {
}