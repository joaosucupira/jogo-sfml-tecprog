#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
// GC(),
GE(),
jog1((LARGURA - TAM_JOGADOR)/2, (ALTURA + TAM_JOGADOR ) / 2),
fase1()
// plat1(0.0f, ALTURA - ALT_PLATAFORMA),
// ali1((LARGURA - TAM_JOGADOR)/2.5, (ALTURA + TAM_JOGADOR ) / 2)
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
}


void Jogo::distribuir()
{
    GE.setPJog(&jog1);
    fase1.setJogador(&jog1);

}

void Jogo::executar() {

    while (pGG->getJanelaAberta()) {

        // pollevents
        while(pGG->getPJanela()->pollEvent( *(GE.getEvento()))) {
            if (GE.getEvento()->type == Event::Closed) {
                pGG->fecharJanela();
            }
            GE.executar();
        }
        
        pGG->limparJanela();
        // execucoes

        fase1.executar();
        jog1.executar();
        pGG->desenharEnte(&jog1);
        
        pGG->exibirNaJanela();
    }
}


