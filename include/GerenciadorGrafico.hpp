#pragma once
#include "stdafx.h"

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
        void mostrar();
        bool getJanelaAberta() const;
        RenderWindow& getJanela() const { return *janela; }

    };

} using namespace Gerenciadores;
