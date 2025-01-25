/* Classe abstrata PURA que deriva a maior parte dos objetos instanciados
* Derivam de Ente:
* - Entidade
* - Fase
* - Menu
*/

#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.hpp"
#include "Figura.hpp"

class Ente
{
protected:
    static int cont_id;
    int id;

    Figura* figura;
    static GerenciadorGrafico* pGG;
public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    
    virtual void atualizarFigura();

    void desenhar();
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    void setId(const int i) { id = i; }

    const int getId() const { return id; }
    Figura* getFigura() { return figura; }
    FloatRect getLimites() const; //sprite

    void setPosicaoFigura(const float x, const float y);
    void setTamanhoFigura(const float x, const float y);
    void setCorFigura(const Color& cor);
    void atualizaParaFiguraInicial();
    
    void carregarFigura(string pathTextura);
    
    //virtual FloatRect hitBox() = 0 //entidade
    //sentidos[4]

};


