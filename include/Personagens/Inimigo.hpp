#pragma once
#include "stdafx.h"

#include "Personagem.hpp"
#include "Jogador.hpp"

namespace Personagens {

    class Inimigo : public Personagem {

    protected:

        int maldade;

    public:

        Inimigo(const float x_inicial, const float y_inicial);
        virtual ~Inimigo();
        
        /*----------------------------------------------------------------------------*/
        virtual void executar() = 0;
        virtual void salvar() = 0;
        virtual void danificar(Jogador* pJ) = 0;
        virtual FloatRect hitBox() const = 0;

        /*GET*/
        const int getMaldade() const {return maldade;}
    };
} using namespace Personagens;