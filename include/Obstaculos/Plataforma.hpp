#pragma once
#include "stdafx.h"

#include "Obstaculo.hpp"


#define PLATAFORMA_PATH "./assets/Obstaculo/plataforma.24x24.png"
#define PLATAFORMA_LARGURA 24
#define PLATAFORMA_ALTURA 24 

namespace Obstaculos {

    class Plataforma : public Obstaculo{

        int altura;

    public: 

        Plataforma(const int x_inicial, const int y_inicial);
        ~Plataforma();

        void obstacular(Jogador* pJ);
        void obstacular(Inimigo* pI);
        void obstacular(Plasma* pP);
        void salvaDataBuffer();
        
        void executar();
        
    };
} using namespace Obstaculos;