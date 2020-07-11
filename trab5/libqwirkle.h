#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jogar(int ordem, char *jogadores, int tam, char *tabuleiro, char*pecas, int *pontos);
void tabu(int tam, char *tabu);
char *aumentatab(int *tam, char *tabuleiro);
void contapont(int x, int y, int posicao, int *pontos, int tam, char *tabuleiro, int ordem);
void ganhador(int njog, int *pontos, char **nomes);