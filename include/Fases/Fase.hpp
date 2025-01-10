#pragma once
#include "stdafx.h"

#include "Ente.hpp"
#include "Plataforma.hpp"
#include "Alienigena.hpp"
#include "GerenciadorColisoes.hpp"
#include "ListaEntidades.hpp"
#include "GerenciadorEventos.hpp"

namespace Fases {
    
    class Fase : public Ente
    {
    private:
        
        GerenciadorEventos GE;
        GerenciadorColisoes GC;
        ListaEntidades* entidades;

    public:
        Fase();
        ~Fase();

        // void posicionarEntidade(Entidade* pE, const float x, const float y);
        void renderizarEntidades();
        void gerenciarEventos();
        void gerenciarColisoes();
        virtual void executar();
        void criarPlataformas();
        void construirPlano(const int tamanho, Vector2f inicio);
        void construirParede(const int tamanho, Vector2f inicio);
        void criarAlienigenas();
        // TODO

        // virtual void criarViajantesMaus() {}
        // virtual void criarPortais() {}
        void carregarFigura() {}
        void setJogador(Jogador* pJ);
        // void criarCenario() {}
    };

} using namespace Fases;