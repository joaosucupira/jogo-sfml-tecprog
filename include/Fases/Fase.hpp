#pragma once
#include "stdafx.h"

#include "Ente.hpp"
#include "Plataforma.hpp"
#include "GerenciadorColisoes.hpp"

namespace Fases {
    
    class Fase : public Ente
    {
    private:

        GerenciadorColisoes GC;

    public:
        Fase();
        ~Fase();

        virtual void criarInimigosMedios() {}
        virtual void executar();
        void carregarFigura() {}

        void criaPlataformas();
    };

} using namespace Fases;