#include <stdio.h>
#include <string>

#ifndef MAPA_H
#define MAPA_H

using namespace std;

class Mapa {
    private:
        char mapaBase, recurso, obstaculo, inimigo, vazio;
        int linhas, colunas;
        static const int MAXTAM = 100;
        char mapaMatriz[MAXTAM][MAXTAM];
        void gerarMapa(ifstream &arquivoMapa);
    public:
        Mapa(ifstream &arquivoMapa);
        ~Mapa();
        string encontrarPonto(int, int);
        void adicionarPonto(int, int);
        void imprimirMapa(); 
};

#endif