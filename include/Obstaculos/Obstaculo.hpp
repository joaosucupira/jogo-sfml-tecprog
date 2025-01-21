
#pragma once
#include "stdafx.h"
#include "Jogador.hpp"

#include "Entidade.hpp"

namespace Obstaculos{

    class Obstaculo : public Entidade {
    protected:
        int* sentidos;
        bool danoso;

    public: 

        Obstaculo(const float x = 0.0f, const float y = 0.0f);
        virtual ~Obstaculo();

        // 8/1 - Inclusao do metodo virtual da linhagem de obstaculos
        virtual void obstacular(Jogador* pJ) = 0;
        virtual void executar() = 0;
        void setSentidos(int* s);
        
    };
} using namespace Obstaculos;