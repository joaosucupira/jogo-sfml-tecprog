#include "Jogador.hpp"
int Jogador::cont(0);

Jogador::Jogador(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial),
pontos(0),
joga1(cont == 0)
{
    if (cont < 2) {
        escolheCor();
        cont++;
        carregarSprite();
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

void Jogador::carregarSprite() {
    if (figura) {
        figura->setSprite(static_cast<string>(JOGADOR_PATH));

    } else { cout << "Jogador::carregarSprite() -> Ponteiro nulo." << endl; }
}


void Jogador::salvaDataBuffer() {
}

void Jogador::executar() {

    mover();
    /* Colocar na classe gerenciador de colisoes */
    aplicarGravidade();
    // zerar a velocidade aqui faz o movimento travar
    // precisa ser no keyrelease
    // velocidade.x = 0;
}