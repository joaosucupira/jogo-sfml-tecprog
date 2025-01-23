#pragma once

#include "stdafx.h"
#include "Fase.hpp"

namespace Fases {
    class Jupiter : public Fase {
        private:
            const int maxAberracoesEspaciais;
        public:
            Jupiter();
            ~Jupiter();
            void criarObstaculos();
            void criarPortais();
            void carregarFigura() {}
            void criarBuracosNegros();
            

            // void criaAberracoesEspaciais();
            // void criarBuracosNegros();
    };
} using namespace Fases;