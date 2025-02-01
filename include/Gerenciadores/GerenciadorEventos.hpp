#pragma once
#include "stdafx.h"
#include "Jogador.hpp"

namespace Gerenciadores {

class GerenciadorEventos
{
private:
    Event evento; // fazer ponteiro e alocar na construtora
    Jogador *pJog;
    Jogador *pJog2;

public:
    GerenciadorEventos();
    ~GerenciadorEventos();
  
    void monitorarJogador();
    void lerTeclado();
    void lerTecladoJog2();
    void encerrar() { evento.type = Event::Closed; }
    void executar();

    Event* getEvento() { return &evento; }
    
    void setPJog(Jogador* pJ);
};

} using namespace Gerenciadores;
