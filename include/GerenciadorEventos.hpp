#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.hpp"
// #include "ListaEntidades.hpp"
#include "Jogador.hpp"

namespace Gerenciadores {
class GerenciadorEventos
{
private:
    static GerenciadorGrafico* pGG;
    // Listas::ListaEntidades* entidades;
    Jogador j1;
    RenderWindow* janela;
    bool rodando;

public:
    GerenciadorEventos();
    ~GerenciadorEventos();

    void setWindow(RenderWindow* pR);
    void setGraficos();
    void desenhar();
    void eventoBase();
    void executar();
};

} using namespace Gerenciadores;
