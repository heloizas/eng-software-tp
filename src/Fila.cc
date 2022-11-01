#include <iostream>
#include <fstream>

#include "../include/Fila.h"

using namespace std;

Fila::Fila(){
    frente = 0;
    tras = 0;
    tamanho = 0;
}

void Fila::enfileira(string comando) {
    comandos[tras] = comando;
    tras = (tras + 1) % MAXTAM;
    tamanho++;
}

string Fila::desenfileira() {
    string contadorAux;
    contadorAux = comandos[frente];
    frente = (frente + 1) % MAXTAM;
    tamanho--;
    return contadorAux;
}

void Fila::inserePrioritario(string comando) {
    Fila filaAuxiliar;
    string auxX;
    string auxY;
    int contadorAux;
    contadorAux = tamanho;
    int tamanhoFilaAux = 0;
    while (tamanhoFilaAux < contadorAux) {
        auxX = desenfileira();
        filaAuxiliar.enfileira(auxX);
        tamanhoFilaAux++;
    }
    enfileira(comando);
    while (tamanhoFilaAux > 0) {
        auxY = filaAuxiliar.desenfileira();
        enfileira(auxY);
        tamanhoFilaAux--;
    }
}

void Fila::imprime() {
    for (int i = 0; i<tamanho; i++) {
        cout << comandos[i] << endl;
    }
}

void Fila::limpa() {
    frente = 0;
    tras = 0;
    tamanho = 0;
}

Fila::~Fila() {
}