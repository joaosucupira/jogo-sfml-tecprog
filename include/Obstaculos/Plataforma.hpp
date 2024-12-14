#pragma once
#include "stdafx.h"

#include "Obstaculo.hpp"

namespace Obstaculos{

    class Plataforma : public Obstaculo{

        int altura;

    public: 

        Plataforma();
        ~Plataforma();

        void executar(){}
    };
} using namespace Obstaculos;