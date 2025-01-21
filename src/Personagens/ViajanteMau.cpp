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
    carregarFigura();
    setTamanhoFigura(TAM_JOGADOR, TAM_JOGADOR);
    setPosicaoFigura(x, y);
    estaAndando = true;
    

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

void ViajanteMau::carregarFigura() {
    if (figura) {
        figura->carregarTextura(ViajanteMau_PATH);
    } else { cout << "void ViajanteMau::carregarFigura() -> ponteiro nulo." << endl; }
}


void ViajanteMau::executar() {
    seguirJogador();
    mover();
    planar();
    aplicarGravidade();
    atualizarFigura();
    pGG->desenharEnte(this);
}

void ViajanteMau::danificar(Jogador* pJ) {
    if(pJ)
        pJ->operator--();
    else
        cout << "ViajanteMau::danificar(Jogador* pJ) -> ponteiro nulo jogador" << endl;
}

void ViajanteMau::salvaDataBuffer() {
}

void ViajanteMau::seguirJogador(){

    if(!pJog){
        cout << "ViajanteMau::seguirJogador() -> ponteiro nulo Jogador" << endl;
        return;
    }

    if(!pJog->getVivo()){
        cout << "ViajanteMau::seguirJogador() -> Jogador" << endl;
        return;
    }

    if(!estaAndando)
        return;

    Vector2f viaMau(x,y), jog(pJog->getX() + lerdeza , pJog->getY() + lerdeza), res;
    float modulo;

    res = jog - viaMau;
    modulo = sqrt(res.x*res.x + res.y*res.y);

    if(modulo > 0)
        res /= modulo;
    else{
        cout << "Divisao por zero ou modulo negativo" << endl;
        return;
    }

    res *= (float)V_VIAJANTE;

    velocidade.x = res.x;
    velocidade.y += res.y;

    
}

void ViajanteMau::planar(){

    velocidade.y = - (GRAVIDADE * pGG->getDeltaTime());
        
}

