
#include "Plataforma.hpp"

Obstaculos::Plataforma::Plataforma(const int x_inicial, const int y_inicial) :
Obstaculo(false),
altura(0)
{
    figura = new Figura(
        PLATAFORMA_LADO, PLATAFORMA_LADO,
        PLATAFORMA_LADO, PLATAFORMA_LADO,
        PLATAFORMA_LADO, PLATAFORMA_LADO,
        PLATAFORMA_LADO, PLATAFORMA_LADO
    );
    carregarFigura();
    setTamanhoFigura(PLATAFORMA_LADO, PLATAFORMA_LADO);
    setPosicaoFigura(x_inicial, y_inicial);
    
}




Plataforma::~Plataforma()
{
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
}
