#pragma once
#include "stdfax.h"
#include "Personagem.hpp"

namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        /* data */
        int pontos;
        const bool joga1;
    public:
        Jogador(const bool j1);
        ~Jogador();
        int getPontos() const { return pontos; }
        void operator+=(int pts);
        void executar() { cout << "executando jogador" << endl; }
        void salvar() {}
    };
} using namespace Personagens;