
#include "Jupiter.hpp"

Jupiter::Jupiter() : Fase(),
maxAberracoesEspaciais(0)
{
    figura = new Figura(
        2819, 1589,
        1,1,
        0,0,
        0,0
    );
    carregarFigura(JUPITER_PATH);
    figura->setTamanho(1309, 736);
}

Fases::Jupiter::~Jupiter(){
}

void Jupiter::executar(){
    
    if(ativa){
        desenhar();
        renderizarEntidades();
        gerenciarColisoes();
        gerenciarEventos();
        atualizaPerseguido();
    }
}

void Jupiter::criar(){
    definirGravidade();
    criarInimigos();
    criarObstaculos();
    configurarJogador();
    configurarPerseguido();
    ativa = true;
}

void Jupiter::recuperar(){

    recuperarPlataformas();
    recuperarBuracosNegros();
    recuperarViajantesMaus();
    recuperarAberracoesEspaciais();
    recuperarPlasmas();
    recuperarJogador();

    
    configurarPerseguido();
    definirGravidade();
    colorirPlataformas();
    ativa = true;
    
}


void Fases::Jupiter::criarInimigos() {
    criarViajantesMaus();
    criarAberracoesEspaciais();
    criarPlasmas();
}

void Fases::Jupiter::criarObstaculos() {
    criarCenario();
    criarPlataformas();
    criarBuracosNegros();
    colorirPlataformas();
}

void Jupiter::criarPlataformas() {
    const int max = rand() % 2 + 1;
    const float tamanho_plano = LARGURA / 10.0f;

    for (int i = 1; i < max + 1; i++) {
        for(int j = 0; j < 5; j++) {
            construirPlano(tamanho_plano, Vector2f(i * 380.0f, ALTURA - (ALT_PLATAFORMA) * j));
        }
    }
}

/*void Fases::Jupiter::criarPortais() {
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
}*/

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

/*void Fases::Jupiter::criarAlienigenas() {
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
}*/

void Jupiter::criarViajantesMaus(){
    ViajanteMau* pVM = NULL;
    const int max = rand() % 2 + 3;
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

void Jupiter::criarAberracoesEspaciais(){
    AberracaoEspacial* pAB = NULL;

    const int max = rand() % 2 + 3;
    const float distancia = 80.0f;
    int v_inicial = -1;

    for(int i = 0; i<max; i++){
        pAB = new AberracaoEspacial(i * distancia, distancia);
        pAB->atualizaVelocidade(Vector2f(v_inicial, 1));

        if(pAB){
            entidades->adiciona(static_cast<Entidade*>(pAB));
            GC.incluirInim(static_cast<Inimigo*>(pAB));
        }

        pAB = NULL;
        v_inicial *= -1;
    }

    if (pAB) delete pAB;
    pAB = NULL;

}

void Jupiter::criarPlasmas() {
    
    Plasma* pPla = NULL;

    const int max = rand() % 2 + 1;

    for(int i = 0; i<max; i++){
        pPla = new Plasma(0,0);

        if(pPla){
            entidades->adiciona(static_cast<Entidade*>(pPla));
            GC.incluirPlas(pPla);
            AberracaoEspacial::incluiPlasma(pPla);
        }

        pPla = NULL;

    }

    if (pPla) delete pPla;
    pPla = NULL;

}

void Jupiter::recuperarBuracosNegros()
{
    float x,y;
    BuracoNegro* pBuNegro = NULL;
    ifstream buffer(BURACO_NEGRO_SALVAR_PATH);

    while(buffer >> x >> y){
        pBuNegro = new BuracoNegro(x,y);

        entidades->adiciona(static_cast<Entidade*>(pBuNegro));
        GC.incluirObst(static_cast<Obstaculo*>(pBuNegro));

        pBuNegro = NULL;
    }

    buffer.close();
}

void Jupiter::recuperarAberracoesEspaciais()
{
    float x,y,velocidade_x;
    int num_vidas, recarregando;
    bool andando;
    ifstream buffer(ABERRACAO_ESPACIAL_SALVAR_PATH);
    AberracaoEspacial* pAbEsp = NULL;

    while(buffer >> x >> y >> num_vidas >> andando >> velocidade_x >> recarregando){
        pAbEsp = new AberracaoEspacial(x,y);

        pAbEsp->setVidas(num_vidas);
        pAbEsp->calcVivo();
        pAbEsp->setAndando(andando);
        pAbEsp->setVelocidadeX(velocidade_x);
        pAbEsp->setRecarregando(recarregando);

        entidades->adiciona(static_cast<Entidade*>(pAbEsp));
        GC.incluirInim(static_cast<Inimigo*>(pAbEsp));

        pAbEsp = NULL;
    }

    buffer.close();
}

void Jupiter::recuperarPlasmas()
{
    float x, y;
    bool ativo;
    Vector2f vel;

    Plasma* pPlasma = NULL;
    ifstream buffer(PLASMA_SALVAR_PATH);

    while(buffer >> ativo >> x >> y >> vel.x >> vel.y){
        pPlasma = new Plasma(x,y);

        pPlasma->setAtivo(ativo);
        pPlasma->setVelocidade(vel);

        entidades->adiciona(static_cast<Entidade*>(pPlasma));
        GC.incluirPlas(pPlasma);
        AberracaoEspacial::incluiPlasma(pPlasma);

        pPlasma = NULL;
    }

    buffer.close();
}

void Jupiter::configurarPerseguido(){
    ViajanteMau::setPJog(pJog1);
    AberracaoEspacial::setPJog(pJog1);
}

void Jupiter::atualizaPerseguido() {
    if (pJog2) {
        if (!pJog1->getVivo() && pJog2->getVivo()) {
            AberracaoEspacial::setPJog(pJog2);
            ViajanteMau::setPJog(pJog2);
        }
    }
}

void Jupiter::definirGravidade(){
    Entidade::setGravidade(9.8f);
}

void Jupiter::colorirPlataformas() {
    Entidade* pE = NULL;
    for (int i = 0; i < entidades->getTamanho(); i++) {
        pE = (*entidades)[i];
        if (pE && dynamic_cast<Plataforma*>(pE)) {
            pE->setCorFigura(Color::Red);
        } 
    }
}