#include "ListaEntidades.hpp"
#include "stdfax.h"
using namespace Listas;

ListaEntidades::ListaEntidades()
{
    // LE();
}

Listas::ListaEntidades::~ListaEntidades()
{
    // LE();
}

void ListaEntidades::adiciona(Entidade *pE)
{
    if (pE == NULL) {
        cout << "ListaEntidades::adiciona impediu a inserção de um ponteiro nulo." << endl;
        exit(7); // testar
    }
    LE.insere(pE);
}

void ListaEntidades::exclui(Entidade *pE)
{
    if (pE == NULL) {
        cout << "ListaEntidades::exclui impediu a inserção de um ponteiro nulo." << endl;
        exit(7); // testar
    }
    LE.remove(pE);

}

void ListaEntidades::excluiTodos()
{
    LE.limpaLista();
}

Entidade* ListaEntidades::operator[](int elem) {
    if (elem >= LE.getTamanho() || elem < 0) {
        cout << "ListaEntidades::operator[] impediu segfault." << endl;
        exit(1);
    }
    Entidade* pE = LE[elem];
    return pE;
}