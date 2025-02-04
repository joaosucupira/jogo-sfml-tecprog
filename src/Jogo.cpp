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

void Jogo::recuperarJogador()
{
    float x,y,velocidade_y;
    int num_vidas, pontos;
    bool ehJog1, andando, pulando;

    ifstream buffer(JOGADOR_SALVAR_PATH);

    while(buffer >> ehJog1 >> pontos >> x >> y >> num_vidas >> andando >> pulando >> velocidade_y){
        if(ehJog1){
            jog1->setXY(x,y);
            jog1->setPontos(pontos);
            jog1->setVidas(num_vidas);
            jog1->setAndando(andando);
            jog1->setPulando(pulando);
            jog1->setVelocidadeY(velocidade_y);
        }
        else{
            jog2->setXY(x,y);
            jog2->setPontos(pontos);
            jog2->setVidas(num_vidas);
            jog2->setAndando(andando);
            jog2->setPulando(pulando);
            jog2->setVelocidadeY(velocidade_y);
        }     
    }
    buffer.close();
    
}

void Jogo::executar() {

    recuperarJogador();
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


