#pragma once

#include "stdafx.h"
#include "Ente.hpp"

#define PATH_FONTE_A "./assets/Fontes/Pixel_Digivolve.otf"
#define PATH_FONTE_B "./assets/Fontes/Pixel_Digivolve_Italic.otf"

class Jogo;

class Menu : public Ente {
private:
    Jogo* pJogo;
    vector<Text> opcoes;
    int opcaoSelecionada;
    Font fonte;
    Color corSelecionada;
    Color corNormal;
    Text criarTexto(const string& texto, float x, float y);

public:
    Menu();
    ~Menu();
    void executar();
    void tratarEventos();
    void moverSelecao(int direcao);
    void desenharOpcaos();
    void menuInicial();
    void menuNovoJogo();
    void limparOpcoes();
    void tratarSelecao(const int opcao);
    void setJogo(Jogo* pJ);
};