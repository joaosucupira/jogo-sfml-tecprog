
#pragma once
#include "stdafx.h"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Plasma.hpp"

#include "Entidade.hpp"

namespace Obstaculos{

    class Obstaculo : public Entidade {
        
    protected:
        
        bool danoso;

    public: 

        Obstaculo(const float x_inicial = 0.0f, const float y_inicial = 0.0f);
        virtual ~Obstaculo();

        /*----------------------------------------------------------------------------*/
        virtual void executar() = 0;

        // 8/1 - Inclusao do metodo virtual da linhagem de obstaculos
        virtual void obstacular(Jogador* pJ) = 0;
        virtual void obstacular(Inimigo* pI) = 0;
        
        /*----------------------------------------------------------------------------*/
        FloatRect hitBox() const;
        
    };
} using namespace Obstaculos;