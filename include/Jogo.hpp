#pragma once

#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "Janela.hpp"
#include "stdafx.h"


class Jogo
{
private:
    GerenciadorColisoes GC;
    Clock* relogio;

    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;

    /* Janela que é passada por referência para objetos que irão a manipular */
    Janela janela;


    
public:
    Jogo();
    ~Jogo();

    void distribuir();
    
    void distribuirRelogio();
    void distribuirJanela();

    void executar();
};


