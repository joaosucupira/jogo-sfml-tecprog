#include "Alienigena.hpp"

Personagens::Alienigena::Alienigena(const float x_inicial, const float y_inicial) :
Inimigo(x_inicial, y_inicial),
ricochete(ALTURA_COLI)
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
    figura->setAjuste(TAM_ALIENIGENA/5.0f);

    velocidade.x = -(VELOCIDADE_ANDAR - 0.3);
    andando = true;

}

Alienigena::~Alienigena()
{
}


void Personagens::Alienigena::executar() {
    if(vivo){
        mover();
        aplicarGravidade();
        atualizarFigura();
        desenhar();
    }
}

void Alienigena::salvar(){

    buffer.open(ALIENIGENA_SALVAR_PATH, std::ios::app);

    if(!buffer){
        cout << "Alienigena::salvar() -> erro ao abrir arquivo" << endl;
        return;
    }

    buffer << x << ' '
    << y << ' '
    << num_vidas << ' '
    << andando << ' '
    << velocidade.x << endl;

    buffer.close();
}

void Alienigena::danificar(Jogador* pJ) {

    bool danifica;
    const float ajuste =  4 * (pJ->getAjuste());
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
        x-=COLISAO;
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJ->setXY(lim2.left - (lim1.width - ajuste + KNOCK_BACK), lim1.top);
        parar();
        x+= COLISAO;

    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){
        operator--();
        parar();
        
        pJ->setXY(lim1.left, (hitBox2.top) - (lim1.height));

        danifica = false;
    }

    pJ->setVelocidadeY(-sqrt(2.0 * gravidade * ricochete));

    if(danifica)
        pJ->operator--();
               
    
}

FloatRect Alienigena::hitBox() const {
    
    FloatRect lim = getLimites();
    const float ajuste = figura->getAjuste();
    

    lim.left += ajuste;
    lim.width -= 2 * ajuste;
    lim.top += ajuste;
    lim.height -= ajuste;

    return lim;
}