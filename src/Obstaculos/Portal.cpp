#include "Portal.hpp"

Portal::Portal(const float x_inicial, const float y_inicial) : 
Obstaculo(x_inicial, y_inicial),
raio(100.0f)
{
    figura = new Figura(
        PORTAL_LADO, PORTAL_LADO,
        8, 1,
        224, 0,
        0, 0
    );

    carregarFigura();
    setTamanhoFigura(TAM_PORTAL, TAM_PORTAL),
    setPosicaoFigura(x_inicial, y_inicial);
}

Portal::~Portal()
{
}

void Portal::obstacular(Jogador *pJ) {
    if (!pJ) {
        cout << "void Portal::obstacular(Jogador *pJ) -> ponteiro nulo" << endl;
        return;
    }
    
    if (abs(getLimites().left - pJ->getLimites().left) <= raio &&
        abs(getLimites().top - pJ->getLimites().top <= raio)) {
        pJ->operator--();
        cout << "Vida Jogador:" << pJ->getVidas() << endl;
        pJ->posicionar(TAM_JOGADOR + 10.0f, TAM_JOGADOR + ALT_PLATAFORMA);
    }
}

void Portal::carregarFigura() {
    if (figura) {
        figura->carregarTextura(PORTAL_PATH);
    } else { cout << "void Portal::carregarFigura() -> figura nula" << endl; }
}

void Portal::atualizarFigura() {
    if (figura) {
        figura->atualizarSecao();
    } else { cout << "void Portal::atualizarFigura() -> figura nula" << endl; }
}

void Portal::executar() {
    pGG->desenharEnte(this);
    atualizarFigura();
}
