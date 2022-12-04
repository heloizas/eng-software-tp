#include <stdio.h>
#include "Fila.h"
#include "Mapa.h"

#ifndef ROBOS_H
#define ROBOS_H

using namespace std;

class Robos {
    private:
        int idRobo;
        bool ativo;
        int qtdInimigosEliminados;
        int qtdRecursosColetados;
        string auxHistorico;
    public:
        Fila* filaHistorico[1];
        Robos(int);
        ~Robos();
        Fila* filaComandos[1];
        int posicaoX;
        int posicaoY;
        bool roboAtivo();
        int qtdRecursos();
        int qtdInimigos();
        void adicionarComando(string);
        void adicionarComandoPrioritario(string);
        void ativarRobo();
        void imprimirRelatorio();
        void retornarBase();
        void executarRobo(Mapa& mapa);
        void processarComando(string, Mapa& mapa);
        void comandoMover(string, Mapa& mapa);
        void comandoColetar(Mapa& mapa);
        void comandoEliminar(Mapa& mapa);
        bool getRoboAtivo();
    friend class ListaRobos;
};

#endif