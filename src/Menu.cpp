#include "Menu.hpp"
#include "Jogo.hpp"

Menu::Menu() : 
pJogo(NULL),
opcaoSelecionada(0), 
corSelecionada(Color::Red), 
corNormal(Color::White)
{
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
            tratarSelecao(opcaoSelecionada);
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
    opcoes.push_back(criarTexto("Novo Jogo", 100, 200));
    opcoes.push_back(criarTexto("Carregar", 100, 250));
    opcoes.push_back(criarTexto("Sair", 100, 300));
}

void Menu::menuNovoJogo() {
    limparOpcoes();
    opcoes.push_back(criarTexto("Digite seu nome:", 100, 200));
    opcoes.push_back(criarTexto("Escolha uma fase:", 100, 250));
    opcoes.push_back(criarTexto("1 Jogador", 100, 300));
    opcoes.push_back(criarTexto("2 Jogadores", 100, 350));

}

void Menu::menuCarregar() {
    limparOpcoes();
    opcoes.push_back(criarTexto("Nao ha jogos salvos para se carregar.", 100, 200));
}

void Menu::limparOpcoes() {
    opcoes.clear();
}


void Menu::tratarSelecao(const int opcao) {
    limparOpcoes();
    switch (opcao) {
        case 0:
            menuNovoJogo();
            break;
        case 1:
            menuCarregar();
            break;
        case 2:
            pJogo->encerrarJogo();
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
