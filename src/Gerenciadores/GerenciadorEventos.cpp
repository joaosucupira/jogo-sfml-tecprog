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
pJanela(NULL)
{
}

GerenciadorEventos::~GerenciadorEventos()
{
    pJanela = NULL;
    pJog = NULL;
}

/* Métodos auxiliares */

void GerenciadorEventos::setJanela(Janela* pJ){
    if(pJ)
        pJanela = pJ;
    else
        cout<< "GerenciadorEventos::setJanela(Janela* pJ) -> PONTEIRO NULO" << endl;
}

void GerenciadorEventos::setPJog(Jogador* pJ){
    if(pJ)
        pJog = pJ;
    else
        cout << " GerenciadorEventos::setPJog(Jogador* pJ) -> PONTEIRO NULO" << endl;
}

/* Métodos principais*/

void GerenciadorEventos::monitorarJogador(){

    /* Inicializar a posicao como 0 aqui impede que seja travada */
    pJog->setVelocidadeX(0.0f);

    // Tirei os else para possibilitar movimento suave
    if (Keyboard::isKeyPressed(Keyboard::Left)){
        pJog->setVelocidadeX(-VELOCIDADE_ANDAR);
    } 
    
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
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
