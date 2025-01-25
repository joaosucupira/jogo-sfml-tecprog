#include "Plasma.hpp"


Plasma::Plasma(float x_inicial, float y_inicial):
Entidade(x_inicial, y_inicial),
ativo(false),
rapidez(V_PLASMA)
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
    if(ativo){
        aplicarGravidade();
        deslocar();
        desenhar();
    }
}

void Plasma::deslocar(){

    if(!pGG){
        cout<< "Personagem::mover() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    x += velocidade.x *  PIXEL_METRO * pGG->getDeltaTime();
    y += velocidade.y *  PIXEL_METRO * pGG->getDeltaTime();

    setPosicaoFigura(x,y);
}