#pragma once
#include "stdafx.h"

#include "Obstaculo.hpp"

#define PLATAFORMA_PATH "./assets/Obstaculo/plataforma.24x24.png"
#define PLATAFORMA_LARGURA 72
#define PLATAFORMA_ALTURA 72 

namespace Obstaculos {

    class Plataforma : public Obstaculo{

        int altura;

    public: 

        Plataforma(const int x_inicial, const int y_inicial);
        ~Plataforma();

        void obstacular(Jogador* pJ);
        void salvaDataBuffer();
        void carregarFigura();
        void executar();
        void atualizarFigura() {}
    };
} using namespace Obstaculos;