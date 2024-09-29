#include "Jogo.hpp"
#include "Lista.h"
#include "Coord2D.h"
#include "stdfax.h"

Jogo::Jogo()
{   
    Lista<Coord2D<int>> listaCoordenadas;

    cout << "[";
    for (int i = 0; i < 10; i++) {
        Coord2D<int>* aux = new Coord2D<int>(i * 13, i * 19);
        listaCoordenadas.insere(aux);
        cout << "(" << aux->x << ", " << aux->y << ") ";

    }
    // Coord2D<int> result = *listaCoordenadas[0];
    cout << "]" << endl;
    listaCoordenadas.limpaLista();
}

Jogo::~Jogo()
{
}