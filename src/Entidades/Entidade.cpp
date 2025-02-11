#include "Entidade.hpp"
using namespace Entidades;

/* Construtoras/Destrutoras */

float Entidade::gravidade = 0;

Entidade::Entidade(float x_inicial, float y_inicial) :
Ente(),
x(x_inicial),
y(y_inicial),
velocidade(0.0,0.0),
buffer(),
antiGrav(0)
{
}

Entidade::~Entidade() {
}

void Entidade::aplicarGravidade() {

    float aux;

    if(!pGG){
        cout << "Personagem::aplicarGravidade() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = pGG->getDeltaTime();
    aux *= gravidade;

    velocidade.y += aux;

}

void Entidade::planar()
{
    float aux;

    if(!pGG){
        cout << "AberracaoEspacial::planar() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = antiGrav * pGG->getDeltaTime();

    velocidade.y -= aux;
        
}

void Entidade::setXY(const float novoX, const float novoY){
    x = novoX;
    y = novoY;
}

void Entidades::Entidade::setSentidos(int s[4]) {
    if (s) {
        for(int i=0; i<4; i++)
            sentidos[i] = s[i];
    }
}
