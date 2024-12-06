#pragma once
#include "stdafx.h"
#include "Entidade.hpp"

using namespace Entidades;

namespace Personagens {
class Personagem : public Entidade
{
protected:
    int num_vidas;
    bool vivo;
    
public:
    Personagem();
    ~Personagem();

    void setVidas(const int vidas) { num_vidas = vidas; }
    void calcVivo() { vivo = (num_vidas > 0 ? true : false); }

    virtual void mover();
    virtual void executar() = 0;

    const int getVidas() const { return num_vidas; }
    const bool getVivo() const { return vivo; }

    void operator--() { num_vidas--; }
};
} using namespace Personagens;