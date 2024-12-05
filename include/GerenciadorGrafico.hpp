#pragma once
#include "stdafx.h"
#include "Janela.hpp"

class Ente;

namespace Gerenciadores {
    class GerenciadorGrafico
    {
    private:
        RenderWindow* janela;

        /* Singleton */
        static GerenciadorGrafico* instancia; 
        GerenciadorGrafico(); 

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia(); 

        void desenharEnte(Ente* pE);

        /* Compartilhamento da classe Janela*/
        void setJanela(Janela* pJ);

    };

} using namespace Gerenciadores;
