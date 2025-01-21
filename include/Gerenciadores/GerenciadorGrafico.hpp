#pragma once
#include "stdafx.h"

class Ente;

namespace Obstaculos { class Plataforma; }
// class Plataforma;


namespace Gerenciadores {
    
    // class GerenciadorEventos;
    // class GerenciadorColisoes; // Removendo o gerenciador de colisões que deve estar desacoplado

    class GerenciadorGrafico
    {
    private:
        RenderWindow* pJanela;
        float deltaTime;
        // GerenciadorEventos *pGeventos;
        static GerenciadorGrafico* instancia; 
        GerenciadorGrafico(); 

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia(); 

        void desenharEnte(Ente* pE);

        // void setGE(GerenciadorEventos* pGE);

        RenderWindow* getPJanela() const;

        // void incluiEnte(Ente *pE);
        // void incluiEnte(Ente* pE, int i);

        // usando para corrigir atualizarSprite()
        const float getDeltaTime() const { return deltaTime; } 
        // Ente* getListaEntes() const { return *(listaEntes); }

        void executar();

        const bool getJanelaAberta() const;
        void limparJanela();
        void exibirNaJanela();
        void fecharJanela();
        void setDeltaTime(const float dt) { deltaTime = dt; }

        void exibirHitBox(FloatRect lim);

    };

} using namespace Gerenciadores;
