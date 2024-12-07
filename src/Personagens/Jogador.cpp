#include "Jogador.hpp"
int Jogador::cont(0);

// Ideia para impedir criação de terceiro jogador: Verificar antes da chamada da cosntrutora
// (privar metodo construtor ou apenas nao utilizar sem a verificação)

Jogador::Jogador(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial),
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

    mover();
    // Colocar na classe gerenciador de colisoes
    aplicarGravidade();
    
    // zerar a velocidade no keyrelease
}