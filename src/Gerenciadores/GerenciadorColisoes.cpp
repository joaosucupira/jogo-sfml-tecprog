#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL)
{

}

GerenciadorColisoes::~GerenciadorColisoes() {
    pJog1 = NULL;
}

void GerenciadorColisoes::executar() {
    colisaoJogadorJanela();
}


void GerenciadorColisoes::setPJogador(Jogador *pJ1) {
    if (pJ1)
        pJog1 = pJ1;
    else
        { cout << "GerenciadorColisoes::setPJogador(Jogador *pJ1) -> ponteiro nulo." << endl; };
}

void GerenciadorColisoes::colisaoJogadorJanela(){
    
    Vector2f posicao(pJog1->getX(), pJog1->getY());
    Vector2f tamanho(pJog1->getTamX(), pJog1->getTamY());

    if (posicao.x + tamanho.x > LARGURA) { // Lado direito
        pJog1->setXY(LARGURA - tamanho.x - COLISAO, posicao.y);
        pJog1->setVelocidadeX(0);

    } else if (posicao.x < 0) { // Lado esquerdo
        pJog1->setXY(COLISAO, posicao.y);
        pJog1->setVelocidadeX(0);
    }

    // Colisão com o chão
    if (posicao.y + tamanho.y > CHAO) {
        pJog1->setXY(posicao.x, CHAO - tamanho.y);
        pJog1->setVelocidadeY(0);
        pJog1->setEstaPulando(false);
    }
}

