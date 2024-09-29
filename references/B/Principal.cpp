#include "Principal.hpp"


Principal::Principal()
{
    janela = new sf::RenderWindow(sf::VideoMode(800, 600), "Game Window");
    amigo = Personagem(0,0,"./assets/img/jogador2sprite.png");

    executar();
}

Principal::~Principal()
{
    delete janela;
}

void Principal::executar()
{
    while (true) {
        janela->clear();
        amigo.atualizar();
        amigo.desenhar(janela);
        janela->display();
    } 
}
