
#pragma once
#include "stdafx.h"

#include "Entidade.hpp"

namespace Obstaculos{

    class Obstaculo : public Entidade {
        
        bool danoso;

    public: 

        Obstaculo(const float x, const float y);
        ~Obstaculo();

        virtual void executar() = 0;
        
    };
} using namespace Obstaculos;