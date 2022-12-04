#include <stdio.h>
#include <string>

#ifndef MAPA_H
#define MAPA_H

using namespace std;

class Mapa {
    private:
        char mapaBase, recurso, obstaculo, inimigo, vazio;
        static const int MAXTAM = 100;
        char mapaMatriz[MAXTAM][MAXTAM];
    public:
        int linhas, colunas;
        int gerarMapa(ifstream &arquivoMapa);
        Mapa(ifstream &arquivoMapa);
        ~Mapa();
        string encontrarPonto(int, int);
        void adicionarPonto(int, int);
        void imprimirMapa(); 
};

#endif