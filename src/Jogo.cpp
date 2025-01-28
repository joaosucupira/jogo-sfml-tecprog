#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GE(),
jog1(new Jogador()),
jog2(new Jogador()),
faseJupiter(),
faseLua()
{
    distribuir();
    executar();
}

Jogo::~Jogo() {
    jog1 = NULL;
    jog2 = NULL;
}


void Jogo::distribuir()
{
    GE.setPJog(jog1);
    distribuirJogador(1);

}

void Jogo::distribuirJogador(const int id_jogador) {


    if (id_jogador == 1) {
        faseJupiter.setJogador(jog1, 1);
        faseJupiter.definirGravidade();
    } else {
        faseJupiter.setJogador(jog2, 2);
    }
}

void Jogo::executar() {

    while (pGG->getJanelaAberta()) {
        
        pGG->setDeltaTime(tempo.restart().asSeconds());

        // pollevents
        while(pGG->getPJanela()->pollEvent( *(GE.getEvento()))) {
            if (Keyboard::isKeyPressed(Keyboard::E)) 
                GE.getEvento()->type = Event::Closed;

            if (GE.getEvento()->type == Event::Closed) {
                pGG->fecharJanela();
            }


        }
        pGG->limparJanela();
        // execucoes

        faseJupiter.executar();
        //faseJupiter.executar();
        
        pGG->exibirNaJanela();
    }
}


