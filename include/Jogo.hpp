#pragma once

#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include "Alienigena.hpp"
#include "Lua.hpp"
#include "Jupiter.hpp"
#include "Menu.hpp"
#include "stdafx.h"


class Jogo {

private:

    Menu menu;
    Clock tempo;
    GerenciadorEventos GE;
    Jogador* jog1;
    Jogador* jog2;
    Lua* faseLua;
    Jupiter* faseJupiter;
    Fase* faseEscolhida;

    bool doisJogadores;

    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;
  
public:

    Jogo();
    ~Jogo();
    
    /*----------------------------------------------------------------------------*/
    void executar();
    void escolherFase(const int id_fase);
    void setDoisJogadores(const bool d) { doisJogadores = d; }
    const bool criarFaseEscolhida();
    const bool recuperarFase();

    void salvarFaseEscolhida();
    void limparJogo();
    
private:

    void recuperarJogador();
    void encerrarJogo() { GE.encerrar(); }
    

    Fase* getFaseEscolhida() const;

};


