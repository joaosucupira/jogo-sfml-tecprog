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
#include "GerenciadorEventos.hpp"
#include "GerenciadorColisoes.hpp"

using namespace Gerenciadores;

/* SINGLETON */

GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

GerenciadorGrafico* GerenciadorGrafico::getInstancia() {
    if (instancia == NULL) { instancia = new GerenciadorGrafico(); }
    return instancia;
}


/* CONSTRUTORA / DESTRUTORA */
GerenciadorGrafico::GerenciadorGrafico() :
pJanela(NULL),
relogio(),
pGeventos(NULL),
pGcolisoes(NULL)
{
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    pJanela = NULL;
    pGeventos = NULL;
    pGcolisoes = NULL;
}


/* MÉTODOS PRINCIPAIS */

void Gerenciadores::GerenciadorGrafico::desenharEnte(Ente *pE) {
    if (pE) {
        pE->desenhar();
    
    } else { cout << "GerenciadorGrafico::desenharEnte(Ente *pE) -> Ponteiro nulo." << endl; }
}

void GerenciadorGrafico::setJanela(Janela *pJ) {
    if (pJ) {
        pJanela = pJ;
    } else { cout << "GerenciadorGrafico::setJanela(Janela *pJ) -> ponteiro nulo." << endl; }
}

void GerenciadorGrafico::setGC(GerenciadorColisoes* pGC){
    if(pGC)
        pGcolisoes = pGC;
}

void GerenciadorGrafico::setGE(GerenciadorEventos* pGE){
    if(pGE)
        pGeventos = pGE;
}

void GerenciadorGrafico::incluiEnte(Ente* pE){
    if(pE){
        pEnte = pE;
    }
    else { cout << "GerenciadorGrafico::incluiEnte(Ente *pE) -> Ponteiro nulo." << endl; }

}

//Gambiarra
RenderWindow* GerenciadorGrafico::getRenderWindow() const {
    if(pJanela){
        return pJanela->getJanela();
    }
    cout << "GerenciadorGrafico::getRenderWindow() -> Ponteiro nulo." << endl;
    return NULL;
}

void GerenciadorGrafico::executar(){

    if(!pEnte || !pGeventos || !pGcolisoes){
        cout << "GerenciadorGrafico::executar() -> Ponteiro nulo" << endl;
        return;
    }
        

    while(pJanela->aberta()){
        pEnte->setDeltaTime(relogio.restart().asSeconds());
        pGeventos->executar();
        pGcolisoes->executar();

        pJanela->limpar();
        desenharEnte(pEnte);
        pJanela->exibir();
    }

}


