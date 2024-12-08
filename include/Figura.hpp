/* Classe figura pensada para agregar Sprite e Texture para desacopla-los
*  da classe Ente em um objeto reutilizável.
*/

#pragma once
#include "stdafx.h"

class Figura
{
private:
    Texture* pTextura;
    Sprite* pSprite;
public:
    Figura();
    ~Figura();

    void carregarTextura(string path_sprite);
    void setSprite(string path_sprite);
    Sprite* getSprite() const { return pSprite; }
};

