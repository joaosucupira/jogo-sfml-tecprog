#include "AberracaoEspacial.hpp"

Jogador* AberracaoEspacial::pJog = NULL;
Plasma* AberracaoEspacial::pPlasma = NULL;

AberracaoEspacial::AberracaoEspacial(const float x_inicial, const float y_inicial):
Inimigo(x_inicial, y_inicial),
tempRecarregar(60),
recarregando(0)
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

void AberracaoEspacial::setPPlasma(Plasma* pPlas){
    if(pPlas)
        pPlasma = pPlas;
    else
        cout << "AberracaoEspacial::setPPlasma(Plasma* pPlas) -> ponteiro nulo" << endl;
}


void AberracaoEspacial::executar() {
    aplicarGravidade();
    mover();
    atirar();
    atualizarFigura();
    desenhar();
}

void AberracaoEspacial::mover(){

    if(!pGG){
        cout<< "AberracaoEspacial::mover()-> ponteiro gGrafico nulo" << endl;
        return;
    }

    planar();

    x += velocidade.x *  PIXEL_METRO * pGG->getDeltaTime();
    y += velocidade.y *  PIXEL_METRO * pGG->getDeltaTime();

    setPosicaoFigura(x,y);

    velocidade.y = 0;
    //move o plasma !!!
}

void AberracaoEspacial::danificar(Jogador* pJ) {

    if(pJ){
        pJ->operator--(maldade);
    }
    else
        cout << "AberracaoEspacial::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
}

void AberracaoEspacial::salvaDataBuffer() {
}

void AberracaoEspacial::planar(){

     float aux;

    if(!pGG){
        cout << "AberracaoEspacial::planar() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = GRAVIDADE * pGG->getDeltaTime();

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
        cout << "AberracaoEspacial::atirar() -> Jogador morto" << endl;
        return;
    }
    
    if(pPlasma->getAtivo())
        return;

    if(recarregando < tempRecarregar){
        recarregando++;
        return;
    }
        
    
    limAb = getLimites();
    pPlasma->setXY(limAb.left + limAb.width /2, limAb.top + limAb.height );
    posPlasma = Vector2f(pPlasma->getX(), pPlasma->getY());
    
    limJog = pJog->getLimites();
    posJog = Vector2f(limJog.left + limJog.width/ 2, limJog.top + limJog.height / 2);

    distancia = posJog - posPlasma;

    distancia *= (float)PIXEL_METRO;

    tempo = sqrt(2*distancia.y / GRAVIDADE);

    //pPlasma->setVelocidadeX(distancia.x/tempo);
    pPlasma->setAtivo(true);
    recarregando = 0;
    

}
