#include "Alienigena.hpp"

Personagens::Alienigena::Alienigena(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial)
{
    figura = new Figura(
        TAM_SECAO_ALI, TAM_SECAO_ALI, 
        QNTD_SECAO_X_ALI, QNTD_SECAO_Y_ALI, 
        SEC_FINAL_X_ALI, SEC_FINAL_Y_ALI,
        SEC_INICIAL_X_ALI, SEC_INICIAL_Y_ALI
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
    if(!pJ) {
        cout << "Alienigena::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
        return;
    }

    bool danifica = true;
    const float ajuste = 2 * (TAM_JOGADOR / 5.0f) + KNOCK_BACK;

    FloatRect lim2 = pJ->getLimites();
    FloatRect lim1 = this->getLimites();


    //Colisao a esquerda do Jogador
    if(sentidos[0]){
        pJ->setXY(lim2.left + (lim2.width + KNOCK_BACK), lim1.top); 
        parar();
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJ->setXY(lim2.left - (lim1.width + KNOCK_BACK), lim1.top);
        parar();

    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){

        pJ->setVelocidadeY(-sqrt(2.0 * GRAVIDADE * ALTURA_COLI));
        pJ->setEstaPulando(true);
        operator--();
        parar();
        
        pJ->setXY(lim1.left, lim2.top - (lim1.height - ajuste));

        danifica = false;
    }

    if(danifica)
        pJ->operator--();
               
    
}

void Personagens::Alienigena::salvaDataBuffer() {
}

