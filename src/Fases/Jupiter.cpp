
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

    float x,y,velocidade_x, velocidade_y;
    int num_vidas, pontos, recarregando;
    bool andando, pulando, planando, ehJog1;

    Plataforma* pPlat = NULL;
    BuracoNegro* pBuNegro = NULL;
    AberracaoEspacial* pAbEsp = NULL;
    ViajanteMau* pViaMau = NULL;

    ifstream buffer;

    buffer.open(PLATAFORMA_SALVAR_PATH);

    while(buffer >> x >> y){
        pPlat = new Plataforma(x,y);
        entidades->adiciona(static_cast<Entidade*>(pPlat));
        GC.incluirObst(static_cast<Obstaculo*>(pPlat));
    }

    buffer.close();

    buffer.open(BURACO_NEGRO_SALVAR_PATH);

    while(buffer >> x >> y){
        pBuNegro = new BuracoNegro(x,y);
        entidades->adiciona(static_cast<Entidade*>(pBuNegro));
        GC.incluirObst(static_cast<Obstaculo*>(pBuNegro));
    }

    buffer.close();

    buffer.open(VIAJANTE_MAU_SALVAR_PATH);

    while(buffer >> x >> y >> num_vidas >> andando >> planando){
        pViaMau = new ViajanteMau(x,y);
        pViaMau->setAndando(andando);
        pViaMau->setVidas(num_vidas);
        pViaMau->setPlanando(planando);

        entidades->adiciona(static_cast<Entidade*>(pViaMau));
        GC.incluirInim(static_cast<Inimigo*>(pViaMau));
    }   

    buffer.close();

    buffer.open(ABERRACAO_ESPACIAL_PATH);

    while(buffer >> x >> y >> num_vidas >> andando >> velocidade_x >> recarregando){
        pAbEsp = new AberracaoEspacial(x,y);
        pAbEsp->setVidas(num_vidas);
        pAbEsp->setAndando(andando);
        pAbEsp->setVelocidadeX(velocidade_x);
        pAbEsp->setRecarregando(recarregando);
        cout << "cheguei" << endl;
    }

    buffer.close();

    /*
    buffer.open(JOGADOR_SALVAR_PATH);
    while(buffer >> ehJog1 >> pontos >> x >> y >> num_vidas >> andando >> pulando >> velocidade_y){
        if(ehJog1){
            pJog1 = new Jogador(x,y);
            pJog1->setPontos(pontos);
            pJog1->setVidas(num_vidas);
            pJog1->setAndando(andando);
            pJog1->setPulando(pulando);
            pJog1->setVelocidadeY(velocidade_y);
            
            entidades->adiciona(static_cast<Entidade*>(pJog1));
            GC.setPJog1(pJog1);
        }
        else{
            pJog2 = new Jogador(x,y);
            pJog2->setPontos(pontos);
            pJog2->setVidas(num_vidas);
            pJog2->setAndando(andando);
            pJog2->setPulando(pulando);
            pJog2->setVelocidadeY(velocidade_y);

            entidades->adiciona(static_cast<Entidade*>(pJog2));
            GC.setPJog2(pJog2);
        }     
    }
    buffer.close();
    */
    configurarJogador();
    configurarPerseguido();
    
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