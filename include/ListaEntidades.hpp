// AUTOR(A) : JOAO SUCUPIRA
// ALTERAÇÕES : ...
/*
* DESCRIÇÃO: Classe que aplica o objeto Lista para listar objetos derivados de
*            Entidade de forma mais eficiente e organizada.
*/
// REFERÊNCIAS: Ex-Alunos da disciplina Caio e Ana Julia: https://github.com/caio-o/ggg
/* MAPA:
*  1-
*/// ! -> .hpp  ao invés de .h para identificar um arquivo de classe que possui um .cpp
#include "Entidade.hpp"
#include "Lista.h"
using namespace Entidades;

namespace Listas {
    class ListaEntidades {
        private:
            Lista<Entidade> LE;
        
        public:
            ListaEntidades();
            ~ListaEntidades();

            void adiciona(Entidade* pE);
            void exclui(Entidade* pE);
            void excluiTodos();
            int getTamanho() const { return LE.getTamanho(); }
            Lista<Entidade>* getLista() { return &LE; }
            Entidade* operator[](int elem);

    };
} // namespace Listas