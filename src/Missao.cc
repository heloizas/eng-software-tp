#include <iostream>
#include <fstream>

#include "../include/Missao.h"

using namespace std;

Missao::Missao(ifstream &arquivoMapa, ifstream &arquivoComandos) {
	base = new Base(arquivoMapa);
	comandos = new Comandos(arquivoComandos, *base);
}

Missao::~Missao() { 

}