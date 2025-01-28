#include "ViajanteMau.hpp"

Jogador* ViajanteMau::pJog = NULL;

ViajanteMau::ViajanteMau(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial),
lerdeza(50),
planando(true)
{
    figura = new Figura(
        TAM_SECAO_VM, TAM_SECAO_VM, 
        QNTD_SECAO_X_VM, QNTD_SECAO_Y_VM, 
        SEC_FINAL_X_VM, SEC_FINAL_Y_VM,
        SEC_INICIAL_X_VM, SEC_INICIAL_Y_VM
    );

    // figura->setCor(Color::Red);
    carregarFigura(VIAJANTE_MAU_PATH);
    setTamanhoFigura(TAM_VIAJANTE, TAM_VIAJANTE);
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
    if(vivo){
        aplicarGravidade();
        mover();  
        atualizarFigura();
        desenhar();
    }
}

void ViajanteMau::danificar(Jogador* pJ) {
    
    bool pular, danifica;
    const float ajusteJogador = TAM_JOGADOR / 5.0f;
    FloatRect hitBoxAb, hitBoxJog;

    if(!pJ) {
        cout << "Alienigena::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
        return;
    }

    pular = true;
    danifica = true;
    
    hitBoxAb =  hitBox();
    hitBoxJog = pJ->hitBox();

    //Colisao a esquerda do Jogador
    if(sentidos[0]){
        pJ->setX(hitBoxAb.left  + (hitBoxAb.width - ajusteJogador + COLISAO));
        posicionar(x-COLISAO,y);
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJ->setX(hitBoxAb.left - (hitBoxJog.width + ajusteJogador + COLISAO));
        posicionar(x+COLISAO,y);
    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){
        pJ->setY(hitBoxAb.top - (hitBoxJog.height + ajusteJogador));
        operator--();
        danifica = false;
    }

    if(sentidos[3]){
        pJ->setY(hitBoxAb.top + (hitBoxAb.height - ajusteJogador));
        posicionar(x,y-COLISAO);
        pJ->setVelocidadeY(0);
        pular = false;
    }

    pJ->parar();
    parar();

    if(pular)
        pJ->setEstaPulando(false);

    if(danifica)
        pJ->operator--(maldade);

    planando = false;
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

    if(!planando)
        return;

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

FloatRect ViajanteMau::hitBox() const
{
    
    FloatRect lim = getLimites();
    const float ajuste = TAM_VIAJANTE / 6;
    

    lim.left += ajuste;
    lim.width -= 2 * ajuste;
    lim.top += 2*ajuste;
    lim.height -=  2* ajuste;

    return lim;
}
