#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
menu(),
GE(),
jog1(NULL),
jog2(NULL),
faseLua(NULL),
faseJupiter(NULL),
faseEscolhida(NULL),
doisJogadores(false),
ranking()
{
    menu.setJogo(this);
    executar();
}

Jogo::~Jogo() {
    jog1 = NULL;
    jog2 = NULL;
    faseEscolhida = NULL;
}

void Jogo::executar() {
    
    while (pGG->getJanelaAberta()) {
        
        pGG->setDeltaTime(tempo.restart().asSeconds());

        // pollevents
        while(pGG->getPJanela()->pollEvent( *(GE.getEvento()))) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) 
                encerrarJogo();

            if (GE.getEvento()->type == Event::Closed) {
                pGG->fecharJanela();
            }

            if (Keyboard::isKeyPressed(Keyboard::P)) {
                // menu.setEstado(5); // pause
                menu.menuPause();
            }


        }
        pGG->limparJanela();
        // execucoes
        menu.executar();

        if (menu.getEstado() == "Jogando") {
            faseEscolhida->executar();

            if (faseEscolhida->getVencida()) {
                menu.setEstado(8); // Fase vencida
                menu.menuFaseVencida();
            }
        }


        pGG->exibirNaJanela();
    }

    if(jog1)
        ranking.adicionarJogador(jog1);
        
    ranking.executar();
}

void Jogo::limparJogo()
{
    jog1 = NULL;
    jog2 = NULL;
    faseEscolhida = NULL;

    if(faseJupiter){
        delete faseJupiter;
        faseJupiter = NULL;
    }
        
    if(faseLua){
        delete faseLua;
        faseLua = NULL;
    }
       

    GE.limparJog();
    srand(time(NULL));
}

// Jogador em operator()-- notifica jogo que perdeu vida logo devemos avaliar se ambos morreram
//  ! - mudar o estado certo
void Jogo::notificar() {
    if (doisJogadores) {
        if (!(jog1->getVivo() || jog2->getVivo())) {
            menu.setEstado(7); // Game over
            menu.menuGameOver();
            // menu.menuInicial();
        }
    } else {
        if (!jog1->getVivo()) {
            menu.setEstado(7); // Game over
            menu.menuGameOver();
            // menu.menuInicial();
        }
    }
}

void Jogo::escolherFase(const int id_fase) {
    if (id_fase == 1) {
        faseLua = new Lua();
        faseEscolhida = static_cast<Fase*>(faseLua);

    } else if (id_fase == 2){
        faseJupiter = new Jupiter();
        faseEscolhida = static_cast<Fase*>(faseJupiter);
    }
}

const bool Jogo::criarFaseEscolhida() {
    if (!faseEscolhida) {
        cout << "void Jogo::criarFaseEscolhida() -> fase ou numero de jogadores nao escolhido -> escolha" << endl;
        return false; // nao foi possivel criar
    } 

    jog1 = new Jogador();
    GE.setPJog(jog1);
    faseEscolhida->setJogador(jog1, 1);
    jog1->adicionarObservador(this);

    if (doisJogadores) {
        jog2 = new Jogador();
        GE.setPJog(jog2);
        faseEscolhida->setJogador(jog2, 2);
        jog2->adicionarObservador(this);
    }
    
    faseEscolhida->setPGEventos(&GE);
    faseEscolhida->criar();

    return true;
}

void Jogo::recuperarJogador()
{
    float x,y,velocidade_y;
    int num_vidas, pontos, idFase, contJogs;
    bool ehJog1, andando, pulando;

    ifstream buffer(JOGADOR_SALVAR_PATH);

    contJogs = 0;

    while(buffer >> idFase >> ehJog1 >> pontos >> x >> y >> num_vidas >> andando >> pulando >> velocidade_y){
        if(ehJog1){
            jog1 = new Jogador(x,y);
            jog1->setPontos(pontos);
            jog1->setVidas(num_vidas);
            jog1->calcVivo();
            jog1->setAndando(andando);
            jog1->setPulando(pulando);
            jog1->setVelocidadeY(velocidade_y);
            jog1->setIdFase(idFase);
            jog1->adicionarObservador(this);
            contJogs++;
        }
        else{
            jog2 = new Jogador(x,y);
            jog2->setPontos(pontos);
            jog2->setVidas(num_vidas);
            jog2->calcVivo();
            jog2->setAndando(andando);
            jog2->setPulando(pulando);
            jog2->setVelocidadeY(velocidade_y);
            jog2->setIdFase(idFase);
            jog2->adicionarObservador(this);
            contJogs++;
        }     
    }

    if(contJogs == 2)
        doisJogadores = true;
    else
        doisJogadores = false;

    buffer.close();
    
}

void Jogo::salvarFaseEscolhida()
{
    if(faseEscolhida)
        faseEscolhida->salvar();
    else
        cout << "Jogo::salvarFaseEscolhida -> ponteiro nulo faseEscolhida" << endl;
}

const bool Jogo::recuperarFase()
{
    path path("./data/salvamento");

    if(! (exists(path) && is_directory(path)) ){
        cout << "Jogo::recuperarFase() -> Salvamento inexistente" << endl;
        return false;
    }

    recuperarJogador();

    escolherFase(jog1->getIdFase());

    GE.setPJog(jog1);
    faseEscolhida->setJogador(jog1, 1);


    if (doisJogadores) {
        GE.setPJog(jog2);
        faseEscolhida->setJogador(jog2, 2);
    }
    
    faseEscolhida->setPGEventos(&GE);

    faseEscolhida->recuperar();

    return true;
}

Fase *Jogo::getFaseEscolhida() const
{
    if (faseEscolhida) {
        return faseEscolhida;
    } else {
        cout << "const Fase *Jogo::getFaseEscolhida() -> nenhuma fase foi escolhida" << endl;
        return NULL;
    }
}

