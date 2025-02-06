#include "Lua.hpp"

Lua::Lua() : Fase(),
maxViajantesMaus(0)
{
    figura = new Figura(1309, 736);
    carregarFigura(LUA_PATH);
}

Lua::~Lua()
{
    ViajanteMau::limparJog();
}

void Lua::executar(){
    if(ativa){
        desenhar();
        renderizarEntidades();
        gerenciarColisoes();
        gerenciarEventos();
        atualizaPerseguido();
    }
}

void Lua::criar(){

    definirGravidade();
    criarInimigos();
    criarObstaculos();
    configurarJogador();
    configurarPerseguido();
    ativa = true;
}

void Lua::recuperar(){

    recuperarPlataformas();
    recuperarPortais();
    recuperarAlienigenas();
    recuperarViajantesMaus();
    recuperarJogador();
    
    configurarPerseguido();
    definirGravidade();
    ativa = true;
}


void Fases::Lua::criarObstaculos() {
    criarPortais();
    criarPlataformas();
    criarCenario();
}

void Fases::Lua::criarInimigos() {
    criarAlienigenas();
    criarViajantesMaus();
}

void Fases::Lua::criarPlataformas() {
    
    const float largura_plataforma = LARGURA / 4.0f;

    if (rand() % 2) {
        Vector2f inicio(LARG_PLATAFORMA / 2.0f, ALTURA - ALT_PLATAFORMA * 4.6);
        construirPlano(largura_plataforma, inicio);

        Vector2f inicio2(LARGURA - (largura_plataforma + LARG_PLATAFORMA), ALTURA - ALT_PLATAFORMA * 4.6);
        construirPlano(largura_plataforma, inicio2);

    } else {
        Vector2f inicio( LARGURA / 2.5f, ALTURA - ALT_PLATAFORMA * 4);
        construirPlano( largura_plataforma, inicio);

        Vector2f inicio2((LARGURA) / 2.0f, ALTURA - ALT_PLATAFORMA * 3);
        construirParede(largura_plataforma, inicio2);
    }


}

void Fases::Lua::criarPortais() {
    Portal* pP = NULL;
    const int max = rand() % 3 + 3;
    const float distancia = 150.0f;

    for (int i = 1; i < max + 1; i++) {
        pP = new Portal(distancia * i, 80.0f);
        if (pP) {
            entidades->adiciona(static_cast<Entidade*>(pP));
            GC.incluirObst(static_cast<Obstaculo*>(pP));
        }
        pP = NULL;
    }

    if (pP) delete pP;
    pP = NULL;
}

void Fases::Lua::criarAlienigenas() {
    Alienigena* pA = NULL;
    const int max = rand() % 5 + 3;

    for (int i = 1; i < max + 1; i++) {
        pA = new Alienigena(
            LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - i * 60.0f,
            ALTURA - (TAM_JOGADOR + ALT_PLATAFORMA)
        );

        entidades->adiciona(static_cast<Entidade*>(pA));
        GC.incluirInim(static_cast<Inimigo*>(pA));
        pA = NULL;
    }
    if (pA) delete pA;
    pA = NULL;
}

void Lua::criarViajantesMaus(){
    ViajanteMau* pVM = NULL;
    const int max = rand() % 3 + 3;


    for (int i = 1; i < max + 1; i++) {
        pVM = new ViajanteMau(
            LARGURA - (PLATAFORMA_LARGURA + TAM_JOGADOR) - i * 60.0f,
            (TAM_JOGADOR + ALT_PLATAFORMA)
            
        );


        entidades->adiciona(static_cast<Entidade*>(pVM));
        GC.incluirInim(static_cast<Inimigo*>(pVM));
        pVM = NULL;
    }
    if (pVM) delete pVM;
    pVM = NULL;
}

void Lua::recuperarPortais()
{
    float x,y;
    Portal* pPortal = NULL;
    ifstream buffer(PORTAL_SALVAR_PATH);

    while(buffer >> x >> y){
        pPortal = new Portal(x,y);

        entidades->adiciona(static_cast<Entidade*>(pPortal));
        GC.incluirObst(static_cast<Obstaculo*>(pPortal));

        pPortal= NULL;
    }

    buffer.close();
}

void Lua::recuperarAlienigenas()
{
    float x,y,velocidade_x;
    int num_vidas;
    bool andando;
    ifstream buffer(ALIENIGENA_SALVAR_PATH);
    Alienigena* pAli = NULL;

    while(buffer >> x >> y >> num_vidas >> andando >> velocidade_x){
        pAli = new Alienigena(x,y);

        pAli->setVidas(num_vidas);
        pAli->calcVivo();
        pAli->setAndando(andando);
        pAli->setVelocidadeX(velocidade_x);

        entidades->adiciona(static_cast<Entidade*>(pAli));
        GC.incluirInim(static_cast<Inimigo*>(pAli));

        pAli = NULL;
    }

    buffer.close();
}

void Lua::configurarJogador()
{
    if (!pJog1) {
        cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 1 nao configurado" << endl;
        return;
    }

    GC.setPJog1(pJog1);
    entidades->adiciona(static_cast<Entidade*>(pJog1));
    pJog1->setXY(LARG_PLATAFORMA * 4.0, ALTURA - (LARG_PLATAFORMA * 2));
    pJog1->setIdFase(1);

    if(!pJog2) {
        cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 2 inexistente" << endl;
        return;
    }

    GC.setPJog2(pJog2);
    entidades->adiciona(static_cast<Entidade*>(pJog2));
    pJog2->setXY(LARG_PLATAFORMA * 5.0, ALTURA - (LARG_PLATAFORMA * 2));
    pJog2->setIdFase(1);
    
}

void Lua::definirGravidade()
{
    Entidade::setGravidade(1.5f);
}

void Lua::configurarPerseguido(){
    ViajanteMau::setPJog(pJog1);
}

void Lua::atualizaPerseguido() {
    if (pJog2) {
        if (!pJog1->getVivo() && pJog2->getVivo()) {
            ViajanteMau::setPJog(pJog2);
        }
    }
}