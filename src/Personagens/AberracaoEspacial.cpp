#include "AberracaoEspacial.hpp"

Jogador* AberracaoEspacial::pJog = NULL;

AberracaoEspacial::AberracaoEspacial(const float x_inicial, const float y_inicial):
Inimigo(x_inicial, y_inicial)
{
    figura = new Figura(
        TAM_SECAO, TAM_SECAO, 
        QNTD_SECAO_X, QNTD_SECAO_Y, 
        SEC_FINAL_X, SEC_FINAL_Y,
        SEC_INICIAL_X, SEC_INICIAL_Y
    );

    figura->setCor(Color::Yellow);
    carregarFigura(ABERRACAO_ESPACIAL_PATH);
    setTamanhoFigura(TAM_JOGADOR + 50, TAM_JOGADOR + 50);
    setPosicaoFigura(x, y);

    velocidade.x = -(VELOCIDADE_ANDAR + 0.5);
    setEstaAndando(true);

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


void AberracaoEspacial::executar() {
    
    planar();
    aplicarGravidade();
    
    mover();

    atualizarFigura();
    pGG->desenharEnte(this);
}

void AberracaoEspacial::mover(){
    x += velocidade.x *  PIXEL_METRO * pGG->getDeltaTime();
    y += velocidade.y *  PIXEL_METRO * pGG->getDeltaTime();

    setPosicaoFigura(x,y);
    //move o plasma !!!
}

void AberracaoEspacial::danificar(Jogador* pJ) {

    int i;

    if(pJ){

        for(i=0; i<maldade; i++)
            pJ->operator--();
    }
        
    else
        cout << "AberracaoEspacial::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
}

void AberracaoEspacial::salvaDataBuffer() {
}

void AberracaoEspacial::planar(){

    //aplicando a velocidade para superar a gravidade (voar)
    velocidade.y = - (GRAVIDADE * pGG->getDeltaTime());
        
}
