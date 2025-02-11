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

        void criarPlataformas();
        void criarBuracosNegros();

        void criarViajantesMaus();
        void criarAberracoesEspaciais();
        void criarPlasmas(const int dano);

        void recuperarBuracosNegros();

        void recuperarViajantesMaus();
        void recuperarAberracoesEspaciais();
        void recuperarPlasmas();

        void configurarJogador();

        void colorirPlataformas();
        void definirGravidade();
        void configurarPerseguido();
        
        void atualizaPerseguido();
    };

} using namespace Fases;