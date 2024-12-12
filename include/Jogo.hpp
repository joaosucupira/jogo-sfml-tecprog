#pragma once

#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "stdafx.h"


class Jogo
{
private:
    GerenciadorColisoes GC;
    GerenciadorEventos GE;
    Jogador jog1;

    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;
  
public:
    Jogo();
    ~Jogo();

    void distribuir();
    
    //void distribuirRelogio();

    void executar();
};


