#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo()
{

    distribuirJanela();
    executar();

}

Jogo::~Jogo()
{

}

void Jogo::distribuirJanela() {
    pGG->setJanela(&janela);
    
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

        /* !!!DESENHOS AQUI!!!*/

        janela.exibir();
    }
}
