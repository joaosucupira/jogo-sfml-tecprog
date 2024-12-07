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
        Jogador(const float x_inicial = 0, const float y_inicial = 0);
        ~Jogador();

        const int getPontos() const { return pontos; }

        void escolheCor();
        void operator+=(int pts);
        // void andar(float dt);
        // void pular(float dt);

        void salvaDataBuffer();
        void executar();
    };
} using namespace Personagens;