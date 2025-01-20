#pragma once
#include "stdafx.h"

#include "Ente.hpp"
#include "Plataforma.hpp"
#include "Alienigena.hpp"
#include "Portal.hpp"
#include "BuracoNegro.hpp"
#include "GerenciadorColisoes.hpp"
#include "ListaEntidades.hpp"
#include "GerenciadorEventos.hpp"

#define AJUSTE_CENTRO 250.0f

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
        void criarPlataformasA();
        void criarPlataformasB();

        void construirPlano(const int tamanho, Vector2f inicio);

        void criarAlienigenas();
        void criarAlienigenasA();
        void criarAlienigenasB();
        

        // virtual void criarViajantesMaus() {}
        void criarPortais();
        void criarBuracosNegros();
        
        void carregarFigura() {}
        void setJogador(Jogador* pJ);
        // void criarCenario() {}
    };

} using namespace Fases;