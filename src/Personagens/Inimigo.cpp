#include "Inimigo.hpp"

Personagens::Inimigo::Inimigo(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial)
{
}

Inimigo::~Inimigo()
{
}

void Personagens::Inimigo::parar() {
    setVelocidadeX(0);
    setVelocidadeY(0);
    setEstaAndando(false);
    atualizaParaFiguraInicial();
}
