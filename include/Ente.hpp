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
    FloatRect* pRect;

    static GerenciadorGrafico* pGG;
public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;

    void desenhar();
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    void setId(const int i) { id = i; }

    const int getId() const { return id; }
    Figura* getFigura() { return figura; }

    FloatRect getLimites() const;

    /*
    const float getTamX() const { return figura->getTamX(); } //testar ponteiro ( só chamar o método getTamX da figura!!!)
    const float getTamY() const { return figura->getTamY(); } //testar ponteiro ( só chamar o método getTamX da figura!!!)
    */

};


