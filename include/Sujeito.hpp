#pragma once

#include "stdafx.h"
#include "Observer.hpp"

class Sujeito {
    protected:
        vector<Observer*> observadores;
        
    public:
        Sujeito() {}
        ~Sujeito() {}

        void adicionarObservador(Observer* pO);
        void removerObservador(Observer* pO);
        void notificarObservadores();
};