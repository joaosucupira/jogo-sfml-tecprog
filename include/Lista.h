// AUTOR(A) : JOAO SUCUPIRA
// ALTERAÇÕES : ...
/*
* DESCRIÇÃO: Gabarito composto para tornar desacopladas as listas de elementos
*            do projeto e poupar-nos o trabalho de criar uma classe de lista para
*            cada objeto que precise.
*/
// REFERÊNCIAS: Ex-Monitor da disciplina M.A. Burda: https://github.com/MatheusBurda/Desert
/* MAPA:
*  1- MÉTODOS ELEMENTO
*  2- MÉTODOS LISTA
*/// ! -> .h  ao invés de .hpp para identificar um arquivo biblioteca ou gabarito

#pragma once
#include "stdfax.h"


namespace Listas {

    template<typename TL>
    class Lista {
        private:
            template<typename TE>
            class Elemento {
                private:
                    Elemento<TE>* pProx;
                    Elemento<TE>* pAnte;
                    TE* pInfo;
                public:
                    Elemento() {
                        pInfo = NULL;
                        pAnte = NULL;
                        pProx = NULL;
                    }
                    ~Elemento() {
                        pInfo = NULL;
                        pAnte = NULL;
                        pProx = NULL;
                    }

                    // 1- DEFINIÇÃO MÉTODOS BÁSICOS PARA ACESSO AOS ELEMENTOS DAS LISTAS EM MODELO DE LISTA DUPLAMENTE ENCADEADA
                    // SETTERS
                    void setProx(Elemento<TE>* pP) { this->pProx = pP; }
                    void setAnte(Elemento<TE>* pP) { this->pAnte = pP; }
                    void setInfo(TE* pI) { this->pInfo = pI; }
                    // GETTERS
                    Elemento<TE>* getAnte() const { return pAnte; }
                    Elemento<TE>* getProx() const { return pProx; }
                    TE* getInfo() const { return pInfo; }
            };

            Elemento<TL>* pPrim;
            Elemento<TL>* pUltm;
            int tamanho;
        public:
            Lista();
            ~Lista();

            void limpaLista();
            void insere(TL* pInfo);
            int getTamanho() const { return tamanho; }
            TL* operator[](int elem);
            bool remove(TL* pTL);
        private:
            void setElemento(Elemento<TL>* pE);
            Elemento<TL>* getPrim() const { return pPrim; }
            Elemento<TL>* getUltm() const { return pUltm; } 

    };

    template <class TL>
    Lista<TL>::Lista()
    {
        pPrim = nullptr;
        pUltm = nullptr;
        tamanho = 0;
        limpaLista();
    }

    template <class TL>
    Lista<TL>::~Lista()
    {
        pPrim = nullptr;
        pUltm = nullptr;
        tamanho = 0;
        limpaLista();
    }


    // 2- DEFINIÇÃO DOS MÉTODOS PARA MANIPULAÇÃO, ALTERAÇÃO E ACESSO AOS ELEMENTOS DAS LISTAS

    // 2.1 - Deleta propriamente todos os elementos e aterra os ponteiros
    template <class TL>
    void Lista<TL>::limpaLista()
    {
        Elemento<TL>* pA1;
        Elemento<TL>* pA2;
        pA1 = pPrim;
        pA2 = pA1;

        while (pA1 != NULL) {
            delete pA1->getInfo();
            pA2 = pA1->getProx();
            delete pA1;
            pA1 = pA2;
            tamanho--;
        }

        pPrim = NULL;
        pUltm = NULL;
    }

    // 2.2 -  Método que prepara a estrutura da lista duplamente encadeada para a 
    //        inserção do novo elemento à lista evitando a adição de ponteiros nulos.
    template <class TL>
    void Lista<TL>::setElemento(Elemento<TL> *pE)
    {
        if (pE != NULL) {
            // Caso 1 - A lista é vazia
            if (pPrim == NULL) {
                pPrim = pE;
                pUltm = pE;
            } 
            // Caso 2 - A lista é não vazia
            else {
                pUltm->setProx(pE);
                pE->setAnte(pUltm);
                pUltm = pE;
            }
            tamanho++;
        } 
        else {
            std::cout << "Lista<TL>::setElemento impediu a inserção de um ponteiro nulo!" << std::endl;
        }
    }

    // 2.3 - Método que executa a alocação de memória e o método 2.2 evitando a adição
    //       de ponteiros nulos.
    template <class TL>
    void Lista<TL>::insere(TL* pInfo) {
        if (pInfo != NULL) {
            Elemento<TL>* pE = NULL;
            pE = new Elemento<TL>;
            pE->setInfo(pInfo);
            setElemento(pE);
        } else {
            std::cout << "Lista<TL>::insere impediu a inserção de um poneiro nulo!" << std:: endl;
        }
    }



    // 2.4 - Operador [] que impede segfault e retorna o ponteiro que aponta para o argumento da posição dada
    template <class TL>
    TL* Lista<TL>::operator[](int elem) {
        if (elem >= tamanho || elem < 0) {
            std::cout << "Lista<TL>::operator[] impediu segfault no gabarito de lista." << std::endl << "Indice indevido = " << std::endl;
        }
        Elemento<TL>* pE = pPrim;
        for (int i = 0; i < elem; i++) {
            pE = pE->getProx();
        }

        if (pE == NULL) {
            std::cout << "Lista<TL>operator[] obteve PONTEIRO NULO!" << std::endl;
            exit(1);
        }
        return pE->getInfo();
    }


    // 2.5 - Método que remove elemento dado seu valor no argumento
    template <class TL>
    bool Lista<TL>::remove(TL* elem) {
        Elemento<TL>* pE = pPrim;
        Elemento<TL>* pAnte = NULL;
        while (pE != NULL) {
            if (pE->getInfo() == elem) {
                if (pE == pPrim)
                    pPrim = pE->getProx();
                else
                    pAnte->setProx(pE->getProx());
                
                delete (pE);
                tamanho--;
                return true;
            }
            pAnte = pE;
            pE = pE->getProx();
        }

        return false;
    }

} // Namespace Listas