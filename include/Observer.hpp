/**REFERENCIAS: Livro do GOF, Design Patterns */

#pragma once

class Observer {
    public:
        Observer() {}
        virtual ~Observer() {}
        virtual void notificar() = 0;
};