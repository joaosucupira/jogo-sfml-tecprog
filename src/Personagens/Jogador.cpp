#include "Jogador.hpp"
int Jogador::cont(0);

Jogador::Jogador(const int x_inicial, const int y_inicial) :
Personagem(x_inicial, y_inicial),
pontos(0),
joga1(cont == 0)
{
    if (cont < 2) {
        escolheCor();
        cont++;
        //setVelocidade(20.0f, 20.0f);
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

/*void Jogador::andar(float dt) {

    if (Keyboard::isKeyPressed(Keyboard::Right)) 
        mover(velocidade.x * dt, 0.0f); 

    if (Keyboard::isKeyPressed(Keyboard::Left)) 
        mover(-(velocidade.x) * dt, 0.0f); 
}

void Jogador::pular(float dt) {
    static bool pular = true;
    float velocidadeVertical = 0.0f;

    if (Keyboard::isKeyPressed(Keyboard::Up)) {

        if (pular && getPosY() >= (ALTURA - getTamY())) {

            velocidadeVertical = FORCA_PULO; 

            pular = false;

        }
    } else pular = true;

    velocidadeVertical += GRAVIDADE * dt;
    mover(0.0f, velocidadeVertical * dt);
}*/

void Jogador::salvaDataBuffer() {
}

void Jogador::executar() {

    aplicarVelocidade();
    aplicarGravidade();
    velocidade.x = 0;
}