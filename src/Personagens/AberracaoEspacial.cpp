#include "AberracaoEspacial.hpp"

Jogador* AberracaoEspacial::pJog = NULL;
Plasma* AberracaoEspacial::pPlasma = NULL;

AberracaoEspacial::AberracaoEspacial(const float x_inicial, const float y_inicial):
Inimigo(x_inicial, y_inicial),
tempRecarregar(240),
recarregando(0),
nucleo(0,0)
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
    desenharNucleo();
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

    bool danifica, pular;
    const float ajuste =  4 * (TAM_JOGADOR / 5.0f);
    FloatRect lim2, lim1, hitBox1, hitBox2;

    if(!pJ) {
        cout << "Alienigena::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
        return;
    }

    danifica = true;
    pular = true;

    lim2 = pJ->getLimites();
    lim1 = getLimites();

    hitBox2 =  hitBox();
    hitBox1 = pJ->hitBox();

    //Colisao a esquerda do Jogador
    if(sentidos[0]){
        pJ->setXY(lim2.left + (lim2.width - ajuste + KNOCK_BACK), lim1.top);
    }
        
    //Colisao a direita do Jogador
    else if(sentidos[1]){
        pJ->setXY(lim2.left - (lim1.width - ajuste + KNOCK_BACK), lim1.top);
    }

    //Colisao a baixo do Jogador
    if(sentidos[2]){
        pJ->setXY(lim1.left, hitBox2.top - (lim1.height));
    }

    if(sentidos[3]){
        
        pJ->setXY(lim1.left, hitBox2.top + (hitBox2.height));

        if(hitBox1.contains(nucleo)){
            operator--();
            danifica = false;
        }

        pular = false;
        
    }

    pJ->parar();
    parar();

    if(pular){
        pJ->setVelocidadeY(-sqrt(2.0 * gravidade * ALTURA_COLI));
        pJ->setEstaPulando(true);
    }

    if(danifica)
        pJ->operator--(maldade);
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

    distancia /= (float)PIXEL_METRO;

    tempo = sqrt(2*distancia.y / (gravidade - pPlasma->getRapidez()));

    pPlasma->setVelocidadeX(distancia.x/tempo);
    pPlasma->setAtivo(true);
    recarregando = 0;

}

void AberracaoEspacial::desenharNucleo(){

    CircleShape circulo;
    int raio;

    raio = 5;

    calcularNucleo();

    circulo.setRadius(raio);
    circulo.setPosition(nucleo.x - 2*raio, nucleo.y-2*raio);
    circulo.setFillColor(Color::Red);

    pGG->getPJanela()->draw(circulo);
}

void AberracaoEspacial::calcularNucleo(){

    FloatRect bound =  getLimites();

    nucleo = Vector2f(bound.left + bound.width/2, bound.top + bound.height);
}
