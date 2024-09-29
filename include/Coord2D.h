// AUTOR(A) : JOAO SUCUPIRA
// ALTERAÇÕES : ...
/*
* DESCRIÇÃO: Gabarito para coordenadas de duas dimensões (abcissa, ordenada), qualquer objeto no jogo que precise dessa
*            informação geométrica para comunicar-se com possíveis outros, logo, esta classe está presente na pasta src
*            para simplificar seu acesso às demais.
*/
// REFERÊNCIAS: Ex-Monitor da disciplina M.A. Burda: https://github.com/MatheusBurda/Desert
/* MAPA:
*  1- OPERADORES ARITMÉTICOS
*  1.2 - OPERADORES ARITMÉTICOS DE INCREMENTO
*  2- OPERADORES LÓGICOS
*  3- OPERADORES DE ATRIBUIÇÃO
*  4- ATRIBUIÇÃO E OUTROS
*/// ! -> .h  ao invés de .hpp para identificar um arquivo biblioteca ou gabarito

#pragma once

#include <iostream>
using namespace std;

template <typename TC>
class Coord2D
{
public:
    /* data */
    TC x, y;

    Coord2D(TC x0 = 0, TC y0 = 0) : x(x0),  y(y0) 
    {
    }
    ~Coord2D() {}

    // 1- Sobrecarga dos operadores aritméticos 
    Coord2D<TC> operator+(const Coord2D<TC> vSoma) const { return Coord2D(x + vSoma.x, y + vSoma.y); }

    Coord2D<TC> operator-(const Coord2D<TC> vSub) const { return Coord2D(x - vSub.x, y - vSub.y); }

    Coord2D<TC> operator*(const TC k) const { return Coord2D(x * k, y * k); } // k escalar

    Coord2D<TC> operator/(const TC k) const { 
        if (k != 0)
            return Coord2D(x * k, y * k);
        cout << "Divisao por zero em (" << x << ", " << y << ")!" << endl;
        exit(1);
    } // k escalar

    // 1.2 - Sobrecarga de operadores ariméticos com incremento
    void operator+=(const Coord2D<TC> vSoma) {
        x += vSoma.x;
        y += vSoma.y;
    }
    void operator-=(const Coord2D<TC> vSub) {
        x -= vSub.x;
        y += vSub.y;
    }
    void operator*=(const TC k) {
        x *= k;
        y *= k;
    } // k escalar
    void operator/=(const TC k) {
        if (k != 0) {
            x /= k;
            y /= k;
        } else {
            cout << "Divisao por 0 em (" << x << ", " << y << " )" << endl;
        }
    }
    //3- Sobrecarga dos operadores lógicos
    const bool operator<(Coord2D<TC> vComparado) const {
        return (bool) (x < vComparado.x && y < vComparado.y);
    }
    const bool operator>(Coord2D<TC> vComparado) const {
        return (bool) (x > vComparado.x && y > vComparado.y);
    }
    const bool operator==(Coord2D<TC> vComparado) const {
        return (bool) (x == vComparado.x && y == vComparado.y);
    }

    //4 - Sobrecarga de operadores de atribuição e outros mais
    void operator=(Coord2D<TC> vAtribuido) {
        x = vAtribuido.x;
        y = vAtribuido.y;
    }

    typedef Coord2D<float> Vector2f;
    
};

