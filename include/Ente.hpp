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
    float deltaTime; //virar static// ele perde a precisao

    static GerenciadorGrafico* pGG;
public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;

    void desenhar();
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    void setId(const int i) { id = i; }
    void setCorpo(RectangleShape* pC);
    void setDeltaTime(float dt){ deltaTime = dt;}


    const int getId() const { return id; }
    const float getDeltaTime() const { return deltaTime; }
    RectangleShape* getCorpo() const { return corpo;}

};


