#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
menu(),
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
    menu.setJogo(this);

    GE.setPJog(jog1);
    distribuirJogador(1);
    GE.setPJog(jog2);
    distribuirJogador(2);
}

void Jogo::distribuirJogador(const int id_jogador) {
    
    // Fase* rFase = &faseJupiter;
    Fase* rFase = &faseLua;

    if (id_jogador == 1) {
        (*rFase).setJogador(jog1, 1);
        (*rFase).configurarJogador(1);
        (*rFase).definirGravidade();
    } else {
        (*rFase).setJogador(jog2, 2);
        (*rFase).configurarJogador(2);
        (*rFase).definirGravidade();

    }

}

void Jogo::executar() {

    while (pGG->getJanelaAberta()) {
        
        pGG->setDeltaTime(tempo.restart().asSeconds());

        // pollevents
        while(pGG->getPJanela()->pollEvent( *(GE.getEvento()))) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) 
                encerrarJogo();

            if (GE.getEvento()->type == Event::Closed) {
                pGG->fecharJanela();
            }

            if (Keyboard::isKeyPressed(Keyboard::P)) {
                // menu.setEstado(5); // pause
                menu.menuPause();
            }


        }
        pGG->limparJanela();
        // execucoes
        menu.executar();
        if (menu.getEstado() == "Jogando") {
            // faseJupiter.executar();
            faseLua.executar();
        }
        // faseLua.executar();
        // faseJupiter.executar();
        
        pGG->exibirNaJanela();
    }
}


