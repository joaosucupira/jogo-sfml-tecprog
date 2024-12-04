/*
* Gerenciador gráfico criado sob padrão de projeto Singleton, ie, há apenas uma
* instância da classe, acessível globalmente, tornando-se um ponto de controle
* para os serviços imagéticos do sistema.
*/
#include "GerenciadorGrafico.hpp"
#include "Ente.hpp"

using namespace Gerenciadores;

/* Instância singleton inicializada */
GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

GerenciadorGrafico* GerenciadorGrafico::getInstancia() {
    if (instancia == NULL) { instancia = new GerenciadorGrafico(); }
    return instancia;
}


/* Tela do jogo*/
GerenciadorGrafico::GerenciadorGrafico() :
janela(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "Jogo++"))
{
    janela->setFramerateLimit(TAXA_QUADROS);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::limparJanela() {
    if (janela->isOpen()) { janela->clear(); }
}


void Gerenciadores::GerenciadorGrafico::desenharEnte(Ente *pE) {
    if (pE) {
        janela->draw(pE->getCorpo());
    } else { cout << "GerenciadorGrafico::desenharEnte(Ente *pE) -> Ponteiro nulo." << endl; }
}

bool GerenciadorGrafico::getJanelaAberta() const { return janela->isOpen(); }

void GerenciadorGrafico::mostrar() {
    if (getJanelaAberta()) { janela->display(); }    
}

