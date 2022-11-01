#include <iostream>
#include <fstream>

#include "../include/Base.h"
#include "../include/ListaRobos.h"
#include "../include/Mapa.h"

using namespace std;

Base::Base(ifstream &arquivoMapa) {
  mapa = new Mapa(arquivoMapa);
  totalAliens = 0;
  recursosColetados = 0; 
  robos = new ListaRobos;
}

void Base::adicionarComando(int idRobo, string comando) {
  robos->adicionarComando(idRobo, comando); 
}

void Base::adicionarComandoPrioritario(int idRobo, string comando) {
  robos->adicionarComandoPrioritario(idRobo, comando); 
}

void Base::ativarRobo(int idRobo) {
  if(!robos->roboAtivo(idRobo)) {
    // Se o robô ainda não estiver ativo, ativa e sai em missão
    robos->ativarRobo(idRobo);
    cout << "BASE: ROBO "<< idRobo <<" SAIU EM MISSAO" << endl;
  } else {
    cout << "BASE: ROBO " << idRobo << " JA ESTA EM MISSAO" << endl;
  }
}

void Base::executarRobo(int idRobo) {
  robos->executarRobo(idRobo, *mapa);
} 

void Base::relatorioGeral() {
  cout << "BASE: TOTAL DE ALIENS " << totalAliens << " RECURSOS " << recursosColetados << endl;
} 

void Base::retornarRobo(int idRobo) {
  if(!robos->roboAtivo(idRobo)) {
    cout << "BASE: ROBO " << idRobo << " NAO ESTA EM MISSAO" << endl;
  } else {
    int auxInimigos = robos->qtdInimigos(idRobo);
    int auxRecursos = robos->qtdRecursos(idRobo);
    robos->retornarRobo(idRobo);
    cout << "BASE: ROBO " << idRobo << " RETORNOU ALIENS " << auxInimigos << " RECURSOS " << auxRecursos << endl;
    totalAliens = totalAliens+auxInimigos;
    recursosColetados = recursosColetados+auxRecursos; 
  } 
} 

void Base::relatorioRobo(int idRobo) {
  robos->relatorioRobo(idRobo); 
}

Base::~Base() {

}
