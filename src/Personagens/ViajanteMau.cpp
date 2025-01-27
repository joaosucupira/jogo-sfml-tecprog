#include "ViajanteMau.hpp"

Jogador* ViajanteMau::pJog = NULL;

ViajanteMau::ViajanteMau(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial),
lerdeza(50)
{
    figura = new Figura(
        TAM_SECAO, TAM_SECAO, 
        QNTD_SECAO_X, QNTD_SECAO_Y, 
        SEC_FINAL_X, SEC_FINAL_Y,
        SEC_INICIAL_X, SEC_INICIAL_Y
    );

    figura->setCor(Color::Red);
    carregarFigura(VIAJANTE_MAU_PATH);
    setTamanhoFigura(TAM_JOGADOR, TAM_JOGADOR);
    setPosicaoFigura(x, y);

    estaAndando = true;
    num_vidas = 0;
    maldade = 1;

}

ViajanteMau::~ViajanteMau()
{
}

void ViajanteMau::setPJog(Jogador *pJ){
    if(pJ)
        pJog = pJ;
    else
        cout << "void ViajanteMau::setPJog() -> ponteiro nulo." << endl;
}


void ViajanteMau::executar() {
    aplicarGravidade();
    mover();  
    atualizarFigura();
    desenhar();
}

void ViajanteMau::danificar(Jogador* pJ) {
    
    bool danifica;
    const float ajuste =  4 * (TAM_JOGADOR / 5.0f);
    FloatRect lim2, lim1, hitBox2;

    if(!pJ) {
        cout << "Alienigena::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
        return;
    }

    danifica = true;

    lim2 = pJ->getLimites();
    lim1 = getLimites();
    hitBox2 =  hitBox();

    //Colisao a esquerda do Jogador
    if(sentidos[0]){
        pJ->setXY(lim2.left + (lim2.width - ajuste + COLISAO), lim1.top);
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJ->setXY(lim2.left - (lim1.width - ajuste + COLISAO), lim1.top);
    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){

        pJ->setXY(lim1.left, hitBox2.top - (lim1.height));

        operator--();
        danifica = false;
    }

    if(sentidos[3]){
        
        pJ->setXY(lim1.left, hitBox2.top + (hitBox2.height));
        posicionar(x,y-COLISAO);
    }

    pJ->parar();
    parar();

    pJ->setEstaPulando(false);

    if(danifica)
        pJ->operator--(maldade);
}

void ViajanteMau::salvaDataBuffer() {
}

void ViajanteMau::seguirJogador(){

    Vector2f posViaMau, posJog, velocidadeRes;
    float moduloVelocidade;

    if(!pJog){
        cout << "ViajanteMau::seguirJogador() -> ponteiro nulo Jogador" << endl;
        return;
    }

    if(!pJog->getVivo()){
        //cout << "ViajanteMau::seguirJogador() -> Jogador morto" << endl;
        return;
    }

    if(!estaAndando)
        return;

    //Aplicando relação bionivica de ponto e vetor
    posViaMau = Vector2f(x,y);
    posJog = Vector2f(pJog->getX() - lerdeza , pJog->getY() - lerdeza);

    velocidadeRes = posJog - posViaMau; //vetor com direcao e sentido da velocidade do viajante mau

    //normalizando o vetor velocidade, calculando o versor
    moduloVelocidade = sqrt(velocidadeRes.x*velocidadeRes.x + velocidadeRes.y*velocidadeRes.y);
    if(moduloVelocidade > 0)
        velocidadeRes /= moduloVelocidade;
    else{
        cout << "Divisao por zero ou modulo negativo" << endl;
        return;
    }

    velocidadeRes *= (float)V_VIAJANTE; //aplicando o módulo correto para a velocidade

    //atualizando velocidade
    velocidade.x += velocidadeRes.x;
    velocidade.y += velocidadeRes.y;

}

void ViajanteMau::planar(){

    float aux;

    if(!pGG){
        cout << "ViajanteMau::planar() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = gravidade * pGG->getDeltaTime();

    velocidade.y -= aux;
        
}

void ViajanteMau::mover(){

    float aux;

    if(!pGG){
        cout<< "ViajanteMau::mover()-> ponteiro gGrafico nulo" << endl;
        return;
    }

    planar();
    seguirJogador();

    aux = pGG->getDeltaTime();
    aux *= PIXEL_METRO;

    x += velocidade.x * aux;
    y += velocidade.y * aux;

    setPosicaoFigura(x,y);

    velocidade.y = 0;
    velocidade.x = 0;
}

