#pragma once
#include "stdafx.h"
#include "Personagem.hpp"

#define JOGADOR_PATH "../assets/Jogador/player.24x24.png"

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

        void escolheCor();
        void operator+=(int pts);
        void carregarSprite();
        void salvaDataBuffer();
        void executar();

        const int getPontos() const { return pontos; }
    };
} using namespace Personagens;