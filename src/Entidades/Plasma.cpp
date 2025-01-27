#include "Plasma.hpp"


Plasma::Plasma(float x_inicial, float y_inicial):
Entidade(x_inicial, y_inicial),
ativo(false),
rapidez(7.8)
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
    setCorFigura(Color::Green);
    
}

Plasma::~Plasma()
{
}

void Plasma::executar()
{
    if (ativo) {
        aplicarGravidade();
        atualizarFigura();
        deslocar();
        desenhar();
    }
}

void Plasma::deslocar(){

    float aux;

    if(!pGG){
        cout<< "Personagem::mover() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    planar();

    aux = pGG->getDeltaTime();
    aux *= PIXEL_METRO;

    x += velocidade.x *  aux;
    y += velocidade.y *  aux;

    setPosicaoFigura(x,y);
}

void Plasma::planar(){
    
    float aux;

    if(!pGG){
        cout << "AberracaoEspacial::planar() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = rapidez * pGG->getDeltaTime();

    velocidade.y -= aux;
}