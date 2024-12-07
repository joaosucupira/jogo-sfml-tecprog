#pragma once
#include "stdafx.h"
#include "Jogador.hpp"
#include "Janela.hpp"

namespace Gerenciadores {
class GerenciadorEventos
{
private:
    Event evento;
    Jogador *pJog;
    Janela *pJanela;

public:
    GerenciadorEventos();
    ~GerenciadorEventos();
  
    void monitorarJogador();
    void executar();
    
    void setJanela(Janela* pJ);
};

} using namespace Gerenciadores;
