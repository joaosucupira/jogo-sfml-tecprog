#pragma once
#include "stdafx.h"
#include "Entidade.hpp"

class GerenciadorColisoes
{
private:
    Clock relogio;
    Vector2f gravidade;
    
public:
    GerenciadorColisoes(const Vector2f grav = Vector2f(0.0f, 9.5f));
    ~GerenciadorColisoes();

    void aplicarGravidade(Entidades::Entidade* pE);
};

