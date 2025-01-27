#include "Alienigena.hpp"

Personagens::Alienigena::Alienigena(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial)
{
    figura = new Figura(
        TAM_SECAO, TAM_SECAO, 
        QNTD_SECAO_X, QNTD_SECAO_Y, 
        SEC_FINAL_X, SEC_FINAL_Y,
        SEC_INICIAL_X, SEC_INICIAL_Y
    );
    // figura->setCor(Color::Red);
    carregarFigura(ALIENIGENA_PATH);
    setTamanhoFigura(TAM_JOGADOR, TAM_JOGADOR);
    setPosicaoFigura(x, y);

    velocidade.x = -(VELOCIDADE_ANDAR - 0.3);
    setEstaAndando(true);

}

Alienigena::~Alienigena()
{
}


void Personagens::Alienigena::executar() {
    mover();
    aplicarGravidade();
    atualizarFigura();
    desenhar();
}

void Alienigena::danificar(Jogador* pJ) {

    bool danifica;
    const float ajuste =  4 * (TAM_JOGADOR / 5.0f);
    FloatRect lim2, lim1, hitBox2;

    if(!pJ) {
        cout << "Alienigena::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
        return;
    }

    danifica = true;

    lim2 = pJ->getLimites();
    lim1 = this->getLimites();
    hitBox2 =  hitBox();

    //Colisao a esquerda do Jogador
    if(sentidos[0]){
        pJ->setXY(lim2.left + (lim2.width - ajuste + KNOCK_BACK), lim1.top);
        parar();
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJ->setXY(lim2.left - (lim1.width - ajuste + KNOCK_BACK), lim1.top);
        parar();

    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){
        operator--();
        parar();
        
        pJ->setXY(lim1.left, (hitBox2.top) - (lim1.height));

        danifica = false;
    }

    pJ->setVelocidadeY(-sqrt(2.0 * gravidade * ALTURA_COLI));

    if(danifica)
        pJ->operator--();
               
    
}

void Personagens::Alienigena::salvaDataBuffer() {
}

