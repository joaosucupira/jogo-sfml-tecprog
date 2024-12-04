#pragma once
#include "stdafx.h"
#include "Entidade.hpp"

using namespace Entidades;


namespace Personagens {
class Personagem : public Entidades::Entidade
{
protected:
    int num_vidas;
public:
    Personagem();
    ~Personagem();

    void setVidas(const int vidas) { num_vidas = vidas; }

    int getVidas() const { return num_vidas; }
    virtual void executar() = 0;
};
} using namespace Personagens;