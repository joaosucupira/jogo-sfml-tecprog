#include "Janela.hpp"

Janela::Janela() :
janela(new RenderWindow(VideoMode(LARGURA, ALTURA), "Jogo++"))
{
    janela->setFramerateLimit(TAXA_QUADROS);
}

Janela::~Janela() {
    janela = NULL;
}

void Janela::processarEventos() {
    Event e;
    while (janela->pollEvent(e)) {
        if (e.type == Event::Closed) {
            fechar();
        }
    }
}

RenderWindow *Janela::getJanela() const
{
    if (janela == NULL) {
        cout << "RenderWindow *Janela::getJanela() const -> ponteiro nulo." << endl;
        return (new RenderWindow());
    }
    return janela;
}
