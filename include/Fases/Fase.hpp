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

        void gerenciarColisoes();
        virtual void criarViajantesMaus() {}
        virtual void criarPortais() {}
        virtual void executar();
        void carregarFigura() {}

        void criarPlataformas();
        void criarCenario() {}
    };

} using namespace Fases;