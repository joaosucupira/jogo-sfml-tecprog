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
#include "Plataforma.hpp"

using namespace Gerenciadores;

/* SINGLETON */

GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

GerenciadorGrafico* GerenciadorGrafico::getInstancia() {
    if (instancia == NULL) { instancia = new GerenciadorGrafico(); }
    return instancia;
}


/* CONSTRUTORA / DESTRUTORA */
GerenciadorGrafico::GerenciadorGrafico() :
pJanela(new RenderWindow(VideoMode(LARGURA, ALTURA), "Anomalia++")),
deltaTime(0.0),
pGeventos(NULL)
// pGcolisoes(NULL) // desacoplar
{
    pJanela->setFramerateLimit(TAXA_QUADROS);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    pJanela = NULL;
    pGeventos = NULL;
    // pGcolisoes = NULL; // desacoplar
}


/* MÉTODOS PRINCIPAIS */

void Gerenciadores::GerenciadorGrafico::desenharEnte(Ente *pE) {
    
    Personagem* pP = NULL;

    if (pE == NULL) {
        cout << "Gerenciadores::GerenciadorGrafico::desenharEnte(Ente *pE) -> ponteiro nulo" << endl;
        return;
    }

    pP = dynamic_cast<Personagem*>(pE);

    if (pP)
    {
        if (!pP->getVivo())
            return;
        
        pJanela->draw(pP->getFigura()->getSprite());

    } else {
        pJanela->draw(pE->getFigura()->getSprite());
    }
    
    
}

// void GerenciadorGrafico::setGC(GerenciadorColisoes* pGC){
//     if(pGC)
//         pGcolisoes = pGC;
//     else
//         {cout << "GerenciadorGrafico::setGC(Ente *pE) -> Ponteiro nulo." << endl;}
// } // desacoplar

void GerenciadorGrafico::setGE(GerenciadorEventos* pGE){
    if(pGE)
        pGeventos = pGE;
    else
        {cout << "GerenciadorGrafico::setGE(Ente *pE) -> Ponteiro nulo." << endl;}
}

void GerenciadorGrafico::incluiEnte(Ente* pE, int i) {
    if(pE){
        // listaEntes[i] = pE; // criar lista
    }
    else { cout << "GerenciadorGrafico::incluiEnte(Ente *pE) -> Ponteiro nulo." << endl; }

}

RenderWindow* GerenciadorGrafico::getPJanela() const {

    if(pJanela){
        return pJanela;
    }
    cout << "GerenciadorGrafico::getPJanela() -> Ponteiro nulo." << endl;
    return NULL;
}

void GerenciadorGrafico::executar(){

    Clock relogio;

    if(!pGeventos){
        cout << "GerenciadorGrafico::executar() -> Ponteiro nulo" << endl;
        return;
    }
        

    while (pJanela->isOpen()) {

        deltaTime = relogio.restart().asSeconds();

        while(pJanela->pollEvent( *(pGeventos->getEvento()) )){

            if(pGeventos->getEvento()->type == Event::Closed)
                pJanela->close();

            pGeventos->executar();
        }
            
        // pEnte->executar();
        // pGcolisoes->executar();
        // listaEntes[0]->executar();
        // listaEntes[1]->executar();
        // listaEntes[2]->executar();

        pJanela->clear();
        // desenharEnte(listaEntes[0]);
        // desenharEnte(listaEntes[1]);
        // desenharEnte(listaEntes[2]);
        pJanela->display();
        
    }

}


