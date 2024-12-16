#pragma once
#include "stdafx.h"

#include "Ente.hpp"
#include "GerenciadorColisoes.hpp"

namespace Fases {
    
    class Fase : public Ente
    {
    private:

        GerenciadorColisoes GC;

    public:
        Fase();
        ~Fase();

        virtual void criarInimigosMedios() = 0;
    };

} using namespace Fases;