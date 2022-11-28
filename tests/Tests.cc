#include "../external/utest.h"
#include "../include/Robos.h"
#include "../include/Base.h"
#include "../include/Mapa.h"
#include "../include/Comandos.h"

#include <iostream>
#include <fstream>
#include <string>

// https://github.com/sheredom/utest.h

Robos criaObjetoRobo() {
   Robos RoboTeste(1);
   return RoboTeste;
}

Base criaObjetoBase() {
  ifstream arquivoMapa("arquivoTesteMapa.txt");
  Base BaseTeste(arquivoMapa);
  arquivoMapa.close();
  return BaseTeste;
}

Mapa criaObjetoMapa() {
  ifstream arquivoMapa("arquivoTesteMapa.txt");
  Mapa MapaTeste(arquivoMapa);
  arquivoMapa.close();
  return MapaTeste;
}

Comandos criaObjetoComandos() {
  ifstream arquivoComandos("arquivoTesteComandos.txt");
  Base BaseTeste = criaObjetoBase();
  Comandos ComandoTeste(arquivoComandos, BaseTeste);
  arquivoComandos.close();
  return ComandoTeste;
}

UTEST(TesteClasseRobo, RoboIniciaDesativado) {
  Robos RoboTeste = criaObjetoRobo();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, RoboAtivadoCorretamente) {
  Robos RoboTeste = criaObjetoRobo();
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, RoboAtivadoEDesativadoCorretamente) {
  Robos RoboTeste = criaObjetoRobo();
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());
  RoboTeste.retornarBase();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, TestaPosicaoX) {
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();
  RoboTeste.adicionarComando("MOVER 0 (1,0)");
  RoboTeste.adicionarComando("MOVER 0 (2,0)");
  RoboTeste.executarRobo(MapaTeste);

  ASSERT_EQ(RoboTeste.posicaoX, 2);
}

UTEST(TesteClasseRobo, TestaPosicaoY) {
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();
  RoboTeste.adicionarComando("MOVER 0 (0,1)");
  RoboTeste.adicionarComando("MOVER 0 (0,2)");
  RoboTeste.adicionarComando("MOVER 0 (0,3)");
  RoboTeste.executarRobo(MapaTeste);

  ASSERT_EQ(RoboTeste.posicaoY, 3);
}

UTEST(TesteClasseRobo, TestaPosicaoY) {
  Robos RoboTeste = criaObjetoRobo();
  RoboTeste.ativarRobo();
  RoboTeste.adicionarComando("MOVER 0 (0,1)");
  RoboTeste.adicionarComando("MOVER 0 (0,2)");
  RoboTeste.adicionarComando("MOVER 0 (0,3)");

  ASSERT_EQ(RoboTeste.filaComandos[1]->tamanho, 3);
}

UTEST(TesteClasseComandos, ComandoEhOrdem) {
  Comandos ComandoTeste = criaObjetoComandos();
  // Comando ordem = 1
  ASSERT_EQ(ComandoTeste.tipoComando("MOVER 0 (2,8)"), 1);
}

UTEST(TesteClasseComandos, ComandoEhDireto) {
  Comandos ComandoTeste = criaObjetoComandos();
  // Comando direto = 2
  ASSERT_EQ(ComandoTeste.tipoComando("ATIVAR 0"), 2);
}

UTEST(TesteClasseComandos, ComandoEhPrioritario) {
  Comandos ComandoTeste = criaObjetoComandos();
  
  // Comando prioritario = 3
  ASSERT_EQ(ComandoTeste.tipoComando("*MOVER 1 (1,8)"), 3);
}


UTEST_MAIN();