#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes() :
pJog1(NULL),
pJog2(NULL),
obstaculos(),
inimigos(),
plasmas()
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
    plasmas.clear();
}

void GerenciadorColisoes::executar() {

    coliJogObstaculo();
    coliInimObstaculo();
    coliJogInimigo();
    coliJogPlasma();

}

void GerenciadorColisoes::setPJog1(Jogador *pJ1) {
    if (pJ1)
        pJog1 = pJ1;
    else
        { cout << "GerenciadorColisoes::setPJogador(Jogador *pJ1) -> ponteiro nulo." << endl; };
}

void Gerenciadores::GerenciadorColisoes::setPJog2(Jogador *pJ2) {
    if (pJ2) {
        pJog2 = pJ2;
    } else {
        { cout << "GerenciadorColisoes::setPJog2(Jogador *pJ2) -> ponteiro nulo." << endl; };

    }
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
        plasmas.insert(pPlas);
    else
        cout << "GerenciadorColisoes::incluirPlas(Plasma* pPlas) -> ponteiro plasma nulo" << endl;
}

const int GerenciadorColisoes::getInimigosVivos() {
    int cont = 0;
    list<Inimigo*>::iterator it;
    
    for(it = inimigos.begin(); it != inimigos.end(); it++){
        if ((*it)) {
            if ((*it)->getVivo()) {
                cont++;
            }
        }
    }
    return cont;
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

    const int margem = 0;

    for (int i = 0; i < 4; i++) {
        sentidos[i] = 0;
    }

    //Verificação do sentido de colisão em realcao ao personagem
    if (resultante.x < resultante.y && resultante.x > margem) {

        if ( pos1.x > pos2.x )
            sentidos[0] = 1; //Esquerda do Personagem
        else if ( pos1.x < pos2.x )
            sentidos[1] = 1; //Direita do Personagem

    }

    else if( resultante.y < resultante.x) {

        if ( pos1.y > pos2.y)
            sentidos[3] = 1; //Baixo do Personagem

        else if(pos1.y < pos2.y)
            sentidos[2] = 1; //Cima do Personagem
        
    }
}

void Gerenciadores::GerenciadorColisoes::separarEntidades(Entidade *pE1, Entidade *pE2)
{
    const float ajuste = pE2->getAjuste();

    FloatRect hitBox1, hitBox2;

    hitBox1 = pE1->hitBox();
    hitBox2 = pE2->hitBox();

    //Esquerda do Personagem
    if(sentidos[0])
        pE2->setX(hitBox1.left  + (hitBox1.width - ajuste + COLISAO));
    
    //Direita do Personagem
    if(sentidos[1])
        pE2->setX(hitBox1.left - (hitBox2.width + ajuste + COLISAO));

    //Baixo do Personagem
    if(sentidos[2])
        pE2->setY(hitBox1.top - (hitBox2.height + ajuste));

    //Cima do Personagem
    if(sentidos[3])
        pE2->setY(hitBox1.top + (hitBox1.height - ajuste));
    
}

void GerenciadorColisoes::coliJogObstaculo(){
    
    unsigned int i;
    const unsigned int tam = obstaculos.size();
    //Acoplar segundo jogador depois

    if(!pJog1){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> pJog1 nulo" << endl;
        return;
    }

    if(obstaculos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    if(pJog1->getVivo()) {

        for(i = 0; i < tam; i++) {
            if(verificarColisao(pJog1, obstaculos[i])) {
                verificarSentido(pJog1, obstaculos[i]);

                obstaculos[i]->setSentidos(sentidos);

                obstaculos[i]->obstacular(pJog1);

            }
        }
    }



    if (pJog2 && pJog2->getVivo()) {

        for (i = 0; i < tam; i++) {
            if (verificarColisao(pJog2, obstaculos[i])) {
                verificarSentido(pJog2, obstaculos[i]);

                obstaculos[i]->setSentidos(sentidos);
                obstaculos[i]->obstacular(pJog2);
            }
        }
    }
}

void GerenciadorColisoes::coliJogInimigo(){

    list<Inimigo*>::iterator it;

    if(!pJog1 && !pJog2){
        cout << "GerenciadorColisoes::coliJogInimigo() -> nenhum jogador configurado" << endl;
        return;
    }

    if(inimigos.empty()){
        // cout << "GerenciadorColisoes::coliJogInimigo() -> vector inimigos vazio" << endl;
        return;
    }

    if(pJog1->getVivo()) {
        
        for(it = inimigos.begin(); it != inimigos.end(); it++){

            if((*it)->getVivo()){

                if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it)) ){
                    
                    verificarSentido(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it));

                    (*it)->setSentidos(sentidos);
                    (*it)->danificar(pJog1);
                    notificarObservadores(); // Padrãp observer

                    // cout << "Vida jogador 1: " << pJog1->getVidas() << endl;
                }   
            }
        }
    }

    if (pJog2 && pJog2->getVivo()) {

        for(it = inimigos.begin(); it != inimigos.end(); it++){

            if((*it)->getVivo()){

                if(verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it)) ){
                    
                    verificarSentido(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it));

                    (*it)->setSentidos(sentidos);
                    (*it)->danificar(pJog2);
                    notificarObservadores();

                    // cout << "Vida jogador 2: " << pJog2->getVidas() << endl;
                }   
            }
        }
    }


}

void GerenciadorColisoes::coliInimObstaculo(){
    
    unsigned int i;
    const unsigned int tamObs = obstaculos.size();
    list<Inimigo*>::iterator it;

    //Acoplar segundo jogador depois

    if(inimigos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector inimigos vazio" << endl;
        return;
    }

    if(obstaculos.empty()){
        // cout << "GerenciadorColisoes::coliJogObstaculo() -> vector obstaculos vazio" << endl;
        return;
    }

    for(it = inimigos.begin(); it != inimigos.end(); it++){
        
        if((*it)->getVivo()){

            for(i = 0; i < tamObs; i++){


                if(verificarColisao( static_cast<Entidade*>(*it) , static_cast<Entidade*>(obstaculos[i]) ) ) {
                    verificarSentido(static_cast<Entidade*>(*it), static_cast<Entidade*>(obstaculos[i]));

                    obstaculos[i]->setSentidos(sentidos);
                    obstaculos[i]->obstacular((*it));

                }
                    
            }

        }
    }
}

void GerenciadorColisoes::coliJogPlasma(){

    set<Plasma*>::iterator it;

    if(!pJog1){
        // cout << "GerenciadorColisoes::coliJogInimigo() -> pJog1 nulo" << endl;
        return;
    }

    if(plasmas.empty()){
        // cout << "GerenciadorColisoes::coliJogInimigo() -> vector inimigos vazio" << endl;
        return;
    }

    if(pJog1->getVivo()){

        for(it = plasmas.begin(); it != plasmas.end(); it++){

            if((*it)->getAtivo()){

                if(verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))){
                    (*it)->queimar(pJog1);
                    cout << "Vida jogador 1: " << pJog1->getVidas() << endl;
                }   
            }
        }
    }

    if(!pJog2){
        // cout << "GerenciadorColisoes::coliJogInimigo() -> pJog2 nulo" << endl;
        return;
    }

    if(pJog2->getVivo()){

        for(it = plasmas.begin(); it != plasmas.end(); it++){

            if((*it)->getAtivo()){

                if(verificarColisao(static_cast<Entidade*>(pJog2), static_cast<Entidade*>(*it))){
                    (*it)->queimar(pJog2);
                    cout << "Vida jogador 2: " << pJog2->getVidas() << endl;
                }   
            }
        }
    }
}