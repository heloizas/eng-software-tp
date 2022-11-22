#include <iostream>
#include <fstream>

#include "../include/Mapa.h"

using namespace std;

Mapa::Mapa(ifstream &arquivoMapa) {
	mapaBase = 'B';
	recurso = 'R';
	obstaculo = 'O';
	inimigo = 'H';
	vazio = '.';
	linhas = 0;
	colunas = 0;
	//Quantidade de linhas e colunas
	arquivoMapa >> linhas >> colunas;
	gerarMapa(arquivoMapa);
}

void Mapa::gerarMapa(ifstream &arquivoMapa) {
	if (arquivoMapa.is_open()){
		for(int i=0; i<linhas; i++) {
			for(int j=0; j<colunas; j++) { 
				arquivoMapa >> mapaMatriz[i][j];
			}
		}
	} else {
		cout << "Nao foi possivel abrir o arquivo do mapa! Verifique o nome e a localizacao do arquivo." << endl;
	}
}

string Mapa::encontrarPonto(int coordenadaX, int coordenadaY) {
	if (mapaMatriz[coordenadaX][coordenadaY] == vazio) return "Vazio";
	if (mapaMatriz[coordenadaX][coordenadaY] == obstaculo) return "Obstaculo";
	if (mapaMatriz[coordenadaX][coordenadaY] == recurso) return "Recurso";
	if (mapaMatriz[coordenadaX][coordenadaY] == inimigo) return "Inimigo";
	if (mapaMatriz[coordenadaX][coordenadaY] == mapaBase) return "Base";
	if (coordenadaX > linhas || coordenadaY > colunas) return "O ponto solicitado nao existe no mapa";
	return "";
}

void Mapa::adicionarPonto(int x, int y) {
	mapaMatriz[x][y] = '.';
}

void Mapa::imprimirMapa() {
	for(int i=0; i<linhas; i++) {
		for(int j=0; j<colunas; j++) { 
			cout << mapaMatriz[i][j];
		}
		cout << endl;
	}
}

Mapa::~Mapa() {

}