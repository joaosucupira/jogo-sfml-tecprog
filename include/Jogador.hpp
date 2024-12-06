#pragma once
#include "stdafx.h"
#include "Personagem.hpp"

namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        static int cont;
        int pontos;
        bool joga1;
    public:
        Jogador();
        ~Jogador();

        const int getPontos() const { return pontos; }

        void escolheCor();

        void operator+=(int pts);

        void salvaDataBuffer();
        void executar();
    };
} using namespace Personagens;