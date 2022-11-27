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
        int posicaoX;
        int posicaoY;
        int qtdInimigosEliminados;
        int qtdRecursosColetados;
        string auxHistorico;
        Fila* filaHistorico[1];
    public:
        Robos(int);
        ~Robos();
        Fila* filaComandos[1];
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