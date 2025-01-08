
#pragma once
#include "stdafx.h"
#include "Jogador.hpp"

#include "Entidade.hpp"

namespace Obstaculos{

    class Obstaculo : public Entidade {
        
        bool danoso;

    public: 

        Obstaculo(const float x, const float y);
        ~Obstaculo();

        // 8/1 - Inclusao do metodo virtual da linhagem de obstaculos
        virtual void obstacular(Jogador* pJ) = 0;
        virtual void executar() = 0;
        
    };
} using namespace Obstaculos;