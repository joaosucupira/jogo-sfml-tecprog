#pragma once
#include "stdafx.h"

#include "Inimigo.hpp"
#include "Jogador.hpp"

// TROCAR PARA SPRITE DE ViajanteMau
#define ViajanteMau_PATH "./assets/Inimigo/Alienigena-24x24.png"

#define TAM_SECAO 24
#define QNTD_SECAO_X 2
#define QNTD_SECAO_Y 3

#define SEC_INICIAL_X 0
#define SEC_INICIAL_Y 0

#define SEC_FINAL_X 24
#define SEC_FINAL_Y 48

#define V_VIAJANTE 0.5

namespace Personagens{

    class ViajanteMau : public Inimigo {

        static Jogador* pJog;
        const int lerdeza;

    public:

        ViajanteMau(const float x_inicial, const float y_inicial);
        ~ViajanteMau();

        void carregarFigura();

        void danificar(Jogador* pJ);
        void executar();
        void salvaDataBuffer();
        
        void seguirJogador();
        static void setPJog(Jogador* pJ);
        void planar();
        
    };

} using namespace Personagens;