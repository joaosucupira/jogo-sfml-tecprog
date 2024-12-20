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
relogio()
{
}

GerenciadorEventos::~GerenciadorEventos()
{
    pJog = NULL;
}

/* Métodos auxiliares */

void GerenciadorEventos::setPJog(Jogador* pJ){
    if(pJ)
        pJog = pJ;
    else
        cout << "GerenciadorEventos::setPJog(Jogador* pJ) -> PONTEIRO NULO" << endl;
}

/* Métodos principais*/

void GerenciadorEventos::monitorarJogador() {

    /* Inicializar a posicao como 0 aqui impede que seja travada */
    pJog->setVelocidadeX(0.0f);
    pJog->setEstaAndando(false);

    // Tirei os else para possibilitar movimento suave
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        pJog->setEstaAndando(true);
        //pJog->getFigura()->virar(1);
        pJog->setVelocidadeX(-VELOCIDADE_ANDAR);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        pJog->setEstaAndando(true);
        //pJog->getFigura()->virar(1);
        pJog->setVelocidadeX(VELOCIDADE_ANDAR);
    }

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (!pJog->getEstaPulando()) {
            pJog->setEstaPulando(true);
            pJog->setVelocidadeY(-sqrt(2.0 * GRAVIDADE * ALTURA_PULO));
        }
    }

    if (pJog->getVelocidade().x == 0) {
        pJog->getFigura()->setSecaoInicial();
    }

}

void GerenciadorEventos::executar() {
    
    monitorarJogador();
    
}
