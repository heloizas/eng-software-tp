# Engenharia de Software 2 - Trabalho Prático
Grupo:
* Bárbara Ramos de Souza
* Heloiza Aparecida dos Santos
* Jônatas Henrique dos Santos

Aproveitamos um pequeno sistema que desenvolvemos antes de ter o conhecimento de boas práticas de desenvolvimento, quando cursamos a disciplina Estrutura de Dados.

O objetivo do trabalho é desenvolver, analisar a qualidade do código e refatorar. 
# Sistema: Extração-Z
<a href="https://drive.google.com/file/d/1QOu7xYG25V-H3LPf3mxSnmgalXTVKr6H/view">Especificações</a> ← 

<b>Objetivo:</b> O objetivo é criar um sistema controlador de robôs para coordenar a operação de extração de um composto (Composto Z). Esse recurso é necessário para restaurar a condição de vida na Terra. O Composto Z é encontrado em um planeta distante, em outra galáxia.

<b>Entrada 1:</b> Recebemos um mapa do planeta no arquivo <i>mapa.txt</i>

Exemplo:
```bash
10 10
B . . . . . O O O .     
. . . . . . O O O .     
. . . . R O O O R .
. . . R O O O O R .
. H . O O O O R . .
. . . R O O R . . .
. . . . . . . . . .
. . . H R R . . . .
. . . H R R . . . .
. . . . H . . . . .
```
* Primeira linha: Quantidade de linhas e colunas do mapa
* B: Base dos robôs, comporta 50 robôs.
* R: Recurso (Composto Z), coletado pelos robôs.
* H: Alien (Inimigo), os robôs devem eliminá-los.
* O: Obstáculo, os robôs não conseguem se movimentar até lá.
* .: Espaço vazio.

<b>Entrada 2:</b> Recebemos um arquivo com os comandos que devem ser executados pelo(s) robô(s) <i>comandos.txt</i>. Os comandos prioritários com (*) na frente, são executados primeiro que os outros.

Exemplo:
```bash
ATIVAR 0       
MOVER 0 (1,1)
EXECUTAR 0
MOVER 0 (0,6)
*COLETAR 0
*MOVER 0 (2,4)
MOVER 0 (4,1)
ELIMINAR 0
EXECUTAR 0
RELATORIO 0
RETORNAR 0
```

<b>Saída:</b> A saída é exibida na linha de comando. Para os exemplos acima, a saída deverá ser:
```bash
BASE: ROBO 0 SAIU EM MISSAO
ROBO 0: MOVEU PARA (1,1)
ROBO 0: MOVEU PARA (2,4)
ROBO 0: RECURSOS COLETADOS EM (2,4)
ROBO 0: IMPOSSIVEL MOVER PARA (0,6)
ROBO 0: MOVEU PARA (4,1)
ROBO 0: ALIEN ELIMINADO EM (4,1)
BASE: ROBO 0 RETORNOU ALIENS 1 RECURSOS 1
BASE: TOTAL DE ALIENS 1 RECURSOS 1
```

<b>Execuçao:</b> Na pasta principal do programa, executar o comando make. Na pasta bin rodar o programa fornecendo os arquivos na linha de comando.
```bash
make
cd bin
./run.out mapa.txt comandos.txt
```