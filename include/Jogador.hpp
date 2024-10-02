#pragma once
#include "stdfax.h"
#include "Personagem.hpp"

namespace Personagens {
class Jogador
{
private:
    /* data */
    int pontos;
    const bool jogador1;
public:
    Jogador(const bool j1 = true);
    ~Jogador();
    // void executar();
    int getPontos() const { return pontos; }
    void operator+=(int pts);
};
} using namespace Personagens;