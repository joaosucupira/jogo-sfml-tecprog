#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL)
//gravidade(GRAVIDADE),
//pRelogio(NULL)
{
    pJog1 = new Jogador(
        (LARGURA - 100.0f) / 2,
        (ALTURA + 100.0f) / 2
    );
}

GerenciadorColisoes::~GerenciadorColisoes() {
    pJog1 = NULL;
}

void GerenciadorColisoes::executar() {
    

}


Jogador *GerenciadorColisoes::getJogador() const {
    if (pJog1 == NULL)
        cout << "Jogador* GerenciadorColisoes::getJogador() const -> ponteiro nulo." << endl;
    return pJog1;
}

void GerenciadorColisoes::colisaoJogadorChao(){
    
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



/*
void GerenciadorColisoes::setRelogio(Clock *pR) {
    if (pR) {
        pRelogio = pR;
    } else cout << "GerenciadorColisoes::setRelogio(Clock *pR) -> ponteiro nulo" << endl;
}

void GerenciadorColisoes::tratarEntradaJogador(float dt) {

    static bool pular = true;
    static float velocidadeVertical = 0.0f; 
 

    if (pJog1) {

        //andar
        if (Keyboard::isKeyPressed(Keyboard::Right)) 
            pJog1->mover(100.0f * dt, 0.0f); 

        if (Keyboard::isKeyPressed(Keyboard::Left)) 
            pJog1->mover(-100.0f * dt, 0.0f); 

        //pular 
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (pular && pJog1->getPosY() >= (ALTURA - pJog1->getTamY())) {
                velocidadeVertical = FORCA_PULO; 

                pular = false;
            }
        } else {
            pular = true; 
        }

        velocidadeVertical += GRAVIDADE * dt;
        pJog1->mover(0.0f, velocidadeVertical * dt);

        if (pJog1->getPosY() > (ALTURA - pJog1->getTamY())) {
            pJog1->setPosY(ALTURA - pJog1->getTamY()); // Define no chão
            velocidadeVertical = 0.0f;                 // Zera a velocidade vertical
        }
    }
}
void GerenciadorColisoes::aplicarGravidade(float dt) {

    RectangleShape* corpo = pJog1->getCorpo();

    if (corpo->getPosition().y + corpo->getSize().y < ALTURA) {
        float dy = gravidade * dt;
        corpo->move(0.0f, dy);
    }
}
*/

