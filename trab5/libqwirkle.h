#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int jogar(int ordem, char *jogadores, int tam, char *tabuleiro, char*pecas, int *pontos, int times, int *xant, int *yant, int *trava);

int jogarch(int ordem, int tam, char *tabuleiro, char*pecas, int*pontos, int times, int *xant, int *yant, int *trava);

void tabu(int tam, char *tabu);
char *aumentatab(int *tam, char *tabuleiro);

void contapont(int x, int y, int posicao, int *pontos, int tam, char *tabuleiro, int ordem, int times);
void ganhador(int njog, int *pontos, char **nomes);

void trocar(char *pecas, char *jogador, int ordem);