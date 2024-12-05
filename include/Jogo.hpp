#pragma once
#include "ListaEntidades.hpp"
#include "Projetil.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Janela.hpp"
#include "stdafx.h"


class Jogo
{
private:
    Jogador* pJ1;
    static GerenciadorGrafico* pGG;
    Janela janela;
    
public:
    Jogo();
    ~Jogo();
    void executar();
};


