#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
pJ1(NULL)
{
    pJ1 = new Jogador(true);
    pGG->setJanela(*(janela.getJanela()));
    executar();

}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    while (janela.aberta()) {
        Event e;
        while (janela.getJanela()->pollEvent(e)) {
            
            if (e.type == Event::Closed) {
                janela.fechar();
            }
        }
        janela.limpar();
        pGG->desenharEnte(pJ1);
        janela.exibir();
    }
}
