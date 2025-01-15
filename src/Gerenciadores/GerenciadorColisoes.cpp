#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL),
pJog2(NULL),
obstaculos(),
inimigos(),
lim1(),
lim2(),
ajustePerso(TAM_JOGADOR / 5),
ajusteObst(ALT_PLATAFORMA / 10)
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
    coliInimJanela();
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

void GerenciadorColisoes::verificarSentido(Vector2f pos1, Vector2f pos2) {

    Vector2f res = pos1 - pos2;
    const int margem = 10;

    for (int i = 0; i < 4; i++) {
        sentidos[i] = 0;
    }

    if (std::abs(res.x) > std::abs(res.y)) {
        if (res.x > margem) {
            sentidos[0] = 1; // Esquerda
        } else {
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
    // Vector2f res;

    // for(int i = 0; i < 4; i++){
    //     sentidos[i] = 0;
    // }

    // res = pos1 - pos2;

    // if(res.x > 10 ) {
    //     sentidos[0] = 1; //esquerda
    // }

    // else if(res.x < -10 ) {
    //     sentidos[1] = 1; //direita
    // }

    // if(res.y < -10) {
    //     sentidos[2] = 1; //cima

    // }

    // else if(res.y > 10) {
    //     sentidos[3] = 1; //baixo
    // }

    
// }

FloatRect GerenciadorColisoes::ajusteHitBoxPerso(FloatRect lim){
    
    lim.left += ajustePerso;
    lim.width -= 2 * ajustePerso;
    lim.top += ajustePerso;
    lim.height -= ajustePerso;

    return lim;
}

void GerenciadorColisoes::restauraHitBoxPerso(FloatRect &lim){
    lim.left -= ajustePerso;
    lim.width += 2 * ajustePerso;
    lim.top -= ajustePerso;
    lim.height += ajustePerso;
    
    pJog1->exibirHitbox(lim);
}

FloatRect Gerenciadores::GerenciadorColisoes::ajusteHitBoxObst(FloatRect lim) {
    lim.left -= ajusteObst;
    lim.width += 2 * ajusteObst;
    lim.top -= ajusteObst;
    lim.height += ajusteObst;
    return lim;
}

void Gerenciadores::GerenciadorColisoes::restauraHitBoxObst(FloatRect &lim) {

    lim.left += ajusteObst;
    lim.width -= 2 * ajusteObst;
    lim.top += ajusteObst;
    lim.height -= ajusteObst;
}

void GerenciadorColisoes::coliJogObstaculo(){
    
    long unsigned int i;
    //Acoplar segundo jogador depois

    if(!pJog1){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> pJog1 nulo" << endl;
        return;
    }

    if(obstaculos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    if(!pJog1->getVivo()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> jog1 morto" << endl;
        return;
    }

    for(i = 0; i < obstaculos.size(); i++){

        lim1 = ajusteHitBoxPerso(pJog1->getLimites());
        pJog1->exibirHitbox(lim1);

        // Talvez precise ajustar a hit box do obstaculo
        lim2 = ajusteHitBoxObst(obstaculos[i]->getLimites());
        // lim2 = (obstaculos[i]->getLimites());
        obstaculos[i]->exibirHitbox(lim2);


        if(verificarColisao(lim1, lim2)){
            verificarSentido(Vector2f(lim1.left, lim1.top), Vector2f(lim2.left, lim2.top));
            restauraHitBoxPerso(lim1);
            restauraHitBoxObst(lim2);
            jogadorPlataforma(pJog1);

            obstaculos[i]->exibirHitbox(lim2);



            // obstaculos[i]->obstacular(pJog1);
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
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    if(!pJog1->getVivo()){
        cout << "GerenciadorColisoes::coliJogObstaculo() -> jog1 morto" << endl;
        return;
    }

    for(i=0; i<inimigos.size(); i++){

        if(inimigos[i]->getVivo()){

            lim1 = ajusteHitBoxPerso(pJog1->getLimites());
            lim2 = ajusteHitBoxPerso(inimigos[i]->getLimites());

            if(verificarColisao( lim1, lim2 ) ){
                
                verificarSentido(Vector2f(lim1.left, lim1.top), Vector2f(lim2.left, lim2.top));
                restauraHitBoxPerso(lim1);
                restauraHitBoxPerso(lim2);

                if(dynamic_cast<Alienigena*>(inimigos[i]))
                    jogadorAlienigena(pJog1, inimigos[i]);

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

                lim2 = ajusteHitBoxObst(obstaculos[j]->getLimites());
                lim1 = ajusteHitBoxPerso(inimigos[i]->getLimites());

                if(verificarColisao( lim1 , lim2 )){
                    verificarSentido(Vector2f(lim1.left, lim1.top), Vector2f(lim2.left, lim2.top));
                    restauraHitBoxObst(lim2);
                    restauraHitBoxPerso(lim1);
                    inimigoPlataforma(inimigos[i]);

                }
                    
            }

        }
    }
}

void GerenciadorColisoes::coliJogJanela(){

    FloatRect limiteEtd1 = pJog1->getLimites();

    limiteEtd1.left += ajustePerso;
    limiteEtd1.width -= 2*ajustePerso;
    
    if (limiteEtd1.left + limiteEtd1.width > LARGURA) { // Lado direito
        pJog1->setXY(LARGURA - (limiteEtd1.width + ajustePerso + COLISAO ), limiteEtd1.top);
        pJog1->setVelocidadeX(0);

    } else if (limiteEtd1.left < 0) { // Lado esquerdo
        pJog1->setXY(COLISAO-ajustePerso, limiteEtd1.top);
        pJog1->setVelocidadeX(0);
    }
    
}

void GerenciadorColisoes::coliInimJanela(){

    long unsigned int i, tam;

    if(inimigos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector inimigos vazio" << endl;
        return;
    }

    tam = inimigos.size();
    for(i = 0; i < tam; i++){

        //lim1 = inimigos[i]->getLimites();

        lim1 = ajusteHitBoxPerso(inimigos[i]->getLimites());
        lim2 = FloatRect(-100, 0, 100, ALTURA); //esquerda

        if(verificarColisao(lim1, lim2)){
            verificarSentido(Vector2f(lim1.left, lim1.top), Vector2f(lim2.left, lim2.top));
            restauraHitBoxPerso(lim1);
            inimigoJanela(inimigos[i]);
        }
        
        lim1 = ajusteHitBoxPerso(inimigos[i]->getLimites());
        lim2 = FloatRect(LARGURA, 0, 100, ALTURA);//direita
        if(verificarColisao(lim1, lim2)){
            verificarSentido(Vector2f(lim1.left, lim1.top), Vector2f(lim2.left, lim2.top));
            restauraHitBoxPerso(lim1);
            inimigoJanela(inimigos[i]);
        }
    }

}

void Gerenciadores::GerenciadorColisoes::exibirColisoes() {
    // pJog1->exibirHitbox(lim1);
    // pJog2->exibirHitbox(lim2);
}

void GerenciadorColisoes::jogadorPlataforma(Jogador* pJog){

    //Colisao a esquerda do Personagem
    if (sentidos[0]) {
        pJog->setXY(lim1.left + (lim2.width ), lim1.top);
        pJog->setVelocidadeX(0);
  
    }
    //Colisao a direita do Personagem
    else if (sentidos[1]) {
        pJog->setXY(lim1.left - (lim2.width ), lim1.top);
        pJog->setVelocidadeX(0);
    }
    
        
    //Colisao a baixo do Personagem
    if(sentidos[2]) {
        pJog->setXY(lim1.left, lim2.top - (lim1.height));
        pJog->setVelocidadeY(0);
        pJog->setEstaPulando(false);
    }
    //Colisao a cima do Personagem
    else if(sentidos[3]) {
        pJog->setXY(lim1.left, lim2.top + (lim2.height + COLISAO));
        
        
    }

    // for (int i = 0; i < 4; i++) {

    //     cout << sentidos[i] << ", ";
    // }

    cout << endl;
    
}

void GerenciadorColisoes::jogadorAlienigena(Jogador* pJog, Inimigo* pInim){

    bool danifica = true;

    //Colisao a esquerda do Jogador
    if(sentidos[0]){
        pJog->setXY(lim2.left + (lim2.width - (2*ajustePerso) + 30), lim1.top); //30 -> macro knockback
        pInim->setVelocidadeX(0);
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJog->setXY(lim2.left - (lim1.width - (2 * ajustePerso) + 30), lim1.top);
        pInim->setVelocidadeX(0);
    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){

        pJog->setVelocidadeY(-sqrt(2.0 * GRAVIDADE * ALTURA_COLI));
        pJog->setEstaPulando(true);
        pInim->operator--();
        
        pJog->setXY(lim1.left, lim2.top - (lim1.height - ajustePerso));

        danifica = false;
    }

    if(danifica)
        pInim->danificar(pJog);
               
}

void GerenciadorColisoes::inimigoPlataforma(Inimigo* pInim){

    //Colisao a esquerda do Personagem
    if(sentidos[0]) {
        pInim->setXY(lim2.left + (lim2.width + COLISAO), lim1.top);
        pInim->atualizaVelocidade(Vector2f(-1.0, 1.0));
    }
        
    
    //Colisao a direita do Personagem
    else if(sentidos[1]) {
        pInim->setXY(lim2.left - (lim1.width + COLISAO), lim1.top);
        // pInim->atualizaVelocidade(Vector2f(-1.0, 1));
    }
    
    //Colisao a baixo do Personagem
    if(sentidos[2]){
        pInim->setXY(lim1.left, lim2.top - (lim1.height));
        pInim->setVelocidadeY(0);
        pInim->setEstaPulando(false);
    }
    //Colisao a cima do Personagem
    if(sentidos[3])
        pInim->setXY(lim1.left, lim2.top + (lim2.height));

}

void GerenciadorColisoes::inimigoJanela(Inimigo *pInim){

    //Esquerda do Inim
    if(sentidos[0]){
        pInim->setXY(lim2.left + (lim2.width), lim1.top);
        pInim->atualizaVelocidade(Vector2f(-1.2,1));
    }

    //Direita do Inim
    else if(sentidos[1]){
        pInim->setXY(lim2.left - (lim1.width), lim1.top);
        pInim->atualizaVelocidade(Vector2f(-1.2,1));
    }

}