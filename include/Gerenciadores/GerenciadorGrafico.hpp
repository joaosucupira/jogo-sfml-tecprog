#pragma once
#include "stdafx.h"

class Ente;

namespace Obstaculos { class Plataforma; }


namespace Gerenciadores {

    class GerenciadorGrafico
    {
    private:
        RenderWindow* pJanela;
        float deltaTime;
        static GerenciadorGrafico* instancia; 
        GerenciadorGrafico(); 

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia(); 
        void desenharEnte(Ente* pE);
        RenderWindow* getPJanela() const;
        const float getDeltaTime() const { return deltaTime; } 
        void executar();
        const bool getJanelaAberta() const;
        void limparJanela();
        void exibirNaJanela();
        void fecharJanela();
        void setDeltaTime(const float dt) { deltaTime = dt; }
        void exibirHitBox(FloatRect lim);

    };

} using namespace Gerenciadores;
