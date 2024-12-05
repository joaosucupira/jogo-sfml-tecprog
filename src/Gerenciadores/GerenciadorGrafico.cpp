/*
* Gerenciador gráfico criado sob padrão de projeto Singleton, ie, há apenas uma
* instância da classe, acessível globalmente, tornando-se um ponto de controle
* para os serviços imagéticos do sistema.
*
* Esta versão foi pensada para desacoplar o objeto RenderWindow e tê-lo agregado
* a uma nova classe janela que existe para facilitar o manejo compartilhado dessa
* janela do jogo.
*/

#include "GerenciadorGrafico.hpp"
#include "Ente.hpp"

using namespace Gerenciadores;

/* SINGLETON */

GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

GerenciadorGrafico* GerenciadorGrafico::getInstancia() {
    if (instancia == NULL) { instancia = new GerenciadorGrafico(); }
    return instancia;
}


/* CONSTRUTORA / DESTRUTORA */
GerenciadorGrafico::GerenciadorGrafico() :
janela(NULL)
{
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    janela = NULL;
}


/* MÉTODOS PRINCIPAIS */

void Gerenciadores::GerenciadorGrafico::desenharEnte(Ente *pE) {
    if (pE) {
        janela->draw(pE->getCorpo());
    
    } else { cout << "GerenciadorGrafico::desenharEnte(Ente *pE) -> Ponteiro nulo." << endl; }
}

void GerenciadorGrafico::setJanela(Janela *pJ) {
    if (pJ) {
        janela = pJ->getJanela();
    } else { cout << "GerenciadorGrafico::setJanela(Janela *pJ) -> ponteiro nulo." << endl; }
}
