#include "Jogo.hpp"
#include "Lista.h"
#include "ListaEntidades.hpp"
#include "Projetil.hpp"
#include "stdfax.h"

Jogo::Jogo()
{   
    cout << "hello" << endl;
    Listas::ListaEntidades listaDeProjeteis;
    Entidades::Projetil projetil1;
    listaDeProjeteis.adiciona(&projetil1);
    listaDeProjeteis[0]->salvar();
    listaDeProjeteis.exclui(&projetil1);
    listaDeProjeteis[0]->salvar();
    
}

Jogo::~Jogo()
{
}