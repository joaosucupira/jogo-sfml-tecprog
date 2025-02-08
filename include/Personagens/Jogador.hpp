#pragma once
#include "stdafx.h"
#include "Personagem.hpp"
#include "Sujeito.hpp"

#define JOGADOR_PATH "./assets/Jogador/player.24x24.png"

#define TAM_SECAO 24
#define QNTD_SECAO 3

#define SEC_INICIAL_X 24
#define SEC_INICIAL_Y 0

#define SEC_FINAL_X 24
#define SEC_FINAL_Y 48

namespace Personagens {

    class Jogador : public Personagem, public Sujeito {

        static int cont;
        int pontos;
        bool ehJog1;
        bool pulando;
        int idFase;
        std::string nome;

    public:

        Jogador(const float x_inicial = 0, const float y_inicial = 0);
        ~Jogador();

        /*----------------------------------------------------------------------------*/
        void executar();
        void salvar();
        void escolheCor();
        FloatRect hitBox() const;

        /*SET*/
        void setPulando(bool pulou){ pulando = pulou;}
        void setPontos(const int pts){ pontos = pts;}
        void setIdFase(const int idFs){idFase = idFs;}
        void setNome(const string n){ nome = n;}

        /*GET*/
        const int getPontos() const { return pontos; }
        const bool getPulando() const {return pulando;}
        const int getIdFase() const {return idFase;}
        const string getNome() const {return nome;}

        /*----------------------------------------------------------------------------*/
        void operator+=(int pts);
        void operator--();
        void operator--(const int dano);

    };
} using namespace Personagens;