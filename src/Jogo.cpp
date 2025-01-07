#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
// tempo(),
GE(),
jog1(new Jogador((LARGURA - TAM_JOGADOR)/2, (ALTURA + TAM_JOGADOR ) / 2)),
fase1()
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
}


void Jogo::distribuir()
{
    GE.setPJog(jog1);
    fase1.setJogador(jog1);

}

void Jogo::executar() {
    // pGG->setDeltaTime(0.0);

    while (pGG->getJanelaAberta()) {
        
        pGG->setDeltaTime(tempo.restart().asSeconds());

        // pollevents
        while(pGG->getPJanela()->pollEvent( *(GE.getEvento()))) {
            if (GE.getEvento()->type == Event::Closed) {
                pGG->fecharJanela();
            }
            // GE.executar();
        }
        pGG->limparJanela();
        // execucoes

        fase1.executar();
        
        pGG->exibirNaJanela();
    }
}


