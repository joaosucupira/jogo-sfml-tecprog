#include "Menu.hpp"
#include "Jogo.hpp"


Menu::Menu() : 
pJogo(NULL),
opcaoSelecionada(0), 
corSelecionada(sf::Color::Red), 
corNormal(sf::Color::White) 
{
    if (!fonte.loadFromFile(PATH_FONTE_A)) {
        cerr << "Erro ao carregar a fonte.\n";
    }

    menuInicial();

    opcoes[opcaoSelecionada].setFillColor(corSelecionada);
}


Menu::~Menu()
{
    pJogo = NULL;
}

void Menu::executar() {
    tratarEventos();
    desenharOpcaos();
}

void Menu::tratarEventos() {
    static bool teclaAnteriormentePressionada = false; 

    bool teclaPressionada = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || 
                            sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                            sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);

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
    opcaoSelecionada += direcao;

    if (opcaoSelecionada < 0) {
        opcaoSelecionada = opcoes.size() - 1;
    } else if (opcaoSelecionada >= opcoes.size()) {
        opcaoSelecionada = 0;
    }

    opcoes[opcaoSelecionada].setFillColor(corSelecionada);
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
    opcoes.push_back(criarTexto("Digite seu nome:", 100, 200));
    opcoes.push_back(criarTexto("Escolha a fase", 100, 250));
    opcoes.push_back(criarTexto("Quantos jogadores:", 100, 300));
}

void Menu::limparOpcoes() {
    opcoes.clear();
}

void Menu::tratarSelecao(const int opcao) {
    limparOpcoes();
    switch (opcao)
    {
    case 0:
        menuNovoJogo();
        break;
    case 1:
        menuNovoJogo();
        break;
    case 2:
        menuNovoJogo();
        break;
    
    default:
        break;
    }
}

void Menu::setJogo(Jogo *pJ) {
    if (pJ) {
        pJogo = pJ;
    } else { cout << "void Menu::setJogo(Jogo *pJ) -> ponteiro nulo" << endl; }
}

sf::Text Menu::criarTexto(const std::string& texto, float x, float y) {
    sf::Text txt;
    txt.setFont(fonte);
    txt.setString(texto);
    txt.setCharacterSize(24);
    txt.setFillColor(corNormal);
    txt.setPosition(x, y);
    return txt;
}