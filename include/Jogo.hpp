#pragma once

#include "GerenciadorGrafico.hpp"
// #include "GerenciadorColisoes.hpp"
#include "GerenciadorEventos.hpp"
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include "Alienigena.hpp"
#include "Fase.hpp"
#include "stdafx.h"


class Jogo
{
private:
    // Primeiro passo: Adequar a classe principal ao modelo
    // Desacoplar os gerenciadores exceto o gráfico
    // GerenciadorColisoes GC;
    Clock tempo;
    GerenciadorEventos GE;
    Jogador* jog1;
    Fase fase1;

    /* Instancia singleton do Gerenciador Grafico */
    static GerenciadorGrafico* pGG;
  
public:
    Jogo();
    ~Jogo();

    void distribuir();
    void executar();

};


