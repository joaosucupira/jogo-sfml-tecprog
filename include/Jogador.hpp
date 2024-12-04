#pragma once
#include "stdafx.h"
#include "Personagem.hpp"

namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        int pontos;
        const bool joga1;
    public:
        Jogador(const bool j1);
        ~Jogador();

        const int getPontos() const { return pontos; }

        void escolheCor();
        void setCor(Color cor);

        void operator+=(int pts);

        void salvaDataBuffer();
        void executar();
    };
} using namespace Personagens;