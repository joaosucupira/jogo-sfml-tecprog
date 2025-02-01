#pragma once
#include "stdafx.h"

#include "Inimigo.hpp"
#include "Jogador.hpp"

// TROCAR PARA SPRITE DE ALIENIGENA
#define ALIENIGENA_PATH "./assets/Inimigo/Alienigena-24x24.png"
#define ALIENIGENA_SALVAR_PATH "./data/alienigena.txt"
#define TAM_SECAO_ALI 24
#define QNTD_SECAO_X_ALI 2
#define QNTD_SECAO_Y_ALI 3

#define SEC_INICIAL_X_ALI 0
#define SEC_INICIAL_Y_ALI 0

#define SEC_FINAL_X_ALI 24
#define SEC_FINAL_Y_ALI 48

namespace Personagens{

    class Alienigena : public Inimigo {

        float raio;

    public:

        Alienigena(const float x_inicial, const float y_inicial);
        ~Alienigena();
        
        /*----------------------------------------------------------------------------*/
        void danificar(Jogador* pJ);
        void executar();
        void salvar();
        
    };

} using namespace Personagens;
