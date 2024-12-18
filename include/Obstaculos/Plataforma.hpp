#pragma once
#include "stdafx.h"

#include "Obstaculo.hpp"

#define PLATAFORMA_PATH "./assets/Obstaculo/plataforma.24x24.png"
#define PLATAFORMA_LADO 24

namespace Obstaculos{

    class Plataforma : public Obstaculo{

        int altura;

    public: 

        Plataforma(const int x_inicial, const int y_inicial);
        ~Plataforma();

        void salvaDataBuffer();
        void carregarFigura();
        void executar();
    };
} using namespace Obstaculos;