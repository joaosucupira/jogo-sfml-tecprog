#pragma once
#include "stdafx.h"
#include "Jogador.hpp"

namespace Gerenciadores {

class GerenciadorEventos
{
private:
    Event evento; // fazer ponteiro e alocar na construtora
    Jogador *pJog;
    Clock relogio;

public:
    GerenciadorEventos();
    ~GerenciadorEventos();
  
    void monitorarJogador();
    void lerTeclado();
    void executar();

    Event* getEvento() { return &evento; }
    
    void setPJog(Jogador* pJ);
};

} using namespace Gerenciadores;
