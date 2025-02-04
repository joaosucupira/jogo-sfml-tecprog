#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
menu(),
GE(),
jog1(new Jogador()),
jog2(new Jogador()),
faseLua(),
faseJupiter(),
faseEscolhida(NULL),
doisJogadores(false)
{
    menu.setJogo(this);
    // distribuir(); // só sabe-se como distribuir depois que o jogador informar fase e multijogador
    executar();
}

Jogo::~Jogo() {
    jog1 = NULL;
    jog2 = NULL;
    faseEscolhida = NULL;
}


void Jogo::distribuir()
{
    GE.setPJog(jog1);
    distribuirJogador(1);

    if (doisJogadores) {
        GE.setPJog(jog2);
        distribuirJogador(2);
    }
}

void Jogo::distribuirJogador(const int id_jogador) {
    
    Fase* pF = NULL;
    pF = getFaseEscolhida();

    if (id_jogador == 1) {
        (*pF).setJogador(jog1, 1);
        (*pF).configurarJogador(1);
        (*pF).definirGravidade();
    } else {
        (*pF).setJogador(jog2, 2);
        (*pF).configurarJogador(2);
        (*pF).definirGravidade();

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
            faseEscolhida->executar();
        }

        pGG->exibirNaJanela();
    }
}

void Jogo::escolherFase(const int id_fase) {
    if (id_fase == 1) {
        faseEscolhida = &faseLua;
    } else {
        faseEscolhida = &faseJupiter;
    }
}

Fase *Jogo::getFaseEscolhida() const
{
    if (faseEscolhida) {
        return faseEscolhida;
    } else {
        cout << "const Fase *Jogo::getFaseEscolhida() -> nenhuma fase foi escolhida" << endl;
        return NULL;
    }
}
