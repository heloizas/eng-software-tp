#include "../external/utest.h"
#include "../include/Robos.h"

// https://github.com/sheredom/utest.h

UTEST(TesteClasseRobo, RoboIniciaDesativado) {
  Robos RoboTeste(1);
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, RoboAtivadoCorretamente) {
  Robos RoboTeste(1);
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());
}

UTEST(TesteClasseRobo, RoboAtivadoEDesativadoCorretamente) {
  Robos RoboTeste(1);
  RoboTeste.ativarRobo();
  ASSERT_TRUE(RoboTeste.getRoboAtivo());
  RoboTeste.retornarBase();
  ASSERT_FALSE(RoboTeste.getRoboAtivo());
}

UTEST_MAIN();
