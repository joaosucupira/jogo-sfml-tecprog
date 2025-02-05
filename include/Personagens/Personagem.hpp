#pragma once
#include "stdafx.h"
#include "Entidade.hpp"

namespace Personagens {

    class Personagem : public Entidade {

    protected:

        int num_vidas;
        bool vivo;
        bool andando;

    public:

        Personagem(const float x_inicial = 0, const float y_inicial = 0);
        ~Personagem();

        /*----------------------------------------------------------------------------*/
        virtual void executar() = 0;
        virtual FloatRect hitBox() const;

        /*----------------------------------------------------------------------------*/
        void calcVivo() { vivo = (num_vidas > 0 ? true : false); }
        void parar();

        /*SET*/
        void setVidas(const int vidas) { num_vidas = vidas; }
        void setAndando(bool andou){ andando = andou;}

        /*GET*/
        const int getVidas() const { return num_vidas;}
        const bool getVivo() const { return vivo;}
        const bool getAndando() const {return andando;}
       
        /*----------------------------------------------------------------------------*/
        void operator--();
        void operator--(const int dano);

    protected:

        virtual void mover();
        void atualizarFigura();

    };

} using namespace Personagens;