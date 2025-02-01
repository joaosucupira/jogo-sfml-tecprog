/*
* Gerenciador gráfico criado sob padrão de projeto Singleton, ie, há apenas uma
* instância da classe, acessível globalmente, tornando-se um ponto de controle
* para os serviços imagéticos do sistema.
*
* Esta versão foi pensada para desacoplar o objeto RenderWindow e tê-lo agregado
* a uma nova classe janela que existe para facilitar o manejo compartilhado dessa
* janela do jogo.
*/
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
pJanela(new RenderWindow(VideoMode(LARGURA, ALTURA), "Anomalia++")),
deltaTime(0.0)
{
    pJanela->setFramerateLimit(TAXA_QUADROS);
}

GerenciadorGrafico::~GerenciadorGrafico(){
    if (pJanela) delete pJanela;
    pJanela = NULL;
}


/* MÉTODOS PRINCIPAIS */

void GerenciadorGrafico::desenharEnte(Ente *pE) {

    if (pE == NULL) {
        cout << "Gerenciadores::GerenciadorGrafico::desenharEnte(Ente *pE) -> ponteiro nulo" << endl;
        return;
    }

    pJanela->draw(pE->getFigura()->getSprite());
    
}

void GerenciadorGrafico::limparJanela() {
    if (!pJanela) {
        cout << "GerenciadorGrafico::limparJanela() -> ponteiro nulo" << endl;
        return;
    }
    pJanela->clear();
}

void Gerenciadores::GerenciadorGrafico::exibirNaJanela() {
    if (!pJanela) {
        cout << "GerenciadorGrafico::limparJanela() -> ponteiro nulo" << endl;
        return;
    }
    pJanela->display();
}

void GerenciadorGrafico::fecharJanela() {
    if (!pJanela) {
        cout << "GerenciadorGrafico::fecharJanela() -> ponteiro nulo" << endl;
        return;
    }
    pJanela->close();
}

RenderWindow* GerenciadorGrafico::getPJanela() const {

    if(pJanela){
        return pJanela;
    }
    cout << "GerenciadorGrafico::getPJanela() -> Ponteiro nulo." << endl;
    return NULL;
}

const bool GerenciadorGrafico::getJanelaAberta() const
{
    if (!pJanela) {
        cout << "const bool GerenciadorGrafico::getJanelaAberta() const -> ponteiro nulo" << endl;
        return NULL;
    }
    return (pJanela->isOpen() ? true : false);
}

