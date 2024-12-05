#pragma once
#include "stdafx.h"
#include "Janela.hpp"

class Ente;

namespace Gerenciadores {
    class GerenciadorGrafico
    {
    private:
        sf::RenderWindow* janela;

        /* Singleton */
        static GerenciadorGrafico* instancia; 
        GerenciadorGrafico(); 

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia(); 
        void limparJanela();

        void desenharEnte(Ente* pE);
        void desenharEnte(Ente* pE, Janela* pJ);
        void mostrar();
        void setJanela(RenderWindow& j) { janela = &j; }

        bool getJanelaAberta() const;
        RenderWindow& getJanela() const { return *janela; }

    };

} using namespace Gerenciadores;
