#pragma once
#include "stdafx.h"
#include "Jogador.hpp"

namespace Gerenciadores {

class GerenciadorEventos
{
private:
    Event evento;
    Jogador *pJog;
    Jogador *pJog2;

public:
    GerenciadorEventos();
    ~GerenciadorEventos();
    
    /*----------------------------------------------------------------------------*/
    void executar();
    void encerrar() { evento.type = Event::Closed; }

    /*SET*/
    void setPJog(Jogador* pJ);
    
    /*GET*/
    Event* getEvento() { return &evento; }

private:

    void monitorarJogador();
    void lerTeclado();
    void lerTecladoJog2();

};

} using namespace Gerenciadores;
