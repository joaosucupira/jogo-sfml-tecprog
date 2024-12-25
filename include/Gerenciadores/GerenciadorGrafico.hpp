#pragma once
#include "stdafx.h"

class Ente;

namespace Obstaculos { class Plataforma; }
// class Plataforma;


namespace Gerenciadores {
    
    class GerenciadorEventos;
    // class GerenciadorColisoes; // Removendo o gerenciador de colisões que deve estar desacoplado

    class GerenciadorGrafico
    {
    private:
        // Ente* listaEntes[3]; // deve ser lista de entidades
        RenderWindow* pJanela;
        // Ente *pEnte;

        float deltaTime;

        GerenciadorEventos *pGeventos;
        // GerenciadorColisoes *pGcolisoes;

        /* Singleton */
        static GerenciadorGrafico* instancia; 
        GerenciadorGrafico(); 

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia(); 

        void desenharEnte(Ente* pE);

        /* Compartilhamento da classe Janela*/
        void setGE(GerenciadorEventos* pGE);
        // void setGC(GerenciadorColisoes* pGC);

        RenderWindow* getPJanela() const;

        // void incluiEnte(Ente *pE);
        void incluiEnte(Ente* pE, int i);

        // usando para corrigir atualizarSprite()
        const float getDeltaTime() const { return deltaTime; } 
        // Ente* getListaEntes() const { return *(listaEntes); }

        void executar();

    };

} using namespace Gerenciadores;
