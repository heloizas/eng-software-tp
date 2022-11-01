#include <stdio.h>
#include "Robos.h"
#include "Mapa.h"

#ifndef LISTAROBOS_H
#define LISTAROBOS_H

using namespace std;

class ListaRobos {
    private:
    // 50 robôs
        Robos* robos[50];
    public:
        ListaRobos();
        ~ListaRobos(); 
        void adicionarComando(int, string);
        void adicionarComandoPrioritario(int, string);
        void ativarRobo(int);
        void executarRobo(int, Mapa&);
        void relatorioRobo(int);
        void retornarRobo(int);
        bool roboAtivo(int); 
        int qtdRecursos(int);
        int qtdInimigos(int);
};

#endif