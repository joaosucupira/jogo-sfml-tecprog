#include "Ente.hpp"

//int Ente::cont_id(0);
GerenciadorGrafico* Ente::pGG = GerenciadorGrafico::getInstancia();
/* Construtoras/Destrutoras */

Ente::Ente() :
//id(cont_id++),
figura(NULL)
{
    setGGrafico();
}

Ente::~Ente()
{
    if (figura != NULL) {
        delete figura;
    }
    figura = NULL;
}
/* Métodos principais */


void Ente::desenhar() {
    // Completo requisito de operador this e rel. bidirecional
    if(pGG)
        pGG->desenharEnte(this);
    else
        cout << "Ente::desenhar() -> ponteiro gGrafico nulo" << endl;
}

void Ente::atualizarFigura(){

    if(figura)
        figura->atualizarSecao();
    else
        cout << "Ente::atualizarFigura() -> ponteiro figura nulo!" << endl;
}

void Ente::atualizaParaFiguraInicial() {
    if (figura) {
        figura->setSecaoInicial();
    } else { cout << "Personagem::atualizaParaFiguraInicial() -> figura nula" << endl; }
}

void Ente::carregarFigura(string pathTextura){
    if(figura)
        figura->carregarTextura(pathTextura);
    else
        cout << "Ente::carregarFigura(string pathTextura) -> ponteiro figura nulo!";
}

FloatRect Ente::getLimites() const{

    if(!figura){
        cout << "Ente::getLimites() -> ponteiro figura nulo" << endl;
        return FloatRect();
    }

    return figura->getLimites();

}

void Ente::setPosicaoFigura(const float x, const float y) {

    if (figura) 
        figura->setPosicao(x, y);
    else 
        cout << "Ente::setPosicaoFigura(const float x, const float y) -> ponteiro figura nulo!" << endl;
}

void Ente::setTamanhoFigura(const float tX, const float tY) {

    if(figura)
        figura->setTamanho(tX, tY);
    else 
        cout << "Ente::setTamanhoFigura(const float tX, const float tY) -> ponteiro figura nulo!" << endl;
}

void Ente::setCorFigura(const Color &cor) { 

    if(figura)
        figura->setCor(cor);
    else
        cout << "Ente::setCorFigura(const Color &cor) -> ponteiro figura nulo!";
}
