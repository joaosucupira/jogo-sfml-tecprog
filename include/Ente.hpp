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
    RectangleShape* corpo;
    Figura* figura;

    static GerenciadorGrafico* pGG;
public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;

    void desenhar();
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    void setId(const int i) { id = i; }
    void setCorpo(RectangleShape* pC);


    const int getId() const { return id; }
    Figura* getFigura() { return figura; }

    const float getTamX() const { return corpo->getSize().x; } //testar ponteiro ( só chamar o método getTamX da figura!!!)
    const float getTamY() const { return corpo->getSize().y; } //testar ponteiro ( só chamar o método getTamX da figura!!!)



    // tirar isso (colocar o RectangleShape na Figura)
    RectangleShape* getCorpo() const { return corpo;}

};


