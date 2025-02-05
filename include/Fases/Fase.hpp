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
#include "Jogador.hpp"
#include "Observer.hpp"

#define AJUSTE_CENTRO 250.0f

namespace Fases {
    // Requisitos: Herança dupla e Observer
    class Fase : public Ente, Observer 
    {
    protected:
        Jogador* pJog1;
        Jogador* pJog2;

        bool ativa;
        GerenciadorEventos* pGE;
        GerenciadorColisoes GC;
        ListaEntidades* entidades;
        bool vencida;

    public:
        Fase();
        virtual ~Fase();

        /*----------------------------------------------------------------------------*/
        virtual void executar() = 0;
        virtual void criar() = 0;
        virtual void recuperar() = 0;
        
        void notificar();
        void salvar();
        /*SET*/
        void setJogador(Jogador* pJ, const int num_jogador);
        void setPGEventos(GerenciadorEventos* pG);

    protected:

        virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;

        virtual void criarPlataformas() = 0;
        //virtual void criarPortais() = 0;

        //virtual void criarAlienigenas() = 0;
        virtual void criarViajantesMaus() = 0;

        virtual void recuperarViajantesMaus();
        virtual void recuperarPlataformas();

        
        virtual void definirGravidade() = 0;
        virtual void configurarPerseguido() = 0;

        virtual void atualizaPerseguido() = 0;

        /*----------------------------------------------------------------------------*/
        void recuperarJogador();
        
        void criarCenario();
        void construirPlano(const float tamanho, Vector2f inicio);
        void construirParede(const float tamanho, Vector2f inicio);
        

        void renderizarEntidades();
        void gerenciarEventos();
        void gerenciarColisoes();
    };

} using namespace Fases;