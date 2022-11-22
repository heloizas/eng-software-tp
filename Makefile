all:
	g++ -std=c++17 src/Base.cc src/Comandos.cc src/Fila.cc src/ListaRobos.cc src/Main.cc src/Mapa.cc src/Missao.cc src/Robos.cc -o bin/run.out
	g++ -std=c++17 tests/Tests.cc src/Base.cc src/Comandos.cc src/Fila.cc src/ListaRobos.cc src/Mapa.cc src/Missao.cc src/Robos.cc -o tests/tests.out

clean:
	$(RM) ./obj/*