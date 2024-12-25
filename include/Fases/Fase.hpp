#pragma once
#include "stdafx.h"

#include "Ente.hpp"
#include "Plataforma.hpp"
#include "GerenciadorColisoes.hpp"
#include "ListaEntidades.hpp"

namespace Fases {
    
    class Fase : public Ente
    {
    private:

        GerenciadorColisoes GC;
        ListaEntidades entidades;

    public:
        Fase();
        ~Fase();

        void gerenciarColisoes();
        virtual void executar();
        void criarPlataformas();

        // TODO

        // virtual void criarViajantesMaus() {}
        // virtual void criarPortais() {}
        void carregarFigura() {}
        // void criarCenario() {}
    };

} using namespace Fases;