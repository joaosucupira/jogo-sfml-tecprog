#include "Portal.hpp"

Portal::Portal(const float x_inicial, const float y_inicial) : 
Obstaculo(x_inicial, y_inicial),
raio(100.0f)
{
    figura = new Figura(
        PORTAL_LADO, PORTAL_LADO,
        8, 1,
        224, 0,
        0, 0
    );

    carregarFigura(PORTAL_PATH);
    setTamanhoFigura(TAM_PORTAL, TAM_PORTAL),
    setPosicaoFigura(x_inicial, y_inicial);
    figura->setAjuste(ALT_PLATAFORMA / 10.0f);
}

Portal::~Portal(){
}

void Portal::executar() {
    desenhar();
    atualizarFigura();
    gravitar();
}

void Portal::salvar(){
    
    buffer.open(PORTAL_SALVAR_PATH, std::ios::app);

    if(!buffer){
        cout << "Portal::salvar()-> Erro ao abrir o arquivo" << endl;
        return;
    }

    buffer << x << ' '
    << y << endl;
    buffer.close();
}

void Portal::obstacular(Jogador *pJ) {
    if (!pJ) {
        cout << "void Portal::obstacular(Jogador *pJ) -> ponteiro nulo" << endl;
        return;
    }
    
    if (abs(getLimites().left - pJ->getLimites().left) <= raio &&
        abs(getLimites().top - pJ->getLimites().top <= raio)) {

        pJ->operator--();
        teletransportar(pJ);
        // cout << "Vida Jogador:" << pJ->getVidas() << endl;
    }
}

void Portal::teletransportar(Jogador* pJ) {
    if (!pJ) {
        cout << "void Portal::teletransportar(Jogador * pJ) -> ponteiro nulo" << endl;
        return;
    }

    pJ->setXY(LARG_PLATAFORMA * 2, ALTURA - (LARG_PLATAFORMA * 2));
}
