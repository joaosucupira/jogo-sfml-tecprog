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

        virtual void criarViajantesMaus() {}
        virtual void criarPortais() {}
        virtual void executar();
        void carregarFigura() {}

        void criarPlataformas();
    };

} using namespace Fases;