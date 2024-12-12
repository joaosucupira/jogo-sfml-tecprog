#pragma once

#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "GerenciadorEventos.hpp"
#include "stdafx.h"


class Jogo
{
private:
    GerenciadorColisoes GC;
    GerenciadorEventos GE;
    //Clock* relogio;

    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;
   

    Jogador jog1;
    
public:
    Jogo();
    ~Jogo();

    void distribuir();
    
    //void distribuirRelogio();

    void executar();
};


