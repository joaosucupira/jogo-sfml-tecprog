#pragma once
#include "Entidade.hpp"
#include "Jogador.hpp"

#define PLASMA_PATH "./assets/Projeteis/bolt1_strip.png"
#define PLASMA_TAM_SEC 10
#define PLASMA_ALTURA 10

#define LARG_PLASMA 20
#define ALT_PLASMA 20

#define V_PLASMA 15

namespace Entidades {

    class Plasma : public Entidade
    {
        
        bool ativo; 
        int dano;

    public:

        Plasma(float x_inicial, float y_inicial);
        Plasma(const int dano = 0);
        ~Plasma();

        /*----------------------------------------------------------------------------*/

        void executar();
        void salvar();
        void queimar(Jogador *pJ);

        /*SET*/
    
        void setAtivo(bool ativou){ativo = ativou;}
        void setDano(int d){dano = d;}

        /*GET*/

        const bool getAtivo()const {return ativo;}
        const int getDano()const {return dano;}
        const float getRapidez(){return antiGrav;}

        FloatRect hitBox() const {return getLimites();}

    private:

        void deslocar();
    
        
    };

} using namespace Entidades;
