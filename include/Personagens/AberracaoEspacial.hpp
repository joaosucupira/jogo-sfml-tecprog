#pragma once
#include "stdafx.h"

#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Plasma.hpp"

// TROCAR PARA SPRITE DE AberracaoEspacial
#define ABERRACAO_ESPACIAL_PATH "./assets/Inimigo/fly-eye_48x48.png"

#define TAM_SECAO_AE 48
#define QNTD_SECAO_X_AE 4
#define QNTD_SECAO_Y_AE 1

#define SEC_INICIAL_X_AE 0
#define SEC_INICIAL_Y_AE 0

#define SEC_FINAL_X_AE 144
#define SEC_FINAL_Y_AE 0

#define V_ABERRACAO 1.5
#define TAM_ABERRACAO 230

namespace Personagens{

    class AberracaoEspacial : public Inimigo {

        static Jogador* pJog;
        static Plasma* pPlasma;
        const int tempRecarregar;
        int recarregando;

    public:

        AberracaoEspacial(const float x_inicial, const float y_inicial);
        ~AberracaoEspacial();

        void danificar(Jogador* pJ);
        void executar();
        void salvaDataBuffer();
        void mover();
        
        static void setPJog(Jogador* pJ);
        static void setPPlasma(Plasma* pPlas);

        //private
        void planar();
        void atirar();
        void recarregar();
        
        void desenharZonaSegura();
        FloatRect hitBox() const;
        
    };

} using namespace Personagens;