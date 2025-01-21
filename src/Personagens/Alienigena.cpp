#include "Alienigena.hpp"

Personagens::Alienigena::Alienigena(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial)
{
    figura = new Figura(
        TAM_SECAO, TAM_SECAO, 
        QNTD_SECAO_X, QNTD_SECAO_Y, 
        SEC_FINAL_X, SEC_FINAL_Y,
        SEC_INICIAL_X, SEC_INICIAL_Y
    );
    // figura->setCor(Color::Red);
    carregarFigura();
    setTamanhoFigura(TAM_JOGADOR, TAM_JOGADOR);
    setPosicaoFigura(x, y);

    velocidade.x = -(VELOCIDADE_ANDAR - 0.3);
    setEstaAndando(true);

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
    mover();
    aplicarGravidade();
    atualizarFigura();
    pGG->desenharEnte(this);
}

void Alienigena::danificar(Jogador* pJ) {
    if(pJ)
        pJ->operator--();
    else
        cout << "Alienigena::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
}

void Personagens::Alienigena::salvaDataBuffer() {
}

void Personagens::Alienigena::mover() {
    static int sentido = 1;
    if (pGG->getDeltaTime() > 0.1) {
        sentido *= -1;
    }
    x += velocidade.x *  PIXEL_METRO * pGG->getDeltaTime() * sentido;
    y += velocidade.y *  PIXEL_METRO * pGG->getDeltaTime() * sentido;
    setPosicaoFigura(x,y);
}
