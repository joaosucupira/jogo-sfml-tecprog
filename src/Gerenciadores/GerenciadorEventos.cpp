/*
* Classe de namespace Gerenciadores
* Autor: João Klug
* Descrição: Classe de manipulação dos eventos do jogo, abertura de janela, entrada de teclado entre outros.
*/

#include "GerenciadorEventos.hpp"

using namespace Gerenciadores;


/* Construtoras/Destrutora */
GerenciadorEventos::GerenciadorEventos():
evento(),
pJog(NULL),
pJog2(NULL)
{
}

GerenciadorEventos::~GerenciadorEventos()
{
    pJog = NULL;
    pJog2 = NULL;
}


void GerenciadorEventos::executar() {
    
    monitorarJogador();
    
}

void Gerenciadores::GerenciadorEventos::digitarNome() {
    if (evento.type == Event::TextEntered) {
        cout << "Digitando" << endl;
    }
}

void Gerenciadores::GerenciadorEventos::limparJog()
{
    pJog = NULL;
    pJog2 = NULL;
}

void GerenciadorEventos::setPJog(Jogador *pJ)
{
    if(pJ)
        if (!pJog) {
            pJog = pJ;
        } else if (!pJog2) {
            pJog2 = pJ;
        } else {
            cout << "void GerenciadorEventos::setPJog(Jogador* pJ) -> Impossivel criar 3 jogadores" << endl;
            return;
        }
    else
        cout << "GerenciadorEventos::setPJog(Jogador* pJ) -> PONTEIRO NULO" << endl;
}

/* Métodos principais*/

void GerenciadorEventos::monitorarJogador() {
    
    if (!pJog) {
        cout << "void GerenciadorEventos::monitorarJogador() -> ponteiro nulo" << endl;
        return; 
    }

    /* Inicializar a posicao como 0 aqui impede que seja travada */
    pJog->setVelocidadeX(0.0f);
    pJog->setAndando(false);
    
    if (pJog2) {
        pJog2->setVelocidadeX(0.0f);
        pJog2->setAndando(false);
    }
    
    lerTeclado();
    if (pJog2) {
        lerTecladoJog2();
    }

    if (pJog->getVelocidade().x == 0) {
        pJog->getFigura()->setSecaoInicial();
    }
    if (pJog2) {
        if (pJog2->getVelocidade().x == 0) {
            pJog2->getFigura()->setSecaoInicial();
        }
    }

}

void Gerenciadores::GerenciadorEventos::lerTeclado() {

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        pJog->setAndando(true);
        pJog->setVelocidadeX(-VELOCIDADE_ANDAR);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        pJog->setAndando(true);
        pJog->setVelocidadeX(VELOCIDADE_ANDAR);
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (!pJog->getPulando()) {
            pJog->setPulando(true);
            pJog->setVelocidadeY(-sqrt(2.0 * pJog->getGravidade() * ALTURA_PULO));
        }
    }

}

void Gerenciadores::GerenciadorEventos::lerTecladoJog2() {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        pJog2->setAndando(true);
        pJog2->setVelocidadeX(-VELOCIDADE_ANDAR);
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        pJog2->setAndando(true);
        pJog2->setVelocidadeX(VELOCIDADE_ANDAR);
    }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        if (!pJog2->getPulando()) {
            pJog2->setPulando(true);
            pJog2->setVelocidadeY(-sqrt(2.0 * pJog->getGravidade() * ALTURA_PULO));
        }
    }
}
