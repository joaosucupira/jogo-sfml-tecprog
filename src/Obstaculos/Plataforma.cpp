
#include "Plataforma.hpp"

Obstaculos::Plataforma::Plataforma(const int x_inicial, const int y_inicial) :
Obstaculo(x_inicial, y_inicial),
altura(0)
{
    figura = new Figura(
        PLATAFORMA_LARGURA, PLATAFORMA_ALTURA,
        0, 0,
        0, 0,
        0, 0
    );
    carregarFigura();
    setTamanhoFigura(PLATAFORMA_LARGURA, PLATAFORMA_ALTURA);
    setPosicaoFigura(x_inicial, y_inicial);
    
}


Plataforma::~Plataforma()
{
}

void Obstaculos::Plataforma::obstacular(Jogador *pJ) {

}

void Obstaculos::Plataforma::salvaDataBuffer() {
}

void Obstaculos::Plataforma::carregarFigura()
{
    if (figura) {
        figura->carregarTextura(PLATAFORMA_PATH);
    } else { cout << "void Obstaculos::Plataforma::carregarFigura() -> ponteiro nulo" << endl; }
}

void Obstaculos::Plataforma::executar() {
    pGG->desenharEnte(this);
    
}
