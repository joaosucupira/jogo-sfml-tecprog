#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
// #include "ListaEntidades.hpp"
#include "Jogador.hpp"

namespace Gerenciadores {
class GerenciadorEventos
{
private:


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
