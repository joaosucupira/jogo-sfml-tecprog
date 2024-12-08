#include "GerenciadorEventos.hpp"

using namespace Gerenciadores;

GerenciadorEventos::GerenciadorEventos():
evento(),
pJog(NULL),
pJanela(NULL)
{
}

GerenciadorEventos::~GerenciadorEventos()
{
    pJanela = NULL;
    pJog = NULL;
}

void GerenciadorEventos::setJanela(Janela* pJ){
    if(pJ)
        pJanela = pJ;
    else
        cout<< "GerenciadorEventos::setJanela(Janela* pJ) -> PONTEIRO NULO" << endl;
}

void GerenciadorEventos::setPJog(Jogador* pJ){
    if(pJ)
        pJog = pJ;
}

void GerenciadorEventos::monitorarJogador(){

    if (Keyboard::isKeyPressed(Keyboard::Left)){
        pJog->setVelocidadeX(-VELOCIDADE_ANDAR);
    } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        pJog->setVelocidadeX(VELOCIDADE_ANDAR);
    }

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (!pJog->getEstaPulando()) {
            pJog->setEstaPulando(true);
            pJog->setVelocidadeY(-sqrt(2.0 * GRAVIDADE * ALTURA_PULO));
        }
    }

}

void GerenciadorEventos::executar() {

    if(!pJanela){
        cout<< "GerenciadorEventos::executar() -> PONTEIRO NULO" << endl;
        return;
    }


    while(pJanela->obterEvento(evento)){

        if(evento.type == Event::Closed)
            pJanela->fechar();
        
        monitorarJogador();
    }

}
