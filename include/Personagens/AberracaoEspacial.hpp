#pragma once
#include "stdafx.h"

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Plasma.hpp"

// TROCAR PARA SPRITE DE AberracaoEspacial
#define ABERRACAO_ESPACIAL_PATH "./assets/Inimigo/Alienigena-24x24.png"

#define TAM_SECAO 24
#define QNTD_SECAO_X 2
#define QNTD_SECAO_Y 3

#define SEC_INICIAL_X 0
#define SEC_INICIAL_Y 0

#define SEC_FINAL_X 24
#define SEC_FINAL_Y 48

#define V_VIAJANTE 0.8

namespace Personagens{

    class AberracaoEspacial : public Inimigo {

        static Jogador* pJog;
        Plasma* pPlasma;
        

    public:

        AberracaoEspacial(const float x_inicial, const float y_inicial);
        ~AberracaoEspacial();

        

        void danificar(Jogador* pJ);
        void executar();
        void salvaDataBuffer();
        void mover();
        
        static void setPJog(Jogador* pJ);
        void setPPlasma(Plasma* pP);

        void planar();
        void atirar();
        
    };

} using namespace Personagens;