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

    //static int cont_id;
    //int id;
    Figura* figura;
    static GerenciadorGrafico* pGG;

public:

    Ente();
    virtual ~Ente();

    /*----------------------------------------------------------------------------*/
    virtual void executar() = 0;

    /*SET*/
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    //void setId(const int i) { id = i; }
    void setPosicaoFigura(const float x, const float y);
    void setTamanhoFigura(const float x, const float y);
    void setCorFigura(const Color& cor);

    /*GET*/
    //const int getId() const { return id; }
    Figura* getFigura() const { return figura; }
    FloatRect getLimites() const;
    const float getAjuste() const;

protected:

    virtual void atualizarFigura();

    void desenhar();
    void carregarFigura(string pathTextura);
    void atualizaParaFiguraInicial();

};


