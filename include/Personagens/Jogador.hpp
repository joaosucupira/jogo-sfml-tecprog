#pragma once
#include "stdafx.h"
#include "Personagem.hpp"

#define JOGADOR_PATH "./assets/Jogador/player.24x24.png"

#define TAM_SECAO 24
#define QNTD_SECAO 3

#define SEC_INICIAL_X 24
#define SEC_INICIAL_Y 0

#define SEC_FINAL_X 24
#define SEC_FINAL_Y 48

namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        static int cont;
        int pontos;
        bool joga1;
        float lentidao;

    public:
        Jogador(const float x_inicial = 0, const float y_inicial = 0);
        ~Jogador();

        void escolheCor();
        void operator+=(int pts);
        
        void salvaDataBuffer();
        void executar();

        const int getPontos() const { return pontos; }
    };
} using namespace Personagens;