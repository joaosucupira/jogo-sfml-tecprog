#pragma once
#include "stdafx.h"

#include "Inimigo.hpp"
#include "Jogador.hpp"

// TROCAR PARA SPRITE DE ALIENIGENA
#define ALIENIGENA_PATH "./assets/Jogador/player.24x24.png"

#define TAM_SECAO 24
#define QNTD_SECAO 3

#define SEC_INICIAL_X 24
#define SEC_INICIAL_Y 0

#define SEC_FINAL_X 24
#define SEC_FINAL_Y 48

namespace Personagens{

    class Alienigena : public Inimigo {

        float raio;

    public:

        Alienigena(const float x_inicial, const float y_inicial);
        ~Alienigena();

        void carregarFigura();

        void danificar(Jogador* pJ) {}
        void executar();
        void salvaDataBuffer();
    };

} using namespace Personagens;
