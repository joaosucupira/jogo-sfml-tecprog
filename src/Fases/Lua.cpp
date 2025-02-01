#include "Lua.hpp"

Lua::Lua() : Fase(),
maxViajantesMaus(0)
{
    figura = new Figura();
    carregarFigura(LUA_PATH);
}

Lua::~Lua()
{
}

void Lua::executar(){
    if(ativa){
        gerenciarEventos();
        desenhar();
        renderizarEntidades();
        gerenciarColisoes();
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