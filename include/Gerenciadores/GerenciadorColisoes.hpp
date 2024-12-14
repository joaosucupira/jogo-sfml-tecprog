#pragma once
#include "stdafx.h"
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Gerenciadores{
    class GerenciadorColisoes
    {
    private:
        Jogador* pJog1;
        
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();

        void executar();

        void colisaoJogadorJanela();

        void setPJogador(Jogador *pJ1);

    };
} using namespace Gerenciadores;

