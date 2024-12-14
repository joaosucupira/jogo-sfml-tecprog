
#pragma once
#include "stdafx.h"

#include "Entidade.hpp"

namespace Obstaculos{

    class Obstaculo : public Entidade {

        bool danoso;

    public: 

        Obstaculo();
        ~Obstaculo();

        virtual void executar() = 0;
        
    };
}using namespace Obstaculos;