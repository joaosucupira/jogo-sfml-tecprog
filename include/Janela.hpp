/*
* AUTOR: João Sucupira
* DESCRIÇÃO: Classe de agregação da janela do jogo manejada pelos gerenciadores
* que manipulam a mesma RenderWindow sempre precisar instanciar outra dentro de si
*/

#pragma once
#include "stdafx.h"

class Janela
{
private:
    RenderWindow* janela;
public:
    Janela();
    ~Janela();

    RenderWindow* getJanela() const;
};

