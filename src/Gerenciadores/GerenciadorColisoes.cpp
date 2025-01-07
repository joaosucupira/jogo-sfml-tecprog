#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL),
pJog2(NULL),
obstaculos(),
inimigos()
{
    obstaculos.clear();
    inimigos.clear();
}

GerenciadorColisoes::~GerenciadorColisoes() {
    pJog1 = NULL;
    pJog2 = NULL;
    obstaculos.clear();
    inimigos.clear();
}

void GerenciadorColisoes::executar() {

    coliJogJanela();
    coliJogObstaculo();
    coliJogInimigo();
    coliInimObstaculo();
}

void GerenciadorColisoes::setPJog1(Jogador *pJ1) {
    if (pJ1)
        pJog1 = pJ1;
    else
        { cout << "GerenciadorColisoes::setPJogador(Jogador *pJ1) -> ponteiro nulo." << endl; };
}

const bool GerenciadorColisoes::verificarColisao(Entidade* pEtd1, Entidade* pEtd2) const{
    return pEtd1->getLimites().intersects(pEtd2->getLimites());
}

void GerenciadorColisoes::incluirObst(Obstaculo* pObst){
    if(pObst)
        obstaculos.push_back(pObst);
    else
        cout << "GerenciadorColisoes::incluirObst(Obstaculo* pObst) -> ponteiro nulo" << endl;
}

void GerenciadorColisoes::incluirInim(Inimigo* pInim){
    if(pInim)
        inimigos.push_back(pInim);
    else
        cout << "GerenciadorColisoes::incluirInim(Inimigo* pInim) -> ponteiro nulo" << endl;
}

void verificarSentido(Vector2f posEtd1, Vector2f posEtd2, int v[4]){
    
    Vector2f res = posEtd1 - posEtd2;

    if(res.x < 0)
        v[0] = 1; //esquerda
    else
        v[1] = 1; //direita
    
    if(res.y < 0)
        v[2] = 1; //cima
    else
        v[3] = 1; //baixo

}

void ajustarPosicao(Personagem* pPersonagem, FloatRect lmEtd1, FloatRect lmEtd2, int v[4]){

    verificarSentido(Vector2f(lmEtd1.left, lmEtd1.top), Vector2f(lmEtd2.left, lmEtd2.top), v);

    //Colisao a esquerda do Personagem
    if(v[0])
        pPersonagem->setXY(lmEtd2.left + (lmEtd2.width + COLISAO), lmEtd1.top);
    
    //Colisao a direita do Personagem
    if(v[1])
        pPersonagem->setXY(lmEtd2.left - (lmEtd1.width + COLISAO), lmEtd1.top);
    
    //Colisao a baixo do Personagem
    if(v[2]){
        pPersonagem->setXY(lmEtd1.left, lmEtd2.top - (lmEtd1.height + COLISAO));
        pPersonagem->setVelocidadeY(0);
        pPersonagem->setEstaPulando(false);
    }
    //Colisao a cima do Personagem
    if(v[3])
        pPersonagem->setXY(lmEtd1.left, lmEtd2.top + (lmEtd2.height + COLISAO));
    

}

void GerenciadorColisoes::coliJogObstaculo(){
    
    long unsigned int i;
    int sentidos [4] = {0};

    //Acoplar segundo jogador depois

    if(!pJog1){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> pJog1 nulo" << endl;
        return;
    }

    if(obstaculos.empty()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    if(!pJog1->getVivo()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> jog1 morto" << endl;
        return;
    }

    for(i = 0; i < obstaculos.size(); i++){
        
        if(verificarColisao( static_cast<Entidade*>(pJog1), static_cast<Entidade*>(obstaculos[i]) ))
            ajustarPosicao(static_cast<Personagem*> (pJog1), pJog1->getLimites(), obstaculos[i]->getLimites(), sentidos);
        
    }
}

void GerenciadorColisoes::coliJogInimigo(){

    long unsigned int i;

    if(!pJog1){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> pJog1 nulo" << endl;
        return;
    }

    if(inimigos.empty()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    if(!pJog1->getVivo()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> jog1 morto" << endl;
        return;
    }

    for(i=0; i<inimigos.size(); i++){
        if( verificarColisao( static_cast<Entidade*>(pJog1), static_cast<Entidade*>(inimigos[i]) ) ){
            inimigos[i]->danificar(pJog1);
            cout << "Vida jogador 1: " << pJog1->getVidas() << endl;
        }
            
    }


}

void GerenciadorColisoes::coliInimObstaculo(){
    
    long unsigned int i, j;
    int sentidos [4] = {0};

    //Acoplar segundo jogador depois

    if(inimigos.empty()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> vector inimigos vazio" << endl;
        return;
    }

    if(obstaculos.empty()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    for(i = 0; i < inimigos.size(); i++){
        
        if(inimigos[i]->getVivo()){

            for(j = 0; j < obstaculos.size(); j++){

                if(verificarColisao( static_cast<Entidade*>(inimigos[i]), static_cast<Entidade*>(obstaculos[j]) )){
                    ajustarPosicao(static_cast<Personagem*> (inimigos[i]), inimigos[i]->getLimites(), obstaculos[j]->getLimites(), sentidos);
                }
                    
            }

        }
    }
}

void GerenciadorColisoes::coliJogJanela(){
    
    FloatRect limiteEtd1 = pJog1->getLimites();

    Vector2f posicao(limiteEtd1.left, limiteEtd1.top);
    Vector2f tamanho(limiteEtd1.width, limiteEtd1.height);

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

