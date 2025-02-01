#include "Menu.hpp"
#include "Jogo.hpp"

Menu::Menu() : 
pJogo(NULL),
opcaoSelecionada(0), 
corSelecionada(Color::Red), 
corNormal(Color::White)
{
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
        {5, "Pause"}
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
    for (const auto& opcao : opcoes) {
        pGG->getPJanela()->draw(opcao);
    }
}

void Menu::menuInicial() {
    limparOpcoes();
    estadoAtual = estados[0];
    opcoes.push_back(criarTexto("Novo Jogo", 100, 200));
    opcoes.push_back(criarTexto("Carregar", 100, 250));
    opcoes.push_back(criarTexto("Leaderboard", 100, 300));
    opcoes.push_back(criarTexto("Sair", 100, 350));
}

void Menu::menuNovoJogo() {
    limparOpcoes();
    estadoAtual = estados[1];
    opcoes.push_back(criarTexto("Digite seu nome:", 100, 200));
    opcoes.push_back(criarTexto("Escolha uma fase:", 100, 250));
    opcoes.push_back(criarTexto("Quantos jogadores:", 100, 300));
    opcoes.push_back(criarTexto("Voltar", 100, 350));
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

void Menu::limparOpcoes() {
    opcoes.clear();
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
    }
}

// modificar para usar mapa de estados
void Menu::tratarSelecaoInicial(const int opcao) {
    limparOpcoes();
    switch (opcao) {
        case 0:
            menuNovoJogo();
            break;
        case 1:
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
    limparOpcoes();
    switch (opcao) {
        case 0:
            // receberNomeJogador();
            break;
        case 1:
            // receberEscolhaFase();
            break;
        case 2:
            // receberMultiJogador();
            break;
        case 3:
            menuInicial();
            break;
        default:
            break;
    }
}

void Menu::tratarSelecaoCarregar(const int opcao) {
    limparOpcoes();
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
    limparOpcoes();
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

void Menu::setJogo(Jogo *pJ) {
    if (pJ) {
        pJogo = pJ;
    } else {
        cout << "void Menu::setJogo(Jogo *pJ) -> ponteiro nulo" << endl;
    }
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
