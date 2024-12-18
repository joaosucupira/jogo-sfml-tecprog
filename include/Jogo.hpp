#pragma once

#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Plataforma.hpp"
// #include "Fase.hpp"
#include "stdafx.h"


class Jogo
{
private:
    GerenciadorColisoes GC;
    GerenciadorEventos GE;
    Jogador jog1;
    Plataforma plat1;
    // Fase fase1;

    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;
  
public:
    Jogo();
    ~Jogo();

    void distribuir();
    void executar();
};


