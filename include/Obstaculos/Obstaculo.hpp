
#pragma once
#include "stdafx.h"

#include "Entidade.hpp"

namespace Obstaculos{

    class Obstaculo : public Entidade {
        
        bool danoso;

    public: 

        Obstaculo(const bool dano);
        ~Obstaculo();

        virtual void executar() = 0;
        
    };
}using namespace Obstaculos;