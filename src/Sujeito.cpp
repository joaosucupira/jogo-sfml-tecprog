#include "Sujeito.hpp"

void Sujeito::adicionarObservador(Observer* pO) {
    if (pO) {
        observadores.push_back(pO);
    } else { cout << "void Sujeito::adicionarObservador(Observer* pO) -> ponteiro nulo" << endl; }
}

void Sujeito::removerObservador(Observer *pO) {
    if (!pO) {
        cout << "void Sujeito::removerObservador(Observer *pO) -> ponteiro nulo" << endl;
        return;
    } 

    if (!observadores.empty()) {
        observadores.erase(
            remove(observadores.begin(), observadores.end(), pO),
            observadores.end()
        );
    }
}

void Sujeito::notificarObservadores() {
    for (Observer* pO : observadores) {
        if (pO) {
            pO->notificar();
        } else { cout << "void Sujeito::notificarObservadores() -> ponteiro nulo" << endl; }
    }
}
