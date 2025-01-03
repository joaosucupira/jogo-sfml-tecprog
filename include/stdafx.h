// ARQUIVO COM TODAS AS BIBLIOTECAS E MACROS NECESCESSÁRIAS
// ! -> .h  ao invés de .hpp para identificar um arquivo biblioteca ou gabarito

#pragma once

/* Includes */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <math.h>

/* Namespaces */
using namespace std;
using namespace sf;

/* Macros */
#define TAXA_QUADROS 100
#define LARGURA 1260
#define ALTURA 580

#define GRAVIDADE 9.8 //(m/s^2)
#define PIXEL_METRO 300 // Conversão metros para pixels
#define CHAO 570// Posição Y que representa o chão (pixels)
#define ALTURA_PULO 0.8 // Altura máxima do pulo do jogador (m)
#define VELOCIDADE_ANDAR 1.0 // Velocidade de andar do jogador (m/s)
#define COLISAO 0.1 //Sempre Positiva

/* Macros - Tamanhos*/
#define TAM_JOGADOR 200.0f
#define ALT_PLATAFORMA  100.0f


