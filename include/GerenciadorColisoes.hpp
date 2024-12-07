#pragma once
#include "stdafx.h"
#include "Entidade.hpp"
#include "Jogador.hpp"


class GerenciadorColisoes
{
private:
    Jogador* pJog1;
    const float gravidade;
    Clock* pRelogio;
    
public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();
    void executar();

    void setRelogio(Clock* pR);

    void tratarEntradaJogador(float dt);

    void aplicarGravidade(float dt);

    Jogador* getJogador() const;

};

