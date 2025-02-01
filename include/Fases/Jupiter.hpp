#pragma once

#include "stdafx.h"
#include "Fase.hpp"

#define JUPITER_PATH "./assets/Fase/cenario_fase_jupiter.png"

namespace Fases {

    class Jupiter : public Fase {

        const int maxAberracoesEspaciais;

    public:
        Jupiter();
        ~Jupiter();

        /*----------------------------------------------------------------------------*/
        void executar();
        void criar();
        void recuperar();

    private:

        void criarInimigos();
        void criarObstaculos();

        void criarPortais();
        void criarPlataformas();
        void criarBuracosNegros();

        void criarAlienigenas();
        void criarViajantesMaus();
        void criarAberracoesEspaciais();
        void criarPlasmas();

        void colorirPlataformas();
        void definirGravidade();
        void configurarPerseguido();
        
        void atualizaPerseguido();
    };

} using namespace Fases;