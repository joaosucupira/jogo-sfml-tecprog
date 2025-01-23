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

    coliJogObstaculo();
    coliInimObstaculo();
    coliJogInimigo();

}

void GerenciadorColisoes::setPJog1(Jogador *pJ1) {
    if (pJ1)
        pJog1 = pJ1;
    else
        { cout << "GerenciadorColisoes::setPJogador(Jogador *pJ1) -> ponteiro nulo." << endl; };
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

const bool GerenciadorColisoes::verificarColisao(FloatRect lim1, FloatRect lim2) const{
    return lim1.intersects(lim2);
}

const bool Gerenciadores::GerenciadorColisoes::verificarColisao(Entidade *pE1, Entidade *pE2) const {
    if (pE1 && pE2) {
        return pE1->hitBox().intersects(pE2->hitBox());
    } else cout << "const bool Gerenciadores::GerenciadorColisoes::verificarColisao(Entidade *pE1, Entidade *pE2) const -> ponteiro nulo" << endl;
}

void GerenciadorColisoes::verificarSentido(Vector2f pos1, Vector2f pos2) {

    Vector2f res = pos1 - pos2;
    const int margem = 10;

    for (int i = 0; i < 4; i++) {
        sentidos[i] = 0;
    }

    // Verificação do sentido de colisão mais relevante

    if (std::abs(res.x) > std::abs(res.y)) {
        if (res.x > margem) {
            sentidos[0] = 1; // Esquerda
        } else if (res.x < -margem) {
        // } else {
            sentidos[1] = 1; // Direita
        }
    }

    else {
        if (res.y > margem) {
            sentidos[3] = 1; // Baixo
        } else {
            sentidos[2] = 1; // Cima
        }
    }

}

void Gerenciadores::GerenciadorColisoes::verificarSentido(Entidade *pE1, Entidade *pE2) {
    if (!(pE1 || pE2)) {
        cout << "void Gerenciadores::GerenciadorColisoes::verificarSentido(Entidade *pE1, Entidade *pE2) - > ponteiro nulo" << endl;
    }

    FloatRect lim1 = pE1->hitBox();
    FloatRect lim2 = pE2->hitBox();

    Vector2f pos1(lim1.left, lim1.top);
    Vector2f pos2(lim2.left, lim2.top);

    Vector2f res = pos1 - pos2;
    const int margem = 10;

    for (int i = 0; i < 4; i++) {
        sentidos[i] = 0;
    }

    // Verificação do sentido de colisão mais relevante
    if (std::abs(res.x) > std::abs(res.y)) {
        if (res.x > margem) {
            sentidos[0] = 1; // Esquerda
        } else if (res.x < -margem) {
        // } else {
            sentidos[1] = 1; // Direita
        }
    }

    else {
        if (res.y > margem) {
            sentidos[3] = 1; // Baixo
        } else {
            sentidos[2] = 1; // Cima
        }
    }
}

void GerenciadorColisoes::coliJogObstaculo(){
    
    long unsigned int i;
    //Acoplar segundo jogador depois

    if(!pJog1){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> pJog1 nulo" << endl;
        return;
    }

    if(obstaculos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    if(!pJog1->getVivo()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> jog1 morto" << endl;
        return;
    }

    for(i = 0; i < obstaculos.size(); i++){

        // Verificação das colisoes

        if(verificarColisao(pJog1, obstaculos[i])) {
            verificarSentido(pJog1, obstaculos[i]);

            obstaculos[i]->setSentidos(sentidos);
            obstaculos[i]->obstacular(pJog1);

        }
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

        if(inimigos[i]->getVivo()){

            if(verificarColisao(pJog1, inimigos[i]) ){
                
                verificarSentido(pJog1, inimigos[i]);
                // if(dynamic_cast<Alienigena*>(inimigos[i]))
                //     jogadorAlienigena(pJog1, inimigos[i]); // RESPEITE A PALAVRA DO POLIMORFISSSMOOOOO
                inimigos[i]->setSentidos(sentidos);
                inimigos[i]->danificar(pJog1);

                cout << "Vida jogador 1: " << pJog1->getVidas() << endl;
                //danificar ficou dentro da colisao especifica de cada inimigo
            }   
        }
    }
}

void GerenciadorColisoes::coliInimObstaculo(){
    
    long unsigned int i, j;

    //Acoplar segundo jogador depois

    if(inimigos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector inimigos vazio" << endl;
        return;
    }

    if(obstaculos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    for(i = 0; i < inimigos.size(); i++){
        
        if(inimigos[i]->getVivo()){

            for(j = 0; j < obstaculos.size(); j++){


                if(verificarColisao( inimigos[i] , obstaculos[j] )) {
                    verificarSentido(inimigos[i], obstaculos[j]);

                    obstaculos[j]->setSentidos(sentidos);
                    obstaculos[j]->obstacular(inimigos[i]);

                }
                    
            }

        }
    }
}
