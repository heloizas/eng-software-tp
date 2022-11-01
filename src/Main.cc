#include <iostream>
#include <fstream>

#include "../include/Mapa.h"
#include "../include/Missao.h"
#include "../include/Comandos.h"
#include "../include/ListaRobos.h"
#include "../include/Fila.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Passar na linha de comandos ao rodar o programa
    // o primeiro arquivo (mapa.txt) e o segundo arquivo (comandos.txt)
    ifstream arquivoMapa(argv[1]);
    ifstream arquivoComandos(argv[2]);

    Missao missao(arquivoMapa, arquivoComandos);
    missao.relatorioGeral();

    return 0;
}