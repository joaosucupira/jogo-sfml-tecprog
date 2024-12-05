#pragma once

#include "GerenciadorGrafico.hpp"
#include "Janela.hpp"
#include "stdafx.h"


class Jogo
{
private:
    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;

    /* Janela que é passada por referência para objetos que irão a manipular */
    Janela janela;
    
public:
    Jogo();
    ~Jogo();
    
    void distribuirJanela();
    void executar();
};


