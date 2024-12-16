#pragma once
#include "stdafx.h"

#include "Inimigo.hpp"
#include "Jogador.hpp"

namespace Personagens{

    class Alienigena : public Inimigo {

        float raio;

    public:

        Alienigena();
        ~Alienigena();

        void danificar(Jogador* pJ){}
        void executar(){}
    };

} using namespace Personagens;
