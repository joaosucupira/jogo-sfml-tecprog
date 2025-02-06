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
#include <filesystem>

/* Namespaces */
using namespace std;
using namespace sf;
using namespace std::filesystem;

/* Macros */
#define TAXA_QUADROS 60
#define LARGURA 1260
#define ALTURA 680

#define PIXEL_METRO 300.0 // Conversão metros para pixels
#define CHAO 570// Posição Y que representa o chão (pixels)
#define ALTURA_PULO 0.8 // Altura máxima do pulo do jogador (m)
#define VELOCIDADE_ANDAR 1.0 // Velocidade de andar do jogador (m/s)
#define COLISAO 30 //Sempre Positiva
#define ALTURA_COLI 0.2 //Altura da colisao do jogador com alienigena
#define KNOCK_BACK 4

/* Macros - Tamanhos*/
#define TAM_JOGADOR 80.0f
#define LARG_PLATAFORMA 64.0f
#define ALT_PLATAFORMA 64.0f
#define TAM_PORTAL 80.0f
#define TAM_BURACO_NEGRO 140.0f

/*Macors - path arquivos salvar*/
#define BURACO_NEGRO_SALVAR_PATH "./data/salvamento/buraco_negro.txt"
#define PLATAFORMA_SALVAR_PATH "./data/salvamento/plataforma.txt"
#define PORTAL_SALVAR_PATH "./data/salvamento/portal.txt"
#define ABERRACAO_ESPACIAL_SALVAR_PATH "./data/salvamento/aberracao_espacial.txt"
#define ALIENIGENA_SALVAR_PATH "./data/salvamento/alienigena.txt"
#define JOGADOR_SALVAR_PATH "./data/salvamento/jogador.txt"
#define VIAJANTE_MAU_SALVAR_PATH "./data/salvamento/viajante_mau.txt"
#define PLASMA_SALVAR_PATH "./data/salvamento/plasma.txt"

#define LEADERBOARD_PATH "./data/leaderBoard/leaderBoard.txt"



