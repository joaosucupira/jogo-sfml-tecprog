#include "Jogador.hpp"
int Jogador::cont(0);

Jogador::Jogador(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial),
pontos(0),
joga1(cont == 0)
{
    if (cont < 2) {
        escolheCor();
        carregarSprite();
        ajustarSprite();
        // figura->setSprite(JOGADOR_PATH);
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

// Transferir quando possível para a classe entidade
// Ainda é preciso definir as sprites
void Jogador::carregarSprite() {
    if (figura) {
        figura->setSprite(JOGADOR_PATH);

    } else { cout << "Jogador::carregarSprite() -> Ponteiro nulo." << endl; }
}

void Jogador::salvaDataBuffer() {
}

void Jogador::executar() {

    mover();

    // Colocar na classe gerenciador de colisoes
    aplicarGravidade();

    // zerar a velocidade aqui faz o movimento travar
    /* velocidade.x = 0; */
}