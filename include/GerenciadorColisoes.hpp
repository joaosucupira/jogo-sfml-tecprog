#pragma once
#include "stdafx.h"
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Gerenciadores{
    class GerenciadorColisoes
    {
    private:
        Jogador* pJog1;
        //const float gravidade;
        //Clock* pRelogio;
        
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        void executar();

        void colisaoJogadorChao();
        void colisaoJogadorParede();

        Jogador* getJogador() const;

    };
} using namespace Gerenciadores;

