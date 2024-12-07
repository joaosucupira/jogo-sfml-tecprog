#pragma once
#include "stdafx.h"
#include "Janela.hpp"

class Ente;

namespace Gerenciadores {

    class GerenciadorEventos;
    class GerenciadorColisoes;

    class GerenciadorGrafico
    {
    private:
        Janela* pJanela;
        Ente *pEnte;
        Clock relogio;

        GerenciadorEventos *pGeventos;
        GerenciadorColisoes *pGcolisoes;

        /* Singleton */
        static GerenciadorGrafico* instancia; 
        GerenciadorGrafico(); 

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia(); 

        void desenharEnte(Ente* pE);

        /* Compartilhamento da classe Janela*/
        void setJanela(Janela* pJ);
        void setGE(GerenciadorEventos* pGE);
        void setGC(GerenciadorColisoes* pGC);

        RenderWindow* getRenderWindow() const;

        void incluiEnte(Ente *pE);
        void executar();

    };

} using namespace Gerenciadores;
