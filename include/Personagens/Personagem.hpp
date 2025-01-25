#pragma once
#include "stdafx.h"
#include "Entidade.hpp"

namespace Personagens {
class Personagem : public Entidade
{
protected:
    int num_vidas;
    bool vivo;
    
    bool estaAndando;
    bool estaPulando;

public:
    Personagem(const float x_inicial = 0, const float y_inicial = 0);
    ~Personagem();
    
    virtual void executar() = 0;
    virtual void mover();

    void setVidas(const int vidas) { num_vidas = vidas; }
    void calcVivo() { vivo = (num_vidas >= 0 ? true : false); }
    void setEstaPulando(bool pulou){ estaPulando = pulou;}
    void setEstaAndando(bool andou){ estaAndando = andou;}

    /* Adaptar valor de vida a ser retirado no proprio operador*/
    void operator--();
    void operator--(const int dano);
    
    const int getVidas() const { return num_vidas;}
    const bool getVivo() const { return vivo;}
    const bool getEstaPulando() const {return estaPulando;}
    const bool getEstaAndando() const {return estaAndando;}

    void atualizarFigura();
    virtual FloatRect hitBox() const;
    

};
} using namespace Personagens;