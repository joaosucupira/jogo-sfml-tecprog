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
        Janela* janela;
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

        void incluiEnte(Ente *pE);
        void executar();

    };

} using namespace Gerenciadores;
