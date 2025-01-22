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
        virtual ~Fase();

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
        

        // virtual void criarInimigos() = 0;
        // virtual void criarObstaculos() = 0;
        void criarPortais();
        void criarBuracosNegros();
        
        virtual void carregarFigura() = 0; 
        void criarCenario() {} // chamar carregar figura
        void setJogador(Jogador* pJ);

    };

} using namespace Fases;