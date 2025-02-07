#include "Menu.hpp"
#include "Jogo.hpp"

Menu::Menu() : 
pJogo(NULL),
opcaoSelecionada(0), 
corSelecionada(Color::Red), 
corNormal(Color::White),
logo(),
rLogo()
{
    carregarLogo();
    nomeJogador = "";
    inicializaEstados();
    carregarFontes();
    menuInicial();
    opcoes[opcaoSelecionada].setFillColor(corSelecionada);
}

Menu::~Menu() {
    pJogo = NULL;
}

void Menu::executar() {
    tratarEventos();
    desenharOpcaos();
}

void Menu::inicializaEstados() {
    estados = {
        {0, "Inicial"},
        {1, "Novo Jogo"},
        {2, "Carregar"},
        {3, "Leaderboard"},
        {4, "Jogando"},
        {5, "Pause"},
        {6, "Digitando"},
        {7, "Game Over"},
        {8, "Fase Vencida"}
    };
    estadoAtual = estados[0];
}

void Menu::carregarFontes() {
    if (!fonte.loadFromFile(PATH_FONTE_A)) {
        cerr << "Erro ao carregar a fonte." << endl;
    }
    if (!fonteSelecionada.loadFromFile(PATH_FONTE_B)) {
        cerr << "Erro ao carregar a fonte." << endl;
    }
}

void Menu::tratarEventos() {
    if (estadoAtual == "Digitando") {
        tratarEntradaTexto();
    }

    if (estadoAtual == "Jogando") {
        return;
    }

    static bool teclaAnteriormentePressionada = false; 

    bool teclaPressionada = Keyboard::isKeyPressed(Keyboard::Down) || 
                            Keyboard::isKeyPressed(Keyboard::Up) ||
                            Keyboard::isKeyPressed(Keyboard::Enter);

    if (teclaPressionada && !teclaAnteriormentePressionada) {

        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            trataPorEstado(opcaoSelecionada);
            
        } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            moverSelecao(1);
        } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
            moverSelecao(-1);
        }
    }


    teclaAnteriormentePressionada = teclaPressionada;
}


void Menu::moverSelecao(int direcao) {
    opcoes[opcaoSelecionada].setFillColor(corNormal);
    opcoes[opcaoSelecionada].setFont(fonte);
    opcaoSelecionada += direcao;

    if (opcaoSelecionada < 0) {
        opcaoSelecionada = opcoes.size() - 1;
    } else if (opcaoSelecionada >= (int) opcoes.size()) {
        opcaoSelecionada = 0;
    }

    opcoes[opcaoSelecionada].setFillColor(corSelecionada);
    opcoes[opcaoSelecionada].setFont(fonteSelecionada);
}

void Menu::desenharOpcaos() {
    if (estadoAtual == "Inicial") {
        desenharLogo();
    }

    if (estadoAtual == "Game Over") {
        desenharGameOver();
    }

    if (estadoAtual == "Fase Vencida") {
        desenharFaseVencida();
    }

    

    for (const auto& opcao : opcoes) {
        pGG->getPJanela()->draw(opcao);
    }

    if (nomeJogador != "" && estadoAtual == "Novo Jogo") {
        pGG->getPJanela()->draw(criarTexto(nomeJogador, 350, 200));
    }
}

void Menu::menuInicial() {
    limparOpcoes();
    opcaoSelecionada = 0; // impede o segfault
    estadoAtual = estados[0];
    opcoes.push_back(criarTexto("Novo Jogo", 100, 200));
    opcoes.push_back(criarTexto("Carregar", 100, 250));
    opcoes.push_back(criarTexto("Leaderboard", 100, 300));
    opcoes.push_back(criarTexto("Sair", 100, 350));
}

void Menu::menuNovoJogo() {
    limparOpcoes();

    estadoAtual = estados[1];
    opcoes.push_back(criarTexto("Digite seu nome:", 100, 200)); // 0
    opcoes.push_back(criarTexto("Escolha uma fase:", 100, 250)); // 1
    recebeFaseEscolhida(); // 2 e 3
    opcoes.push_back(criarTexto("Quantos jogadores:", 100, 300)); // 4
    recebeMultijogador(); // 5 e 6
    opcoes.push_back(criarTexto("Jogar", 100, 350)); // 7
    opcoes.push_back(criarTexto("Voltar", 100, 400)); // 8
}

void Menu::recebeMultijogador() {
    opcoes.push_back(criarTexto("1J", 400, 300));
    opcoes.push_back(criarTexto("2J", 450, 300));
}

void Menu::recebeFaseEscolhida() {
    opcoes.push_back(criarTexto("Lua", 370, 250));
    opcoes.push_back(criarTexto("Jupiter", 440, 250));
}

void Menu::menuCarregar() {
    limparOpcoes();
    estadoAtual = estados[2];
    opcoes.push_back(criarTexto("Nao ha jogos salvos para se carregar.", 100, 200));
    opcoes.push_back(criarTexto("Voltar", 100, 250));
}

void Menu::menuLeaderboard() {
    limparOpcoes();
    estadoAtual = estados[3];
    opcoes.push_back(criarTexto("Nao ha registros de jogador algum.", 100, 200));
    opcoes.push_back(criarTexto("Voltar", 100, 250));
}

void Menu::menuPause() {
    estadoAtual = estados[5];
    limparOpcoes();
    opcaoSelecionada = 0;
    opcoes.push_back(criarTexto("Continuar", 100, 200));
    opcoes.push_back(criarTexto("Salvar", 100, 250));
    opcoes.push_back(criarTexto("Menu inicial", 100, 300));
}

void Menu::menuGameOver() {
    limparOpcoes();
    opcaoSelecionada = 0;
    estadoAtual = estados[7];

    opcoes.push_back(criarTexto("Tentar novamente",100,200));
    opcoes.push_back(criarTexto("Menu inicial",100,250));
}

void Menu::menuFaseVencida() {
    limparOpcoes();
    opcaoSelecionada = 0;
    estadoAtual = estados[8];

    opcoes.push_back(criarTexto("Ver ranking",100,200));
    opcoes.push_back(criarTexto("Menu inicial",100,250));
}

void Menu::limparOpcoes() {
    if (!opcoes.empty()) {
        opcoes.clear();
    }
}

void Menu::trataPorEstado(const int escolha) {
    if (estadoAtual == "Inicial") {
        tratarSelecaoInicial(escolha);

    } else if (estadoAtual == "Novo Jogo") {
        tratarSelecaoNovoJogo(escolha);

    } else if (estadoAtual == "Carregar") {
        tratarSelecaoCarregar(escolha);

    } else if (estadoAtual == "Leaderboard") {
        tratarSelecaoLeaderboard(escolha);

    } else if (estadoAtual == "Digitando") {
        tratarEntradaTexto();

    } else if (estadoAtual == "Pause") {
        tratarSelecaoPause(escolha);

    } else if (estadoAtual == "Game Over") {
        tratarSelecaoGameOver(escolha);

    } else if (estadoAtual == "Fase Vencida") {
        tratarSelecaoFaseVencida(escolha);
    }
}

// modificar para usar mapa de estados
void Menu::tratarSelecaoInicial(const int opcao) {
    limparOpcoes();
    pJogo->limparJogo();
    switch (opcao) {
        case 0:
            menuNovoJogo();
            break;
        case 1:
            if(pJogo->recuperarFase())
                estadoAtual = estados[4]; //Jogando
            else
                menuCarregar();
            break;
        case 2:
            menuLeaderboard();
            break;
        default:
            break;
    }
}

void Menu::tratarSelecaoNovoJogo(const int opcao) {
    // limparOpcoes();

    switch (opcao) {
        case 0:
            estadoAtual = estados[6];
            break;
        case 2:
            // escolheu Lua
            pJogo->escolherFase(1);
            opcoes[opcaoSelecionada].setFillColor(Color::Green);
            opcaoSelecionada+=2;
            break;
        case 3:
            // escolheu Jupiter
            pJogo->escolherFase(2);
            opcoes[opcaoSelecionada].setFillColor(Color::Green);
            opcaoSelecionada++;
            break;

        case 5:
            pJogo->setDoisJogadores(false);
            opcoes[opcaoSelecionada].setFillColor(Color::Green);
            opcaoSelecionada+=2;
            break;
        case 6:
            pJogo->setDoisJogadores(true);
            opcoes[opcaoSelecionada].setFillColor(Color::Green);
            opcaoSelecionada++;
            break;

        case 7:
            if (pJogo->criarFaseEscolhida()) {
                estadoAtual = estados[4]; // Jogar
            } else {
                opcoes.push_back(criarTexto("Por favor, pelo menos escolha a fase!", 100, 500));
            }
            break;

        case 8:
            menuInicial(); // Voltar
            break;

        default:
            break;
    }
}

void Menu::tratarSelecaoCarregar(const int opcao) {
    // limparOpcoes();
    switch (opcao)
    {
    case 0:
        /* Idealmente aqui haveria uma lista de jogos salvos mas se nao der esse menu só verifica se te 
            tem algum salvamento, se tiver ele manda esperar enquanto chama o carregamento do ponteiro de 
            jogo. se nao, ele avisa que nao tem jogo salvo e da a opcao de voltar para menu inicial.*/
        break;
    case 1:
        menuInicial();
        break;
    
    default:
        break;
    }
}

void Menu::tratarSelecaoLeaderboard(const int opcao) {
    // limparOpcoes();
    switch (opcao)
    {
    case 0:
        // vai ter uma lista de nomes e pontuacoes num set/multiset
        break;
    case 1:
        menuInicial();
        break;
    
    default:
        break;
    }
}

void Menu::tratarSelecaoPause(const int opcao) {
    limparOpcoes();
    menuPause();
    switch (opcao)
    {
    case 0:
        estadoAtual = estados[4]; // Jogando
        break;
    case 1:
        opcoes[opcaoSelecionada+1].setFillColor(Color::Green);
        pJogo->salvarFaseEscolhida();// Salvamento
        break;
    case 2:
        menuInicial();
        break;
    
    default:
        break;
    }
}


void Menu::tratarEntradaTexto() {
    nomeJogador = "";

    Event evento;
    while (estadoAtual == "Digitando") {
        while (pGG->getPJanela()->pollEvent(evento)) {

            if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Enter) {
                estadoAtual = estados[1]; // Novo jogo
            }

            if (evento.type == Event::TextEntered) { 
                if (evento.text.unicode < 32) {
                    // Backspace
                    if (evento.text.unicode == 8 && !nomeJogador.empty()) {
                        nomeJogador.pop_back();
                    }
                } else if (
                    evento.text.unicode >= 32 &&
                    evento.text.unicode < 128 &&
                    evento.text.unicode != 58 && 
                    nomeJogador.size() < 150) {

                    nomeJogador += static_cast<char>(evento.text.unicode);
                    desenharOpcaos();
                }
            }
        }
    }
}

void Menu::tratarSelecaoGameOver(const int opcao) {
    limparOpcoes();
    opcaoSelecionada = 0;
    menuGameOver();

    switch (opcao)
    {
    case 0:
        pJogo->limparJogo();
        menuNovoJogo();
        break;
    case 1:
        menuInicial();
        break;
    
    default:
        break;
    }
}

void Menu::tratarSelecaoFaseVencida(const int opcao) {
    limparOpcoes();
    opcaoSelecionada = 0;
    menuFaseVencida();

    switch (opcao)
    {
    case 0:
        // menuLeaderboard();
        break;
    case 1:
        menuInicial();
        break;
    
    default:
        break;
    }
}

void Menu::setJogo(Jogo *pJ) {
    if (pJ) {
        pJogo = pJ;
        
    } else {
        cout << "void Menu::setJogo(Jogo *pJ) -> ponteiro nulo" << endl;
    }
}


void Menu::desenharLogo() {

    pGG->getPJanela()->draw(rLogo);

}

void Menu::desenharGameOver() {
    Text gameover = criarTexto("GAME OVER", 500, 300);
    gameover.setCharacterSize(64);
    pGG->getPJanela()->draw(gameover);
}

void Menu::desenharFaseVencida() {
    Text sucesso = criarTexto("SUCESSO!", 500, 300);
    sucesso.setCharacterSize(64);
    pGG->getPJanela()->draw(sucesso);
}

void Menu::carregarLogo() {
    logo.loadFromFile(PATH_LOGO);
    rLogo.setSize(sf::Vector2f(logo.getSize()));
    rLogo.setTexture(&logo);

    rLogo.setOrigin(logo.getSize().x / 2.0f, logo.getSize().y / 2.0f);
    rLogo.setScale(0.125f, 0.125f);
    rLogo.setPosition(LARGURA / 1.8f, ALTURA / 2.0f);

}


Text Menu::criarTexto(const string& texto, float x, float y) {
    Text txt;
    txt.setFont(fonte);
    txt.setString(texto);
    txt.setCharacterSize(24);
    txt.setFillColor(corNormal);
    txt.setPosition(x, y);
    return txt;
}
