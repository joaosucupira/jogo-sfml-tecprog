#pragma once
#include "stdafx.h"

#include "Personagem.hpp"
#include "Jogador.hpp"

namespace Personagens {

    class Inimigo : public Personagem {

    protected:

        int maldade;

    public:

        Inimigo();
        ~Inimigo();

        void salvaDataBuffer(){}
        virtual void executar() = 0;
        virtual void danificar(Jogador* pJ) = 0;
    };
} using namespace Personagens;