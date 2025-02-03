#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GE(),
jog1(new Jogador()),
jog2(new Jogador()),
faseLua(),
faseJupiter()
{
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

    faseJupiter.setPGEventos(&GE);
}

void Jogo::distribuirJogador(const int id_jogador) {
    
    Fase* fase = static_cast<Fase*>(&faseJupiter);

    if (id_jogador == 1) {
        fase->setJogador(jog1, 1);
    } else {
        fase->setJogador(jog2, 2);
    }

}

void Jogo::executar() {

    distribuir();
    faseJupiter.recuperar();
    
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
        
        faseJupiter.executar();
        
        pGG->exibirNaJanela();
    }
    faseJupiter.salvar();
}


