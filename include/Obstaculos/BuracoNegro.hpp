#pragma once
#include "stdafx.h"

#include "Obstaculo.hpp"

#define BURACO_NEGRO_PATH "./assets/Obstaculo/B_Negro_100x100px.png"
#define BURACO_NEGRO_LADO 100

namespace Obstaculos{

    class BuracoNegro : public Obstaculo {
        
        float forca;

    public:

        BuracoNegro(const float x_inicial, const float y_inicial);
        ~BuracoNegro();

        /*----------------------------------------------------------------------------*/
        void executar();
        void salvar();
        
        void obstacular(Jogador* pJ);
        void obstacular(Inimigo* pI) {}

        void puxar(Jogador* pJ, float dt);
        
    };
} using namespace Obstaculos;