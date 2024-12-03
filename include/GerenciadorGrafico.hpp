#pragma once
#include "stdfax.h"
#include <map>

namespace Gerenciadores {
    class GerenciadorGrafico
    {
    private:
        /* data */
        sf::RenderWindow* janela;
        sf::View exibir;
        std::map<const char*, sf::Texture*> mapaTexturas;
        sf::Font* fonte;

        static GerenciadorGrafico* instancia; // Ponteiro presente para toda instancia de gerenciador
        GerenciadorGrafico(); // Construtora PRIVADA para que não seja instanciado nenhum gerenciador grafico por outro objeto

    public:
        ~GerenciadorGrafico();
        static GerenciadorGrafico* getInstancia(); /* Método público por onde outras classes podem acessá-lo */
        void limparJanela();
        void desenhar(sf::RectangleShape* corpo);
        void mostrar();
        bool getJanelaAberta() const;

    };

} using namespace Gerenciadores;
