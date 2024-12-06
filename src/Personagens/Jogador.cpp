#include "Jogador.hpp"
int Jogador::cont(0);

Jogador::Jogador() :
Personagem(),
pontos(0),
joga1(cont == 0)
{
    if (cont < 2) {
        escolheCor();
        cont++;
    } else { cout << endl << "Jogador::Jogador() -> Apenas dois jogadores permitidos." << endl; }
;    
}

Jogador::~Jogador() {
}

void Personagens::Jogador::escolheCor() {
    Color cor = (joga1 ? Color::Green : Color::Blue);
    setCor(cor);
}

void Jogador::operator+=(int pts) { pontos += pts; }

void Jogador::salvaDataBuffer() {
}

void Jogador::executar() {
}