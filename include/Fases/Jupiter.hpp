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

            // void criaAberracoesEspaciais();
            // void criarBuracosNegros();
    };
} using namespace Fases;