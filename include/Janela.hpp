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

    void fechar() { janela->close(); }
    void limpar (const Color& cor = Color::Black) { janela->clear(); }
    void exibir() { janela->display(); }

    RenderWindow* getJanela() const;
    const bool aberta() const { return janela->isOpen(); }

};

