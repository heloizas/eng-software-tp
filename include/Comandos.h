#include <stdio.h>
#include "Base.h"

#ifndef COMANDOS_H
#define COMANDOS_H

using namespace std;
 
class Comandos {
    private:
        static const int MAXTAM = 100;
        string comandos[MAXTAM];
        string linhaComando;
        int quantidadeComandos;
        int tipo;
        int idRobo; 
        bool auxPrioritaria;
        void gerarComandos(ifstream &arquivoComandos, Base &base);
        void executarComando(string, Base &base);
        void executarComandoDireto(string, Base &base);
        void executarComandoOrdem(string, Base &base, bool);
        int tipoComando(string);
        void comandoMover(string, Base &base);
        void comandoColetar(string, Base &base);
        void comandoEliminar(string, Base &base);
        void comandoAtivar(string, Base &base);
        void comandoExecutar(string, Base &base);
        void comandoRelatorio(string, Base &base);
        void comandoRetornar(string, Base &base);
    public:
        Comandos(ifstream &arquivoComandos, Base &base);
        ~Comandos();
        void imprimirComandos();
    friend class Mapa;
};

#endif