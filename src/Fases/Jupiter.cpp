
#include "Jupiter.hpp"

Jupiter::Jupiter() : Fase(),
maxAberracoesEspaciais(rand() % 2 + 3),
maxBuracosNegros(rand() % 4 + 3),
maxPlasmas(rand() % 2 + 1),
maxViajantesMaus(rand() % 2 + 3)
{
    figura = new Figura(2819, 1589);
    carregarFigura(JUPITER_PATH);
    figura->setTamanho(1309, 736);
}

Fases::Jupiter::~Jupiter(){
    AberracaoEspacial::limparPlasmas();
    AberracaoEspacial::limparJog();
    ViajanteMau::limparJog();
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

    definirGravidade();
    
    recuperarPlataformas();
    recuperarBuracosNegros();
    recuperarViajantesMaus();
    recuperarAberracoesEspaciais();
    recuperarPlasmas();
    recuperarJogador();

    
    configurarPerseguido();
    colorirPlataformas();
    ativa = true;
    
}


void Fases::Jupiter::criarInimigos() {
    criarViajantesMaus();
    criarAberracoesEspaciais();
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
    const int min = 3;  
    float dx = LARGURA / 2.25f;
    float dy = ALTURA - ALT_PLATAFORMA * 2 - 80.0f;

    for (int i = 0; i < min; i++) {
        pB = new BuracoNegro(dx * i, dy);
        if (pB) {
            entidades->adiciona(static_cast<Entidade*>(pB));
            GC.incluirObst(static_cast<Obstaculo*>(pB));
        

        }
        pB = NULL;
    }

    dy = 80.0f;
    for (int i = 0; i < maxAberracoesEspaciais - min; i++) {
        pB = new BuracoNegro(dx * i, dy);
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
    
    const float distancia = 80.0f;

    for (int i = 1; i < maxViajantesMaus + 1; i++) {
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

    const float distancia = 100.0f;
    int v_inicial = -1;

    for(int i = 1; i<=maxAberracoesEspaciais; i++){
        pAB = new AberracaoEspacial(i * distancia, 80.0f);
        

        if(pAB){
            entidades->adiciona(static_cast<Entidade*>(pAB));
            GC.incluirInim(static_cast<Inimigo*>(pAB));
            pAB->atualizaVelocidade(Vector2f(v_inicial, 1));
        }

        v_inicial *= -1;
    }

    criarPlasmas(pAB->getMaldade());
    
    pAB = NULL;
}

void Jupiter::criarPlasmas(const int dano) {
    
    Plasma* pPla = NULL;


    for(int i = 0; i<maxPlasmas; i++){
        pPla = new Plasma(dano);

        if(pPla){
            entidades->adiciona(static_cast<Entidade*>(pPla));
            GC.incluirPlas(pPla);
            AberracaoEspacial::incluiPlasma(pPla);
        }

        pPla = NULL;

    }

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

void Jupiter::recuperarViajantesMaus()
{
    float x,y;
    int num_vidas;
    bool andando,planando;
    ifstream buffer(VIAJANTE_MAU_SALVAR_PATH);
    ViajanteMau* pViaMau = NULL;

    while(buffer >> x >> y >> num_vidas >> andando >> planando){

        pViaMau = new ViajanteMau(x,y);

        pViaMau->setAndando(andando);
        pViaMau->setVidas(num_vidas);
        pViaMau->calcVivo();
        pViaMau->setPlanando(planando);

        entidades->adiciona(static_cast<Entidade*>(pViaMau));
        GC.incluirInim(static_cast<Inimigo*>(pViaMau));

        pViaMau = NULL;
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
    int dano;

    Plasma* pPlasma = NULL;
    ifstream buffer(PLASMA_SALVAR_PATH);

    while(buffer >> ativo >> x >> y >> vel.x >> vel.y >> dano){
        pPlasma = new Plasma(x,y);

        pPlasma->setAtivo(ativo);
        pPlasma->setVelocidade(vel);
        pPlasma->setDano(dano);

        entidades->adiciona(static_cast<Entidade*>(pPlasma));
        GC.incluirPlas(pPlasma);
        AberracaoEspacial::incluiPlasma(pPlasma);

        pPlasma = NULL;
    }

    buffer.close();
}

void Jupiter::configurarJogador()
{
    if (!pJog1) {
        // cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 1 nao configurado" << endl;
        return;
    }

    GC.setPJog1(pJog1);
    entidades->adiciona(static_cast<Entidade*>(pJog1));
    pJog1->setXY(LARG_PLATAFORMA * 4.0, ALTURA - (LARG_PLATAFORMA * 2));
    pJog1->setIdFase(2);

    if(!pJog2) {
        // cout << "void Fase::configurarJogador(const int num_jogador, Vector2f posicao) -> jogador 2 inexistente" << endl;
        return;
    }

    GC.setPJog2(pJog2);
    entidades->adiciona(static_cast<Entidade*>(pJog2));
    pJog2->setXY(LARG_PLATAFORMA * 5.0, ALTURA - (LARG_PLATAFORMA * 2));
    pJog2->setIdFase(2);
    
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