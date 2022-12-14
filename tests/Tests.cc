#include "../external/utest.h"
#include "../include/Robos.h"
#include "../include/Base.h"
#include "../include/Mapa.h"
#include "../include/Comandos.h"

#include <iostream>
#include <fstream>
#include <string>

// https://github.com/sheredom/utest.h

Robos criaObjetoRobo()
{
  Robos RoboTeste(1);
  return RoboTeste;
}

Base criaObjetoBase()
{
  ifstream arquivoMapa("arquivoTesteMapa.txt");
  Base BaseTeste(arquivoMapa);
  arquivoMapa.close();
  return BaseTeste;
}

Mapa criaObjetoMapa()
{
  ifstream arquivoMapa("arquivoTesteMapa.txt");
  Mapa MapaTeste(arquivoMapa);
  arquivoMapa.close();
  return MapaTeste;
}

Comandos criaObjetoComandos()
{
  ifstream arquivoComandos("arquivoTesteComandos.txt");
  Base BaseTeste = criaObjetoBase();
  Comandos ComandoTeste(arquivoComandos, BaseTeste);
  arquivoComandos.close();
  return ComandoTeste;
}

// TESTES UNITÁRIOS

UTEST(TesteClasseRobo, RoboIniciaDesativado)
{
  Robos RoboTeste = criaObjetoRobo();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, RoboAtivadoCorretamente)
{
  Robos RoboTeste = criaObjetoRobo();
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, RoboAtivadoEDesativadoCorretamente)
{
  Robos RoboTeste = criaObjetoRobo();
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());
  RoboTeste.retornarBase();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, TestaPosicaoX)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();
  RoboTeste.adicionarComando("MOVER 0 (1,0)");
  RoboTeste.adicionarComando("MOVER 0 (2,0)");
  RoboTeste.executarRobo(MapaTeste);

  ASSERT_EQ(RoboTeste.posicaoX, 2);
}

UTEST(TesteClasseRobo, TestaPosicaoY)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();
  RoboTeste.adicionarComando("MOVER 0 (0,1)");
  RoboTeste.adicionarComando("MOVER 0 (0,2)");
  RoboTeste.adicionarComando("MOVER 0 (0,3)");
  RoboTeste.executarRobo(MapaTeste);

  ASSERT_EQ(RoboTeste.posicaoY, 3);
}

UTEST(TesteClasseRobo, TesteTamanhoFila)
{
  Robos RoboTeste = criaObjetoRobo();
  RoboTeste.ativarRobo();
  RoboTeste.adicionarComando("MOVER 0 (0,1)");
  RoboTeste.adicionarComando("MOVER 0 (0,2)");
  RoboTeste.adicionarComando("MOVER 0 (0,3)");

  ASSERT_EQ(RoboTeste.filaComandos[0]->tamanho, 3);
}

UTEST(TesteClasseRobo, VerificarRetornoRobo)
{
  Robos RoboTeste1 = criaObjetoRobo();
  Robos RoboTeste2 = criaObjetoRobo();

  RoboTeste1.ativarRobo();
  RoboTeste2.ativarRobo();
  RoboTeste2.retornarBase();

  ASSERT_TRUE(RoboTeste1.getRoboAtivo());
  ASSERT_FALSE(RoboTeste2.getRoboAtivo());
}

UTEST(TesteClasseComandos, ComandoEhOrdem)
{
  Comandos ComandoTeste = criaObjetoComandos();
  // Comando ordem = 1
  ASSERT_EQ(ComandoTeste.tipoComando("MOVER 0 (2,8)"), 1);
}

UTEST(TesteClasseComandos, ComandoEhDireto)
{
  Comandos ComandoTeste = criaObjetoComandos();
  // Comando direto = 2
  ASSERT_EQ(ComandoTeste.tipoComando("ATIVAR 0"), 2);
}

UTEST(TesteClasseComandos, ComandoEhPrioritario)
{
  Comandos ComandoTeste = criaObjetoComandos();
  // Comando prioritario = 3
  ASSERT_EQ(ComandoTeste.tipoComando("*MOVER 1 (1,8)"), 3);
}

UTEST(TesteClasseComandos, VerificaFuncaoGerarComandos)
{
  Comandos ComandoTeste = criaObjetoComandos();
  Base BaseTeste = criaObjetoBase();
  ifstream arquivoComandos("arquivoTesteComandos.txt");

  // Se o arquivo for encontrado corretamente, retorna 0.
  ASSERT_EQ(ComandoTeste.gerarComandos(arquivoComandos, BaseTeste), 0);
}

UTEST(TesteClasseMapa, RetornaSeEhPontoVazio)
{
  Mapa MapaTeste = criaObjetoMapa();
  string str = MapaTeste.encontrarPonto(1, 1);
  char *cstr = &str[0];
  ASSERT_STREQ(cstr, "Vazio");
}

UTEST(TesteClasseMapa, VerificarTamanhoFilaHistorico)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();

  RoboTeste.adicionarComando("MOVER 0 (3,3)");
  RoboTeste.adicionarComando("MOVER 0 (3,2)");
  RoboTeste.executarRobo(MapaTeste);

  int tamanhoFilaHistorico =  RoboTeste.filaHistorico[0]->tamanho;

  ASSERT_EQ(tamanhoFilaHistorico, 2);
}

UTEST(TesteClasseMapa, VerificaFuncaoGerarMapa)
{
  Mapa MapaTeste = criaObjetoMapa();
  ifstream arquivoMapa("arquivoTesteMapa.txt");

  // Se o arquivo for encontrado corretamente, retorna 0.
  ASSERT_EQ(MapaTeste.gerarMapa(arquivoMapa), 0);
}

UTEST(TesteClasseMapa, VerificaTamanhoLinhasEColunas)
{
  Mapa MapaTeste = criaObjetoMapa();

  ASSERT_EQ(MapaTeste.linhas, 10);
  ASSERT_EQ(MapaTeste.colunas, 10);
}

// TESTES DE INTEGRAÇÃO

UTEST(TesteIntegracao, TestaQtRecursos)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());

  RoboTeste.adicionarComando("MOVER 0 (2,4)");
  RoboTeste.adicionarComando("COLETAR 0");
  RoboTeste.executarRobo(MapaTeste);
  ASSERT_EQ(RoboTeste.qtdRecursos(), 1);

  RoboTeste.retornarBase();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteIntegracao, TestaQtInimigos)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());

  RoboTeste.adicionarComando("MOVER 0 (4,1)");
  RoboTeste.adicionarComando("ELIMINAR 0");
  RoboTeste.adicionarComando("MOVER 0 (7,3)");
  RoboTeste.adicionarComando("ELIMINAR 0");
  RoboTeste.executarRobo(MapaTeste);
  ASSERT_EQ(RoboTeste.qtdInimigos(), 2);

  RoboTeste.retornarBase();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteIntegracao, TestComandosVariados)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());

  RoboTeste.adicionarComando("MOVER 0 (1,1)");
  RoboTeste.executarRobo(MapaTeste);
  RoboTeste.adicionarComando("MOVER 0 (0,6)");
  RoboTeste.adicionarComandoPrioritario("COLETAR 0");
  RoboTeste.adicionarComandoPrioritario("MOVER 0 (2,4)");
  RoboTeste.adicionarComando("MOVER 0 (4,1)");
  RoboTeste.adicionarComando("ELIMINAR 0");
  RoboTeste.executarRobo(MapaTeste);
  ASSERT_EQ(RoboTeste.qtdInimigos(), 1);
  ASSERT_EQ(RoboTeste.qtdRecursos(), 1);

  RoboTeste.retornarBase();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteIntegracao, TestaComandosPreBase)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();

  RoboTeste.adicionarComando("MOVER 0 (1,1)");
  RoboTeste.executarRobo(MapaTeste);
  RoboTeste.adicionarComando("MOVER 0 (0,6)");
  RoboTeste.adicionarComandoPrioritario("COLETAR 0");
  RoboTeste.adicionarComandoPrioritario("MOVER 0 (2,4)");
  RoboTeste.adicionarComando("MOVER 0 (4,1)");
  RoboTeste.adicionarComando("ELIMINAR 0");
  RoboTeste.executarRobo(MapaTeste);

  ASSERT_EQ(RoboTeste.qtdInimigos(), 1);
  ASSERT_EQ(RoboTeste.qtdRecursos(), 1);
  ASSERT_EQ(RoboTeste.posicaoX, 4);
  ASSERT_EQ(RoboTeste.posicaoY, 1);
  ASSERT_EQ(RoboTeste.roboAtivo(), 1);
  
  RoboTeste.retornarBase();
}

UTEST(TesteIntegracao, TestaRetornoBaseCompleto)
{
  Robos RoboTeste = criaObjetoRobo();
  Mapa MapaTeste = criaObjetoMapa();
  RoboTeste.ativarRobo();

  RoboTeste.adicionarComando("MOVER 0 (1,1)");
  RoboTeste.executarRobo(MapaTeste);
  RoboTeste.adicionarComando("MOVER 0 (0,6)");
  RoboTeste.adicionarComandoPrioritario("COLETAR 0");
  RoboTeste.adicionarComandoPrioritario("MOVER 0 (2,4)");
  RoboTeste.adicionarComando("MOVER 0 (4,1)");
  RoboTeste.adicionarComando("ELIMINAR 0");
  RoboTeste.executarRobo(MapaTeste);
  
  RoboTeste.retornarBase();
  ASSERT_EQ(RoboTeste.qtdInimigos(), 0);
  ASSERT_EQ(RoboTeste.qtdRecursos(), 0);
  ASSERT_EQ(RoboTeste.posicaoX, 0);
  ASSERT_EQ(RoboTeste.posicaoY, 0);
  ASSERT_EQ(RoboTeste.roboAtivo(), 0);
}

UTEST_MAIN();