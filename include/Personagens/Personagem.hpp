#pragma once
#include "stdafx.h"
#include "Entidade.hpp"

namespace Personagens {
class Personagem : public Entidade
{
protected:
    int num_vidas;
    bool vivo;
    Vector2f velocidade;
    bool estaAndando;
    bool estaPulando;

public:
    Personagem(const float x_inicial = 0, const float y_inicial = 0);
    ~Personagem();
    
    virtual void executar() = 0;
    virtual void mover();

    void setVidas(const int vidas) { num_vidas = vidas; }
    void calcVivo() { vivo = (num_vidas >= 0 ? true : false); }
    void setVelocidadeX(float x){ velocidade.x = x;}
    void setVelocidadeY(float y){ velocidade.y = y;}
    void setEstaPulando(bool pulou){ estaPulando = pulou;}
    void setEstaAndando(bool andou){ estaAndando = andou;}
    void atualizaVelocidade(Vector2f num) {velocidade.x *= num.x; velocidade.y *= num.y;}
    void atualizaParaFiguraInicial();
    
    const int getVidas() const { return num_vidas;}
    const bool getVivo() const { return vivo;}
    Vector2f getVelocidade() const { return velocidade;}
    const bool getEstaPulando() const {return estaPulando;}
    const bool getEstaAndando() const {return estaAndando;}

    /* Adaptar valor de vida a ser retirado no proprio operador*/
    void operator--() { (num_vidas > 0) ? num_vidas-- : vivo = false;}

    void aplicarGravidade();

    void atualizarFigura();
    void figuraInicial();
    

};
} using namespace Personagens;