#pragma once
#include "stdafx.h"

#include "Fase.hpp"

namespace Fases{

    class Lua : public Fase {

        const int maxViajantesMaus;

    public:
        Lua();
        ~Lua();

        void criarViajantesMaus() {}
        void carregarFigura() {}

    };


}using namespace Fases;
