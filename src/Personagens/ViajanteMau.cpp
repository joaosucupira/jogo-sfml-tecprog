#include "ViajanteMau.hpp"

Jogador* ViajanteMau::pJog = NULL;

ViajanteMau::ViajanteMau(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial),
lerdeza(50)
{
    figura = new Figura(
        TAM_SECAO_VM, TAM_SECAO_VM, 
        QNTD_SECAO_X_VM, QNTD_SECAO_Y_VM, 
        SEC_FINAL_X_VM, SEC_FINAL_Y_VM,
        SEC_INICIAL_X_VM, SEC_INICIAL_Y_VM
    );

    // figura->setCor(Color::Red);
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
    
    int i;

    if(pJ){

        for(i=0; i<maldade; i++)
            pJ->operator--();
    }
        
    else
        cout << "ViajanteMau::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
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
        cout << "ViajanteMau::seguirJogador() -> Jogador morto" << endl;
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

    aux = GRAVIDADE * pGG->getDeltaTime();

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

