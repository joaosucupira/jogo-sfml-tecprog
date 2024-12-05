#include "Janela.hpp"

Janela::Janela() :
janela(new RenderWindow(VideoMode(LARGURA, ALTURA), "Jogo++"))
{
    janela->setFramerateLimit(TAXA_QUADROS);
}

Janela::~Janela() {
    janela = NULL;
}

RenderWindow *Janela::getJanela() const {
    if (janela == NULL) {
        cout << "RenderWindow *Janela::getJanela() const -> ponteiro nulo." << endl;
        return (new RenderWindow());
    }
    return janela; 
}
