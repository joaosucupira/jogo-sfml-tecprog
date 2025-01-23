#pragma once

#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include "Alienigena.hpp"
#include "Lua.hpp"
#include "Jupiter.hpp"
#include "stdafx.h"


class Jogo
{
private:

    Clock tempo;
    GerenciadorEventos GE;
    Jogador* jog1;
    Lua faseLua;
    Jupiter faseJupiter;

    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;
  
public:
    Jogo();
    ~Jogo();

    void distribuir();
    void executar();

};


