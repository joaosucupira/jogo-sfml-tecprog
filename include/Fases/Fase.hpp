#pragma once
#include "stdafx.h"

#include "Ente.hpp"
#include "Plataforma.hpp"
#include "Alienigena.hpp"
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
        void criarAlienigenas();
        // TODO

        // virtual void criarViajantesMaus() {}
        // virtual void criarPortais() {}
        void carregarFigura() {}
        void setJogador(Jogador* pJ);
        // void criarCenario() {}
    };

} using namespace Fases;