#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL),
pRelogio(NULL),
gravidade(GRAVIDADE)
{
    pJog1 = new Jogador(
        static_cast<int>((LARGURA - 100.0f) / 2),
        static_cast<int>((ALTURA + 100.0f) / 2)
    );
}

GerenciadorColisoes::~GerenciadorColisoes() {
    pJog1 = NULL;
}

void GerenciadorColisoes::executar() {
    float dt = pRelogio->restart().asSeconds();
    tratarEntradaJogador(dt);
    aplicarGravidade(dt);

}

void GerenciadorColisoes::setRelogio(Clock *pR) {
    if (pR) {
        pRelogio = pR;
    } else cout << "GerenciadorColisoes::setRelogio(Clock *pR) -> ponteiro nulo" << endl;
}

void GerenciadorColisoes::tratarEntradaJogador(float dt) {

    static bool pular = true;
    static float velocidadeVertical = 0.0f; 
 

    if (pJog1) {

        /* andar*/
        if (Keyboard::isKeyPressed(Keyboard::Right)) 
            pJog1->mover(100.0f * dt, 0.0f); 

        if (Keyboard::isKeyPressed(Keyboard::Left)) 
            pJog1->mover(-100.0f * dt, 0.0f); 

        /* pular */
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

Jogador *GerenciadorColisoes::getJogador() const {
    if (pJog1 == NULL)
        cout << "Jogador* GerenciadorColisoes::getJogador() const -> ponteiro nulo." << endl;
    return pJog1;
}
