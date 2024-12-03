#include "ListaEntidades.hpp"
#include "stdfax.h"
using namespace Listas;

ListaEntidades::ListaEntidades() : LE()
{
    excluiTodos();
}

Listas::ListaEntidades::~ListaEntidades()
{
    excluiTodos();
}

void ListaEntidades::adiciona(Entidade *pE)
{
    if (pE == NULL) {
        cout << "ListaEntidades::adiciona impediu a inserção de um ponteiro nulo." << endl;
        exit(7); // testar
    }
    LE.insere(pE);
    // cout << "Entidade adicionada com sucesso!" << endl;
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
    if (getLista()) LE.limpaLista();
}

Entidade* ListaEntidades::operator[](int elem) {
    if (elem >= LE.getTamanho() || elem < 0) {
        cout << "ListaEntidades::operator[] impediu segfault." << endl;
        exit(1);
    }
    Entidade* pE = LE[elem];
    return pE;
}