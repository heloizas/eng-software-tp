#include <stdio.h>
#include "Mapa.h"
#include "ListaRobos.h"

#ifndef BASE_H
#define BASE_H

using namespace std;

class Base {
    private:
        Mapa* mapa;
        ListaRobos* robos; 
        int totalAliens, recursosColetados;
    public:
        Base(ifstream &arquivoMapa);
        ~Base();
        void adicionarComando(int, string);
        void adicionarComandoPrioritario(int, string);
        void ativarRobo(int);
        void executarRobo(int);
        void relatorioRobo(int);
        void retornarRobo(int);
        void relatorioGeral();
    friend class Mapa;
};

#endif