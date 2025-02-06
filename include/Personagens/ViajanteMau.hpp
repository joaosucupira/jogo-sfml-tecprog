#pragma once
#include "stdafx.h"

#include "Inimigo.hpp"
#include "Jogador.hpp"

// TROCAR PARA SPRITE DE ViajanteMau
#define VIAJANTE_MAU_PATH "./assets/Inimigo/mini_demon_48x48.png"
#define TAM_SECAO_VM 48
#define QNTD_SECAO_X_VM 4
#define QNTD_SECAO_Y_VM 1

#define SEC_INICIAL_X_VM 0
#define SEC_INICIAL_Y_VM 0

#define SEC_FINAL_X_VM 144
#define SEC_FINAL_Y_VM 0

#define V_VIAJANTE 0.7
#define TAM_VIAJANTE 80.0f

namespace Personagens{

    class ViajanteMau : public Inimigo {

        static Jogador* pJog;
        const int lerdeza;
        bool planando;

    public:

        ViajanteMau(const float x_inicial, const float y_inicial);
        ~ViajanteMau();

        /*----------------------------------------------------------------------------*/
        void danificar(Jogador* pJ);
        void executar();
        void salvar();
        FloatRect hitBox() const;

        static void limparJog(){pJog = NULL;}
        /*SET*/
        static void setPJog(Jogador* pJ);
        void setPlanando(bool planou){ planando = planou;}

    private:

        void mover();
        void seguirJogador();
        void planar();
        
    };

} using namespace Personagens;