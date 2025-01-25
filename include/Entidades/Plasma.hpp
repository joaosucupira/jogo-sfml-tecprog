#pragma once
#include "Entidade.hpp"

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
        const float rapidez;

    public:
        Plasma(float dx, float dy);
        ~Plasma();

        void executar();
        void salvaDataBuffer(){}

        void setAtivo(bool ativou){ativo = ativou;}
        const bool getAtivo(){return ativo;}

        const float getRapidez(){return rapidez;}
        FloatRect hitBox() const {return getLimites();}

        void deslocar();
        
    };

} using namespace Entidades;
