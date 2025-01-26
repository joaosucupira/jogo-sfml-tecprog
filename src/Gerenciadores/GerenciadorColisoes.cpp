#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL),
pJog2(NULL),
obstaculos(),
inimigos()

{
    obstaculos.clear();
    inimigos.clear();
    plasmas.clear();
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

void GerenciadorColisoes::incluirPlas(Plasma* pPlas){
    if(pPlas)
        plasmas.push_back(pPlas);
    else
        cout << "GerenciadorColisoes::incluirPlas(Plasma* pPlas) -> ponteiro plasma nulo" << endl;
}

const bool Gerenciadores::GerenciadorColisoes::verificarColisao(Entidade *pE1, Entidade *pE2) const {
    if (pE1 && pE2) {
        return pE1->hitBox().intersects(pE2->hitBox());
    } else cout << "const bool Gerenciadores::GerenciadorColisoes::verificarColisao(Entidade *pE1, Entidade *pE2) const -> ponteiro nulo" << endl;

    return false;
}

void Gerenciadores::GerenciadorColisoes::verificarSentido(Entidade *pE1, Entidade *pE2) {

    FloatRect lim1, lim2;
    Vector2f pos1, pos2, metade1, metade2, resultante;

    if (!(pE1 || pE2)) {
        cout << "void Gerenciadores::GerenciadorColisoes::verificarSentido(Entidade *pE1, Entidade *pE2) - > ponteiro nulo" << endl;
    }

    lim1 = pE1->hitBox();
    lim2 = pE2->hitBox();

    metade1 = Vector2f(lim1.width/2, lim1.height/2);
    metade2 = Vector2f(lim2.width/2, lim2.height/2);

    pos1 = Vector2f(lim1.left + metade1.x, lim1.top + metade1.y);
    pos2 = Vector2f(lim2.left + metade2.x, lim2.top + metade2.y);

    resultante = pos1 - pos2;

    resultante.x = -1 * (abs(resultante.x) - (metade1.x + metade2.x));
    resultante.y = -1 * (abs(resultante.y) - (metade1.y + metade2.y));

    const int margem = 2;

    for (int i = 0; i < 4; i++) {
        sentidos[i] = 0;
    }

    // Verificação do sentido de colisão mais relevante
    if (resultante.x < resultante.y && resultante.x > margem) {
        if ( pos1.x > pos2.x ) {
            sentidos[0] = 1; // Personagem a direita
            //cout << resultante.x << '\n' << endl;
        } else if ( pos1.x < pos2.x ) {
        // } else {
            sentidos[1] = 1; // Personagem a esquerda
            //cout << resultante.x << '\n' << endl;
        }
    }

    else if( resultante.y < resultante.x) {
        if ( pos1.y > pos2.y) {
            sentidos[3] = 1; // Personagem a cima
            
        } else if(pos1.y < pos2.y) {
            sentidos[2] = 1; // Personagem a baixo
            //cout << "SIMM" << endl;
        }
    }
}

void GerenciadorColisoes::coliJogObstaculo(){
    
    long unsigned int i;
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
        cout << "GerenciadorColisoes::coliJogInimigo() -> pJog1 nulo" << endl;
        return;
    }

    if(inimigos.empty()){
        cout << "GerenciadorColisoes::coliJogInimigo() -> vector inimigos vazio" << endl;
        return;
    }

    if(!pJog1->getVivo()){
        //cout << "GerenciadorColisoes::coliJogInimigos() -> jog1 morto" << endl;
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
