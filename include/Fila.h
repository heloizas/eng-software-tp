#include <stdio.h>
#include <string>

#ifndef FILA_H
#define FILA_H

using namespace std;

class Fila {
    private:
        int frente;
        int tras;
        static const int MAXTAM = 100;
        int tamanho;
    public:
        Fila();
        ~Fila();
        string comandos[MAXTAM]; 
        void enfileira(string);
        string desenfileira();
        void inserePrioritario(string);
        void imprime();
        void limpa();
    friend class Robos;
};

#endif