#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();



Jogo::Jogo() :
GE(),
jog1(new Jogador()),
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

        fase1.executar();
        
        pGG->exibirNaJanela();
    }
}


