#include "GerenciadorEventos.hpp"

GerenciadorGrafico* GerenciadorEventos::pGG = GerenciadorGrafico::getInstancia();

GerenciadorEventos::GerenciadorEventos() :
GC(),
janela(NULL),
rodando(false),
j1(true)
{
    setGraficos();
}

Gerenciadores::GerenciadorEventos::~GerenciadorEventos() {
    // if (janela)
    //     delete janela;
    janela = NULL;
}

void GerenciadorEventos::setWindow(RenderWindow *pR) {
    if (pR)
        janela = pR;
    else
        cout << "GerenciadorEventos::setWindow(RenderWindow *pR) -> ponteiro nulo. " << endl;
}

void GerenciadorEventos::setGraficos() {
    setWindow(&(
        pGG->getJanela()
    ));

}

void GerenciadorEventos::desenhar() {
    janela->clear();
    pGG->desenharEnte(&j1);
    janela->display();
}

void GerenciadorEventos::eventoBase()
{
    Event e;
    while (janela->pollEvent(e)) {
        if (e.type == Event::Closed) {
            janela->close();
            rodando = false;
        }
    }
}

void GerenciadorEventos::executar() {
    rodando = true;
    Clock relogio;

    while (rodando && janela->isOpen()) {
        float dt = relogio.restart().asSeconds();
        j1.moverSprite(Vector2f(0, 100.0f * dt));
        desenhar();
        eventoBase();

    }
}
