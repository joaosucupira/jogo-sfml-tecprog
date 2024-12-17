#include "Jogador.hpp"
int Jogador::cont(0);

Jogador::Jogador(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial),
pontos(0),
joga1(cont == 0)
{
    //A verificação é feita na hora de construir o objeto?
    if (cont < 2) {
        figura = new Figura(
            TAM_SECAO, TAM_SECAO, 
            QNTD_SECAO, QNTD_SECAO, 
            SEC_FINAL_X, SEC_FINAL_Y,
            SEC_INICIAL_X, SEC_INICIAL_Y
        );
        escolheCor();
        setTamanhoFigura(100.0f, 100.0f);
        carregarFigura();
        cont++;
        
    } else { cout << endl << "Jogador::Jogador() -> Apenas dois jogadores permitidos." << endl; }
    
}

Jogador::~Jogador() {
}

void Personagens::Jogador::escolheCor() {
    Color cor = (joga1 ? Color::Green : Color::Blue);
    setCorFigura(cor);
}

void Jogador::operator+=(int pts) { pontos += pts; }

void Jogador::carregarFigura() {
    if (figura) {
        figura->carregarTextura(JOGADOR_PATH);
    } else { cout << "Jogador::carregarSprite() -> Ponteiro nulo." << endl; }
}

void Jogador::salvaDataBuffer() {
}

void Jogador::executar() {

    mover();
    aplicarGravidade();
    atualizarFigura();
}