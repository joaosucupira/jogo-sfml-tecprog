#pragma once
#include "Entidade.hpp"
#include "Jogador.hpp"

#define PLASMA_PATH "./assets/Obstaculo/plataforma.24x24.png"
#define PLASMA_TAM_SEC 24
#define PLASMA_ALTURA 24

#define LARG_PLASMA 10
#define ALT_PLASMA 20

#define V_PLASMA 15

namespace Entidades {

    class Plasma : public Entidade
    {
        
        bool ativo;
        const float antiGrav; 
        int dano;

    public:

        Plasma(float x_inicial, float y_inicial);
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

        void planar();
        void deslocar();
    
        
    };

} using namespace Entidades;
