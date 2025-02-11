#pragma once
#include "stdafx.h"
#include "Obstaculo.hpp"

#define PORTAL_PATH "./assets/Obstaculo/Ship_portal_32x32.png"
#define PORTAL_LADO 32

namespace Obstaculos{

    class Portal : public Obstaculo {
        
        float raio;

    public:
        Portal(const float x_inicial = 0.0f, const float y_inicial = 0.0f);
        ~Portal();
        /*----------------------------------------------------------------------------*/
        void salvar();
        void executar();

        void obstacular(Jogador* pJ);
        void obstacular(Inimigo* pI) {}
        void teletransportar(Jogador* pJ);
    };
} using namespace Obstaculos;