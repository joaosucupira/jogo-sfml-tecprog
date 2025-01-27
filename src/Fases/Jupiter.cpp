
#include "Jupiter.hpp"

Jupiter::Jupiter() : Fase(),
maxAberracoesEspaciais(0)
{
    gravidade = 9.8f;
    figura = new Figura(
        2819, 1589,
        1,1,
        0,0,
        0,0
    );
    carregarFigura();
    figura->setTamanho(1309, 736);
    criarObstaculos();
    criarAlienigenas();
}

Fases::Jupiter::~Jupiter()
{
}

void Fases::Jupiter::criarObstaculos() {
    criarPilares();
    criarPortais();
    criarBuracosNegros();
    criarViajantesMaus();
    criarAberracoesEspaciais();
    criarPlasmas();
}

void Fases::Jupiter::criarPortais() {
    Portal* pP = NULL;

    for (int i = 1; i < 4; i++) {
        pP = new Portal(250.0f * i, ALTURA - ALT_PLATAFORMA * 2 - 150.0f);
        if (pP) {
            if (i == 2) {
                continue;
            }
            else {

                entidades->adiciona(static_cast<Entidade*>(pP));
                GC.incluirObst(static_cast<Obstaculo*>(pP));
            }
        }
        pP = NULL;
    }
    if (pP) delete pP;
    pP = NULL;
}

void Fases::Jupiter::carregarFigura() {
    if (figura) {
        figura->carregarTextura(JUPITER_PATH);
    }
}

void Fases::Jupiter::criarBuracosNegros(){
    BuracoNegro* pB = NULL;

    for (int i = 1; i < 4; i++) {
        pB = new BuracoNegro(215.0f * i, ALTURA - ALT_PLATAFORMA * 2 - 240.0f);
        if (pB) {
            if (i == 2) {
                entidades->adiciona(static_cast<Entidade*>(pB));
                GC.incluirObst(static_cast<Obstaculo*>(pB));
            }

        }
        pB = NULL;
    }
    if (pB) delete pB;
    pB = NULL;
}

void Fases::Jupiter::criarAlienigenas() {
    Alienigena* pA = NULL;
    const int max = 1;

    for (int i = 0; i < max; i++) {
        pA = new Alienigena(
            LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - i * 400.0f,
            10.0f
        );

        entidades->adiciona(static_cast<Entidade*>(pA));
        GC.incluirInim(static_cast<Inimigo*>(pA));
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Jupiter::criarAberracoesEspaciais(){
    AberracaoEspacial* pAB = NULL;

    pAB = new AberracaoEspacial(LARGURA/2,1);
    if(pAB){
        entidades->adiciona(static_cast<Entidade*>(pAB));
        GC.incluirInim(static_cast<Inimigo*>(pAB));
    }
    else
        cout<< "Fase::criarAberracoesEspaciais() -> Erro na alocacao dinamica" << endl;

}

void Jupiter::criarPlasmas() {
    Plasma* pPla = NULL;

    pPla = new Plasma(0,0);

    if(pPla){
        entidades->adiciona(static_cast<Entidade*>(pPla));
        GC.incluirPlas(pPla);
        AberracaoEspacial::setPPlasma(pPla);
    }
    else
        cout<< "Fase::criarAberracoesEspaciais() -> Erro na alocacao dinamica" << endl;


}

void Jupiter::criarViajantesMaus(){
    ViajanteMau* pVM = NULL;
    pVM = new ViajanteMau(LARGURA/2,0);
    if(pVM){
        entidades->adiciona(static_cast<Entidade*>(pVM));
        GC.incluirInim(static_cast<Inimigo*>(pVM));
    }
    else
        cout<< "Fase::criarViajantesMaus() -> Erro na alocacao dinamica" << endl;
}


void Fases::Jupiter::criarPilares()
{
}
