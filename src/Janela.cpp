#include "Janela.hpp"

/* CONSTRUTORA / DESTRUTORA */
Janela::Janela() :
janela(new RenderWindow(VideoMode(LARGURA, ALTURA), "Jogo++"))
{
    janela->setFramerateLimit(TAXA_QUADROS);
}

Janela::~Janela() {
    janela = NULL;
}

/* MÉTODOS PRINCIPAIS*/

/*void Janela::eventoBase() {
    Event e;
    while (getJanela()->pollEvent(e)) {
        
        if (e.type == Event::Closed) {
            fechar();
        }
    }
}*/

RenderWindow *Janela::getJanela() const
{
    if (janela == NULL) {
        cout << "RenderWindow *Janela::getJanela() const -> ponteiro nulo." << endl;
        return (new RenderWindow());
    }
    return janela;
}
