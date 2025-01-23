#pragma once

#include "stdafx.h"
#include "Fase.hpp"

#define JUPITER_PATH "./assets/Fase/cenario_fase_jupiter.png"

namespace Fases {
    class Jupiter : public Fase {
        private:
            const int maxAberracoesEspaciais;
        public:
            Jupiter();
            ~Jupiter();
            void criarObstaculos();
            void criarPortais();
            void carregarFigura();
            void criarBuracosNegros();
            void criarAlienigenas();
            void criarPilares();

            // void criaAberracoesEspaciais();
    };
} using namespace Fases;