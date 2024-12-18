#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL),
pJog2(NULL),
obstaculos(),
inimigos(),
limiteEtd1(),
limiteEtd2()
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

void Gerenciadores::GerenciadorColisoes::incluirObst(Obstaculo *pObst) {
    if (pObst) {
        obstaculos.push_back(pObst);
    } else { cout << "void Gerenciadores::GerenciadorColisoes::incluirObst(Obstaculo *pObst) -> ponteiro nulo." << endl; }
}

const bool GerenciadorColisoes::verificarColisao(Entidade* pEtd1, Entidade* pEtd2) const{
    return pEtd1->getLimites().intersects(pEtd2->getLimites());
}

void GerenciadorColisoes::coliJogObstaculo(){
    
    long unsigned int i;
    Vector2f res;

    //Acoplar jogador 2 depois

    if(!pJog1){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> pJog1 nulo" << endl;
        return;
    }

    if(obstaculos.empty()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    for(i = 0; i < obstaculos.size(); i++){
        
        if(verificarColisao( static_cast<Entidade*>(pJog1), static_cast<Entidade*>(obstaculos[i]) )){

            limiteEtd1 = pJog1->getLimites();
            limiteEtd2 = obstaculos[i]->getLimites();

            res.x = limiteEtd1.left - limiteEtd2.left;
            res.y = limiteEtd1.top - limiteEtd2.top;

            if(res.x < 0){
                pJog1->setVelocidadeX(0);
                
                //Etd1 é movido para a direita
            }
            else{
                //Etd1 é movido para a esquerda
            }
               

            if(res.y < 0){
                //Etd1 é movido para cima
            }
            else{
                //Etd1 é movido para baixo
            }
                
        }
}

}

void GerenciadorColisoes::coliJogInimigo(){

}

void GerenciadorColisoes::coliInimObstaculo(){

}


void GerenciadorColisoes::coliJogJanela(){
    
    limiteEtd1 = pJog1->getLimites();

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

