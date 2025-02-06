#include "Jogo.hpp"

GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
menu(),
GE(),
jog1(new Jogador()),
jog2(new Jogador()),
faseLua(),
faseJupiter(),
faseEscolhida(NULL),
doisJogadores(false)
{
    menu.setJogo(this);
    executar();
}

Jogo::~Jogo() {
    jog1 = NULL;
    jog2 = NULL;
    faseEscolhida = NULL;
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
            jog1->setXY(x,y);
            jog1->setPontos(pontos);
            jog1->setVidas(num_vidas);
            jog1->setAndando(andando);
            jog1->setPulando(pulando);
            jog1->setVelocidadeY(velocidade_y);
            jog1->setIdFase(idFase);
            contJogs++;
        }
        else{
            jog2->setXY(x,y);
            jog2->setPontos(pontos);
            jog2->setVidas(num_vidas);
            jog2->setAndando(andando);
            jog2->setPulando(pulando);
            jog2->setVelocidadeY(velocidade_y);
            jog2->setIdFase(idFase);
            contJogs++;
        }     
    }

    if(contJogs == 2)
        doisJogadores = true;
    else
        doisJogadores = false;

    buffer.close();
    
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
        }

        pGG->exibirNaJanela();
    }
}

void Jogo::escolherFase(const int id_fase) {
    if (id_fase == 1) {
        faseEscolhida = &faseLua;
    } else if (id_fase == 2){
        faseEscolhida = &faseJupiter;
    }
}

const bool Jogo::criarFaseEscolhida() {
    if (!faseEscolhida) {
        cout << "void Jogo::criarFaseEscolhida() -> fase ou numero de jogadores nao escolhido -> escolha" << endl;
        return false; // nao foi possivel criar
    } 

    // j1
    GE.setPJog(jog1);
    faseEscolhida->setJogador(jog1, 1);

    if (doisJogadores) {
        // j2
        GE.setPJog(jog2);
        faseEscolhida->setJogador(jog2, 2);
    }
    
    faseEscolhida->setPGEventos(&GE);
    faseEscolhida->criar();

    return true;
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

