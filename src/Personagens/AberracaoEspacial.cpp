#include "AberracaoEspacial.hpp"

Jogador* AberracaoEspacial::pJog = NULL;
Plasma* AberracaoEspacial::pPlasma = NULL;

AberracaoEspacial::AberracaoEspacial(const float x_inicial, const float y_inicial):
Inimigo(x_inicial, y_inicial),
tempRecarregar(240),
recarregando(rand()%120)
{
    figura = new Figura(
        TAM_SECAO_AE, TAM_SECAO_AE, 
        QNTD_SECAO_X_AE, QNTD_SECAO_Y_AE, 
        SEC_FINAL_X_AE, SEC_FINAL_Y_AE,
        SEC_INICIAL_X_AE, SEC_INICIAL_Y_AE
    );


    carregarFigura(ABERRACAO_ESPACIAL_PATH);
    setTamanhoFigura(TAM_ABERRACAO, TAM_ABERRACAO);
    setPosicaoFigura(x, y);

    velocidade.x = -(VELOCIDADE_ANDAR + 0.5);

    estaAndando = true;
    num_vidas = 5;
    maldade = 3;

}

AberracaoEspacial::~AberracaoEspacial()
{
}

void AberracaoEspacial::setPJog(Jogador *pJ){
    if(pJ)
        pJog = pJ;
    else
        cout << "void AberracaoEspacial::setPJog() -> ponteiro nulo." << endl;
}

void AberracaoEspacial::setPPlasma(Plasma* pPlas){
    if(pPlas)
        pPlasma = pPlas;
    else
        cout << "AberracaoEspacial::setPPlasma(Plasma* pPlas) -> ponteiro nulo" << endl;
}


void AberracaoEspacial::executar() {
    if(vivo){
        aplicarGravidade();
        mover();
        atirar();
        recarregar();
        atualizarFigura();
        desenhar();
        desenharZonaSegura();
    }
}

void AberracaoEspacial::mover(){

    float aux;

    if(!pGG){
        cout<< "AberracaoEspacial::mover()-> ponteiro gGrafico nulo" << endl;
        return;
    }

    planar();

    aux = pGG->getDeltaTime();
    aux *= PIXEL_METRO;

    x += velocidade.x * aux;
    y += velocidade.y * aux;

    setPosicaoFigura(x,y);

    velocidade.y = 0;
    
}

void AberracaoEspacial::danificar(Jogador* pJ) {

    bool pular;
    const float ajusteJogador = TAM_JOGADOR / 5.0f;
    FloatRect hitBoxAb, hitBoxJog;

    if(!pJ) {
        cout << "Alienigena::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
        return;
    }

    pular = true;

    
    hitBoxAb =  hitBox();
    hitBoxJog = pJ->hitBox();

    //Colisao a esquerda do Jogador
    if(sentidos[0]){
        pJ->setX(hitBoxAb.left  + (hitBoxAb.width - ajusteJogador + KNOCK_BACK));
        atualizaVelocidade(Vector2f(-1.0,1.0));
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJ->setX(hitBoxAb.left - (hitBoxJog.width + ajusteJogador + KNOCK_BACK));
        atualizaVelocidade(Vector2f(-1.0,1.0));
    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){
        pJ->setY(hitBoxAb.top - (hitBoxJog.height + ajusteJogador));
    }

    if(sentidos[3]){
        
        pJ->setY(hitBoxAb.top + (hitBoxAb.height - ajusteJogador));
        
        operator--();
        cout << "Vida Aberracao: " << num_vidas << endl;

        pular = false;
        
    }

    pJ->parar();

    
    if(pular){
        pJ->setVelocidadeY(-sqrt(2.0 * gravidade * ALTURA_COLI));
        pJ->setEstaPulando(true);
    }
}

void AberracaoEspacial::salvaDataBuffer() {
}

void AberracaoEspacial::planar(){

    float aux;

    if(!pGG){
        cout << "AberracaoEspacial::planar() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = gravidade * pGG->getDeltaTime();

    velocidade.y -= aux;
        
}

void AberracaoEspacial::atirar(){

    Vector2f posPlasma, posJog, distancia;
    FloatRect limJog, limAb;
    float tempo;


    if(!pJog){
        cout << "AberracaoEspacial::atirar() -> ponteiro nulo Jogador" << endl;
        return;
    }

    if(!pPlasma){
        cout << "AberracaoEspacial::atirar() -> ponteiro Plasma nulo" << endl;
        return;
    }

    if(!pJog->getVivo()){
        //cout << "AberracaoEspacial::atirar() -> Jogador morto" << endl;
        return;
    }
    
    if(pPlasma->getAtivo())
        return;
        
    
    limAb = getLimites();
    pPlasma->setXY(limAb.left + limAb.width /2, limAb.top + limAb.height );
    posPlasma = Vector2f(pPlasma->getX(), pPlasma->getY());
    
    limJog = pJog->getLimites();
    posJog = Vector2f(limJog.left + limJog.width/ 2, limJog.top + limJog.height / 2);

    distancia = posJog - posPlasma;

    distancia /= (float)PIXEL_METRO;

    tempo = sqrt(2*distancia.y / (gravidade - pPlasma->getRapidez()));

    if(tempo < 0.75)
        tempo = 0.75;

    pPlasma->setVelocidadeX(distancia.x/tempo);
    pPlasma->setAtivo(true);

}

void AberracaoEspacial::recarregar()
{
    recarregando++;
    if(recarregando > tempRecarregar){
        pPlasma->setAtivo(false);
        pPlasma->setVelocidade(Vector2f(0,0));
        recarregando = 0;
    }
}

void AberracaoEspacial::desenharZonaSegura(){
    
    RectangleShape zonaSegura;
    FloatRect lim;

    if(!vivo)
        return;

    lim = hitBox();

    zonaSegura.setPosition(lim.left, lim.top + lim.height);
    zonaSegura.setSize(Vector2f(lim.width,0.5));
    zonaSegura.setFillColor(Color::Green);

    pGG->getPJanela()->draw(zonaSegura);
}

FloatRect AberracaoEspacial::hitBox() const
{
    FloatRect lim = getLimites();
    const float ajuste = TAM_ABERRACAO / 3;
    

    lim.left += ajuste;
    lim.width -= 2 * ajuste;
    lim.top += ajuste;
    lim.height -= 2*ajuste;

    return lim;
}
