#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GE(),
jog1(new Jogador()),
jog2(new Jogador()),
faseLua(),
faseJupiter()
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
    GE.setPJog(jog2);
    distribuirJogador(2);


}

void Jogo::distribuirJogador(const int id_jogador) {
    
    Fase* rFase = &faseJupiter;

    if (id_jogador == 1) {
        (*rFase).setJogador(jog1, 1);
        (*rFase).configurarJogador(1);
    } else {
        (*rFase).setJogador(jog2, 2);
        (*rFase).configurarJogador(2);
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

        // faseLua.executar();
        faseJupiter.executar();
        
        pGG->exibirNaJanela();
    }
}


