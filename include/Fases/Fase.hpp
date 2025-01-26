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
#include "ViajanteMau.hpp"
#include "AberracaoEspacial.hpp"
#include "Plasma.hpp"

#define AJUSTE_CENTRO 250.0f

namespace Fases {
    
    class Fase : public Ente
    {
    protected:
        bool ativa;
        float gravidade;
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
        void executar();
        void criarPlataformas();

        void construirPlano(const float tamanho, Vector2f inicio);
        void construirParede(const float tamanho, Vector2f inicio);
    
        // virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;
        virtual void criarPortais() = 0;
        virtual void criarAlienigenas() = 0;
        virtual void criarViajantesMaus() = 0;
        
        virtual void carregarFigura() = 0; 
        void criarCenario();
        void setJogador(Jogador* pJ);

    };

} using namespace Fases;