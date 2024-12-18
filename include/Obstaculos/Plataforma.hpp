#pragma once
#include "stdafx.h"

#include "Obstaculo.hpp"

#define PLATAFORMA_PATH "./assets/Obstaculo/plataforma.24x24.png"
#define PLATAFORMA_LADO 24

namespace Obstaculos{

    class Plataforma : public Obstaculo{

        int altura, largura;

    public: 

        Plataforma(const int a, const int l);
        ~Plataforma();

        void executar();
    };
} using namespace Obstaculos;