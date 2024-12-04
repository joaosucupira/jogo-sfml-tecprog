#pragma once
#include "ListaEntidades.hpp"
#include "Projetil.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "stdafx.h"


class Jogo
{
private:
    static GerenciadorGrafico* pGG;
    GerenciadorEventos GE;
    Jogador  J1;

public:
    Jogo();
    ~Jogo();
};


