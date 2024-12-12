#pragma once
#include "stdafx.h"

class Ente;

namespace Gerenciadores {

    class GerenciadorEventos;
    class GerenciadorColisoes;

    class GerenciadorGrafico
    {
    private:
        RenderWindow* pJanela;
        Ente *pEnte;
        float deltaTime;

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
        void setGE(GerenciadorEventos* pGE);
        void setGC(GerenciadorColisoes* pGC);

        RenderWindow* getPJanela() const;

        void incluiEnte(Ente *pE);

        // usando para corrigir atualizarSprite()
        const float getDeltaTime() const { return deltaTime; } 

        void executar();

    };

} using namespace Gerenciadores;
