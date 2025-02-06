#pragma once

#include "stdafx.h"
#include "Ente.hpp"

#define PATH_FONTE_A "./assets/Fontes/Pixel_Digivolve.otf"
#define PATH_FONTE_B "./assets/Fontes/Pixel_Digivolve_Italic.otf"
#define PATH_LOGO "./assets/Outros/ANOMALIA_logo.png"

class Jogo;

class Menu : public Ente {
private:
    Jogo* pJogo;
    map<int, string> estados;
    string estadoAtual;
    vector<Text> opcoes;
    int opcaoSelecionada;
    Font fonte;
    Font fonteSelecionada;
    Color corSelecionada;
    Color corNormal;
    Text criarTexto(const string& texto, float x, float y);
    string nomeJogador;
    Texture logo;
    RectangleShape rLogo;
    

public:
    Menu();
    ~Menu();
    void executar();

    /* Principais */
    void inicializaEstados();
    void carregarFontes();
    void tratarEventos();
    void moverSelecao(int direcao);
    void desenharOpcaos();

    /* Telas de menu */
    void menuInicial();
    void menuNovoJogo();
    void recebeMultijogador();
    void recebeFaseEscolhida();
    void menuCarregar();
    void menuLeaderboard();
    void menuPause();
    void menuGameOver();
    void menuFaseVencida();

    void limparOpcoes();

    /* Tratamento de selecao*/
    void trataPorEstado(const int escolha);
    void tratarSelecaoInicial(const int opcao);
    void tratarSelecaoNovoJogo(const int opcao); 
    void tratarSelecaoCarregar(const int opcao); 
    void tratarSelecaoLeaderboard(const int opcao); 
    void tratarSelecaoPause(const int opcao); 
    void tratarEntradaTexto();
    void tratarSelecaoGameOver(const int opcao);
    void tratarSelecaoFaseVencida(const int opcao);

    void setJogo(Jogo* pJ);
    void setEstado(const int estado) { estadoAtual = estados[estado]; }
    const string& getEstado() const { return estadoAtual; }
    void desenharLogo();
    void desenharGameOver();
    void desenharFaseVencida();
    void carregarLogo();


};