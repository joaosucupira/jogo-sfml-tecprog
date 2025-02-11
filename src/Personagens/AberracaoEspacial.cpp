#include "AberracaoEspacial.hpp"

Jogador* AberracaoEspacial::pJog = NULL;
queue<Plasma*> AberracaoEspacial::plasmas;

AberracaoEspacial::AberracaoEspacial(const float x_inicial, const float y_inicial):
Inimigo(x_inicial, y_inicial),
tempRecarregar(240),
recarregando(rand()%240)
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
    figura->setAjuste(TAM_ABERRACAO / 3);

    velocidade.x = V_ABERRACAO;

    andando = true;
    num_vidas = 3;
    maldade = 3;

}

AberracaoEspacial::~AberracaoEspacial(){
}

void AberracaoEspacial::executar() {
    if(vivo){
        aplicarGravidade();
        mover();
        atirar();
        atualizarFigura();
        desenhar();
        desenharZonaSegura();
    }
}

void AberracaoEspacial::salvar(){

    buffer.open(ABERRACAO_ESPACIAL_SALVAR_PATH, std::ios::app);

    if(!buffer){
        cout << "AberracaoEspacial::salvar() -> erro ao abrir arquivo" << endl;
        return;
    }

    buffer << x << ' ' 
    << y << ' ' 
    << num_vidas << ' ' 
    << andando << ' ' 
    << velocidade.x << ' ' 
    << recarregando << endl;

    buffer.close();
}

void AberracaoEspacial::danificar(Jogador* pJ) {

    bool pular;
    const float ajusteJogador = pJ->getAjuste();
    FloatRect hitBoxAb, hitBoxJog;

    if(!pJ) {
        cout << "AberracaoEspacial::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
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
        // cout << "Vida Aberracao: " << num_vidas << endl;

        pular = false;
        
    }

    pJ->parar();

    
    if(pular){
        pJ->setVelocidadeY(-sqrt(2.0 * gravidade * ALTURA_COLI));
        pJ->setPulando(true);
    }

    if(!vivo)
       (*pJ)+= maldade;

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

    x += (velocidade.x * aux);
    y += (velocidade.y * aux);

    setPosicaoFigura(x,y);

    velocidade.y = 0;
    
}

void AberracaoEspacial::atirar(){

    Plasma* pPlasma;
    Vector2f posPlasma, posJog, distancia;
    FloatRect limJog, limAb;
    float tempo;


    if(!pJog){
        cout << "AberracaoEspacial::atirar() -> ponteiro nulo Jogador" << endl;
        return;
    }

    if(plasmas.empty()){
        cout << "AberracaoEspacial::atirar() -> ponteiro Plasma nulo" << endl;
        return;
    }

    if(!pJog->getVivo()){
        //cout << "AberracaoEspacial::atirar() -> Jogador morto" << endl;
        return;
    }

    pPlasma = recarregar();

    if(!pPlasma){
        //cout << "AberracaoEspacial::atirar() -> Plasma ativo nao encontrado" << endl;
        return;
    } 
        
    
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

Plasma* AberracaoEspacial::recarregar()
{   

    int tam;
    Plasma* pPlasma = NULL;

    if(plasmas.empty()){
        cout << "AberracaoEspacial::recarregar() -> ponteiro Plasma nulo" << endl;
        return NULL;
    }

    if(recarregando < tempRecarregar){
        recarregando++;
        return NULL;
    }
        
    
    tam = plasmas.size();

    for(int i = 0; i<tam; i++){

        pPlasma = plasmas.front();
        plasmas.pop();
        plasmas.push(pPlasma);

        if(!pPlasma->getAtivo()){
            recarregando = 0;
            pPlasma->setVelocidade(Vector2f(0,0));
            return pPlasma;
        }
            

        if(pPlasma->getX() < 0 || pPlasma->getY() < 0
        || pPlasma->getX() > LARGURA || pPlasma->getY() > ALTURA)
        {
            recarregando = 0;
            pPlasma->setVelocidade(Vector2f(0,0));
            return pPlasma;
        }
            
        pPlasma = NULL;
    }
    
    return pPlasma;
    
}

void AberracaoEspacial::desenharZonaSegura(){
    
    RectangleShape zonaSegura;
    FloatRect lim;

    if(!vivo)
        return;

    lim = hitBox();

    zonaSegura.setPosition(lim.left + 10, lim.top + lim.height);
    zonaSegura.setSize(Vector2f(lim.width - 10 ,2));
    zonaSegura.setFillColor(Color::Green);

    pGG->getPJanela()->draw(zonaSegura);
}

FloatRect AberracaoEspacial::hitBox() const
{
    FloatRect lim = getLimites();
    const float ajuste = figura->getAjuste();
    

    lim.left += ajuste;
    lim.width -= 2 * ajuste;
    lim.top += ajuste;
    lim.height -= 2*ajuste;

    return lim;
}

void AberracaoEspacial::setPJog(Jogador *pJ){
    if(pJ)
        pJog = pJ;
    else
        cout << "void AberracaoEspacial::setPJog() -> ponteiro nulo." << endl;
}

void AberracaoEspacial::incluiPlasma(Plasma* pPlas){
    if(pPlas)
        plasmas.push(pPlas);
    else
        cout << "AberracaoEspacial::incluiPlasma(Plasma* pPlas) -> ponteiro nulo" << endl;
}

void Personagens::AberracaoEspacial::limparPlasmas()
{
    while(!plasmas.empty())
        plasmas.pop();
}
