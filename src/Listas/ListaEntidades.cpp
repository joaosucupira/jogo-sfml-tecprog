#include "ListaEntidades.hpp"
#include "stdafx.h"

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
    if (getLista() && !vazia()) LE.limpaLista();
}

void ListaEntidades::salvar()
{

    path pasta("./data/salvamento");
    const int tam = LE.getTamanho();

    try{
        for(const auto &entrada : directory_iterator(pasta))
            remove(entrada.path());
    }catch(const filesystem_error &erro){
        cout << " ListaEntidades::salvar -> Erro ao limpar arquivos de salvamento" << erro.what() <<endl;
        return;
    }
    
    try{
        create_directory("./data/salvamento");
    }catch(const filesystem_error &erro){
        cout << " ListaEntidades::salvar-> Erro ao criar diretorio salvamento" << erro.what() <<endl;
        return;
    }
    

    for(int i = 0; i<tam; i++){
        LE[i]->salvar();
    }
    

}

Entidade* ListaEntidades::operator[](int elem) {
    if (elem >= LE.getTamanho() || elem < 0) {
        cout << "ListaEntidades::operator[] impediu segfault." << endl;
        exit(1);
    }
    Entidade* pE = LE[elem];
    return pE;
}