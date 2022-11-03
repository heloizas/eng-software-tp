#include <iostream>
#include <fstream>

#include "../include/Comandos.h"

using namespace std;

Comandos::Comandos(ifstream &arquivoComandos, Base &base) {
    quantidadeComandos = 0;
    tipo = 1;
    auxPrioritaria = true;
    gerarComandos(arquivoComandos, base);
}

void Comandos::gerarComandos(ifstream &arquivoComandos, Base &base) {
    if (arquivoComandos.is_open()){
        while(getline(arquivoComandos, linhaComando)){
            comandos[quantidadeComandos] = linhaComando;
            quantidadeComandos++;
            executarComando(linhaComando, base);
        }
    } else {
        cout << "Nao foi possivel abrir o arquivo de comandos! Verifique o nome e a localizacao do arquivo." << endl;
    }
}

void Comandos::executarComando(string comando, Base &base) {
    auxPrioritaria = false;
    if(tipoComando(comando) == 3) {
        auxPrioritaria = true;
        executarComandoOrdem(comando, base, auxPrioritaria);
    }
    if (tipoComando(comando) == 1) {
        executarComandoOrdem(comando, base, auxPrioritaria);
    } else if (tipoComando(comando) == 2) {
        executarComandoDireto(comando, base);
    }
    tipoComando(comando);
}

void Comandos::verificaComandoAtivar(string comando, Base &base){
    if(comando.find("ATIVAR") != string::npos) {
        comandoAtivar(comando, base);
    }
}

void Comandos::verificaComandoExecutar(string comando, Base &base){
    if(comando.find("EXECUTAR") != string::npos) {
        comandoExecutar(comando, base);
    } 
}

void Comandos::verificaComandoRelatorio(string comando, Base &base){
    if(comando.find("RELATORIO") != string::npos) {
        comandoRelatorio(comando, base);
    }
}

void Comandos::verificaComandoRetornar(string comando, Base &base){
    if(comando.find("RETORNAR") != string::npos) {
        comandoRetornar(comando, base);
    }
}


void Comandos::executarComandoDireto(string comando, Base &base) {
    verificaComandoAtivar(comando, base);
    verificaComandoExecutar(comando, base);
    verificaComandoRelatorio(comando, base);
    verificaComandoRetornar(comando, base);
}

void Comandos::executarComandoOrdem(string comando, Base &base, bool prioritaria) {
    if(comando.find("MOVER") != string::npos) {
        comandoMover(comando, base);
    } else if(comando.find("COLETAR") != string::npos) {
        comandoColetar(comando, base);
    } else if(comando.find("ELIMINAR") != string::npos) {
        comandoEliminar(comando, base);
    }
}

int Comandos::tipoComando(string comando) {
    // 1: Comando Ordem
    // 2: Comando Direto
    // 3: Comando Prioritário
    tipo = 1;
    if (comando[0] == '*'){
        tipo = 3;
    } else if ((comando.find("ATIVAR") != string::npos) || (comando.find("EXECUTAR") != string::npos)
    || (comando.find("RELATORIO") != string::npos) || (comando.find("RETORNAR") != string::npos)) {
        tipo = 2;
    }
    return tipo;
}

// Ordens de Comando
void Comandos::comandoMover(string comando, Base &base) {
    idRobo = stoi(comando.substr(6, 8));
    if (auxPrioritaria) {
        base.adicionarComandoPrioritario(idRobo, comando);
    } else {
        base.adicionarComando(idRobo, comando);
    }
}

void Comandos::comandoColetar(string comando, Base &base) {
    idRobo = stoi(comando.substr(8, comando.length()));
    if (auxPrioritaria) {
        base.adicionarComandoPrioritario(idRobo, comando);
    } else {
        base.adicionarComando(idRobo, comando);   
    }
}

void Comandos::comandoEliminar(string comando, Base &base) {
    idRobo = stoi(comando.substr(9, comando.length()));
    if (auxPrioritaria) {
        base.adicionarComandoPrioritario(idRobo, comando);
    } else {
        base.adicionarComando(idRobo, comando);     
    }
}

// Ordens Diretas:
void Comandos::comandoAtivar(string comando, Base &base) {
    idRobo = stoi(comando.substr(7, comando.length()));
    base.ativarRobo(idRobo);
}

void Comandos::comandoExecutar(string comando, Base &base) {
    idRobo = stoi(comando.substr(9, comando.length()));
    base.executarRobo(idRobo);
}

void Comandos::comandoRelatorio(string comando, Base &base) {
    idRobo = stoi(comando.substr(10, comando.length()));
    base.relatorioRobo(idRobo);
}

void Comandos::comandoRetornar(string comando, Base &base) {
    idRobo = stoi(comando.substr(9, comando.length()));
    base.retornarRobo(idRobo);
}

void Comandos::imprimirComandos() {
	for(int i=0; i<quantidadeComandos; i++) {
		cout << comandos[i] << endl;
	}
}

Comandos::~Comandos() {

}