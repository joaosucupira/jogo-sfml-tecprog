#pragma once

#include "stdafx.h"
#include "Ente.hpp"

#define PATH_FONTE_A "./assets/Fontes/Pixel_Digivolve.otf"
#define PATH_FONTE_B "./assets/Fontes/Pixel_Digivolve_Italic.otf"

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

public:
    Menu();
    ~Menu();
    void executar();
    void inicializaEstados();
    void carregarFontes();
    void tratarEventos();
    void moverSelecao(int direcao);
    void desenharOpcaos();
    void menuInicial();
    void menuNovoJogo();
    void menuCarregar();
    void menuLeaderboard();
    void limparOpcoes();
    void trataPorEstado(const int escolha);
    void tratarSelecaoInicial(const int opcao);
    void tratarSelecaoNovoJogo(const int opcao); 
    void tratarSelecaoCarregar(const int opcao); 
    void tratarSelecaoLeaderboard(const int opcao); 
    void setJogo(Jogo* pJ);

};