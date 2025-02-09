/**CREDITOS: Inspirado no trabalho do antigo monitor de Técnicas de Programaçao
 * Matheus Burda, principalmente no que tange o uso do padrao de projeto
 * Single-ton**/


#pragma once
#include "stdafx.h"

class Ente;

namespace Gerenciadores {
    
    class GerenciadorGrafico {

    private:

        RenderWindow* pJanela;
        float deltaTime;
        static GerenciadorGrafico* instancia; 

        GerenciadorGrafico(); 

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia();

        /*----------------------------------------------------------------------------*/

        void desenharEnte(Ente* pE);
        void limparJanela();
        void exibirNaJanela();
        void fecharJanela();

        /*SET*/
        void setDeltaTime(const float dt) { deltaTime = dt; }

        /*GET*/
        RenderWindow* getPJanela() const;
        const float getDeltaTime() const { return deltaTime; } 
        const bool getJanelaAberta() const;

    };

} using namespace Gerenciadores;
