#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GC(),
relogio(new Clock())
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
    relogio = NULL;
}

void Jogo::distribuir() {
    distribuirRelogio();
    distribuirJanela();
}

void Jogo::distribuirRelogio() {
    GC.setRelogio(relogio);
}

void Jogo::distribuirJanela()
{
    pGG->setJanela(&janela);
}

void Jogo::executar()
{   

    Jogador* pJ = GC.getJogador();
    while (janela.aberta()) {

        float dt = relogio->restart().asSeconds();

        janela.eventoBase();

        // GC.tratarEntradaJogador(dt);
        // GC.aplicarGravidade(dt);
        GC.executar();

        janela.limpar();
        /* !!!DESENHOS AQUI!!!*/
        pGG->desenharEnte(pJ);

        janela.exibir();
    }
}
