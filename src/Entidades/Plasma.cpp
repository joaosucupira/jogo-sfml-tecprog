#include "Plasma.hpp"


Plasma::Plasma(float x_inicial, float y_inicial):
Entidade(x_inicial, y_inicial),
ativo(false)
{
    figura = new Figura(
        PLASMA_TAM_SEC, PLASMA_TAM_SEC,
        1, 1,
        0, 0,
        0, 0
    );
    carregarFigura(PLASMA_PATH);
    setTamanhoFigura(LARG_PLASMA, ALT_PLASMA);
    setPosicaoFigura(x_inicial, y_inicial);
}

Plasma::~Plasma()
{
}

void Plasma::executar()
{
    cout << "Plasma executado!" << endl;
}

void Plasma::salvar()
{
    cout << "Plasma salvo!" << endl;
}