#include "Alienigena.hpp"

Personagens::Alienigena::Alienigena(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial)
{
    figura = new Figura(
        TAM_SECAO, TAM_SECAO, 
        QNTD_SECAO, QNTD_SECAO, 
        SEC_FINAL_X, SEC_FINAL_Y,
        SEC_INICIAL_X, SEC_INICIAL_Y
    );
    figura->setCor(Color::Red);
    carregarFigura();
    setTamanhoFigura(TAM_JOGADOR, TAM_JOGADOR);
    setPosicaoFigura(x, y);

}

Alienigena::~Alienigena()
{
}

void Personagens::Alienigena::carregarFigura() {
    if (figura) {
        figura->carregarTextura(ALIENIGENA_PATH);
    } else { cout << "void Personagens::Alienigena::carregarFigura() -> ponteiro nulo." << endl; }
}

void Personagens::Alienigena::executar() {
}

void Personagens::Alienigena::salvaDataBuffer() {
}
