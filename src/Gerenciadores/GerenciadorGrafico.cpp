/*
* Gerenciador gráfico criado sob padrão de projeto Singleton, ie, há apenas uma
* instância da classe, acessível globalmente, tornando-se um ponto de controle
* para os serviços imagéticos do sistema.
*/
#include "stdfax.h"
#include "GerenciadorGrafico.hpp"
using namespace Gerenciadores;

/* Instância singleton inicializada */
/* instancia eh a forma de acesso do gerenciador pelas classes do projeto*/
GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

GerenciadorGrafico* GerenciadorGrafico::getInstancia() {
    if (instancia == NULL) { instancia = new GerenciadorGrafico(); }
    return instancia;
}



/* Tela do jogo*/
GerenciadorGrafico::GerenciadorGrafico() :
    janela(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "Jogo ainda sem nome")),
    exibir(sf::Vector2f(LARGURA / 2, ALTURA / 2), sf::Vector2f(LARGURA, ALTURA)),
    mapaTexturas()
{
    janela->setFramerateLimit(TAXA_QUADROS);
    fonte = NULL;
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::limparJanela() {
    if (janela->isOpen()) { janela->clear(); }
}


void GerenciadorGrafico::desenhar(sf::RectangleShape *corpo)
{
    janela->draw(*corpo);
}

bool GerenciadorGrafico::getJanelaAberta() const { return janela->isOpen(); }

void GerenciadorGrafico::mostrar() {
    if (getJanelaAberta()) { janela->display(); }    
}

