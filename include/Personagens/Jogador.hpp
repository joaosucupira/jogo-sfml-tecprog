#pragma once
#include "stdafx.h"
#include "Personagem.hpp"

#define JOGADOR_PATH "./assets/Jogador/player.24x24.png"
#define JOGADOR_SALVAR_PATH "./data/jogador.txt"
#define TAM_SECAO 24
#define QNTD_SECAO 3

#define SEC_INICIAL_X 24
#define SEC_INICIAL_Y 0

#define SEC_FINAL_X 24
#define SEC_FINAL_Y 48

namespace Personagens {

    class Jogador : public Personagem {

        static int cont;
        int pontos;
        bool ehJog1;
        bool pulando;

    public:

        Jogador(const float x_inicial = 0, const float y_inicial = 0);
        ~Jogador();

        /*----------------------------------------------------------------------------*/
        void executar();
        void salvar();
        void escolheCor();

        /*SET*/
        void setPulando(bool pulou){ pulando = pulou;}

        /*GET*/
        const int getPontos() const { return pontos; }
        const bool getPulando() const {return pulando;}

        /*----------------------------------------------------------------------------*/
        void operator+=(int pts);

    };
} using namespace Personagens;