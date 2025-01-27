
#include "Jupiter.hpp"

Jupiter::Jupiter() : Fase(),
maxAberracoesEspaciais(0)
{
    gravidade = 1.2f;
    figura = new Figura(
        2819, 1589,
        1,1,
        0,0,
        0,0
    );
    carregarFigura();
    figura->setTamanho(1309, 736);
    criarObstaculos();
    // criarAlienigenas();
}

Fases::Jupiter::~Jupiter()
{
}

void Fases::Jupiter::criarObstaculos() {
    criarSuportes();
    // criarPortais();
    criarBuracosNegros();
    criarViajantesMaus();
    criarAberracoesEspaciais();
    criarPlasmas();
    colorirPlataformas();
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
    int max = 3;  

    for (int i = 0; i < max; i++) {
        pB = new BuracoNegro((LARGURA / 2.5f) * i, ALTURA - ALT_PLATAFORMA * 2 - 150.0f);
        if (pB) {
            entidades->adiciona(static_cast<Entidade*>(pB));
            GC.incluirObst(static_cast<Obstaculo*>(pB));
        

        }
        pB = NULL;
    }

    max = rand() % 4;
    for (int i = 0; i < max; i++) {
        pB = new BuracoNegro((LARGURA / 2.5f) * i, ALT_PLATAFORMA * 2 - 150.0f);
        if (pB) {
            entidades->adiciona(static_cast<Entidade*>(pB));
            GC.incluirObst(static_cast<Obstaculo*>(pB));
        

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

    pAB = new AberracaoEspacial(1, 80.0f);
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
    const int max = rand() % 5 + 3;
    const float distancia = 80.0f;

    for (int i = 1; i < max + 1; i++) {
        pVM = new ViajanteMau(LARGURA - LARG_PLATAFORMA, (i * distancia));
        if(pVM) {
            entidades->adiciona(static_cast<Entidade*>(pVM));
            GC.incluirInim(static_cast<Inimigo*>(pVM));
        }
        pVM = NULL;
    }

    if (pVM) delete pVM;
    pVM = NULL;

}

void Fases::Jupiter::colorirPlataformas() {
    Entidade* pE = NULL;
    for (int i = 0; i < entidades->getTamanho(); i++) {
        pE = (*entidades)[i];
        if (pE && dynamic_cast<Plataforma*>(pE)) {
            pE->setCorFigura(Color::Red);
        } 
    }
}

void Fases::Jupiter::criarSuportes() {
    const int max = rand() % 2 + 2;
    const float tamanho_plano = LARGURA / 10.0f;

    for (int i = 1; i < max; i++) {
        for(int j = 0; j < 5; j++) {
            construirPlano(tamanho_plano, Vector2f(i * 380.0f, ALTURA - (ALT_PLATAFORMA) * j));
        }
    }
}
