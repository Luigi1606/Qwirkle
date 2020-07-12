#include "libqwirkle.h"

void contapont(int x, int y, int posicao, int *pontos, int tam, char *tabuleiro, int ordem, int times){
  int soma = 0;
  for(int i = 2; tabuleiro[posicao+i] != ' ' && posicao+i<(tam*(y+1)*2)-2; i+=2){
    soma++;
  }
  for(int i = 2; tabuleiro[posicao-i] != ' ' && posicao-i>tam*(y-1)*2; i+=2){
    soma++;
  }
  if(soma==5){
    printf("Qwirkleeeee!!!!!!!!!!!!\n\n\n");
    soma +=6;
  }
  // printf("SCORE MARCADO: %d\n", soma);
  pontos[ordem]+=soma;
  soma = 0;
  for(int i = 2*tam; tabuleiro[posicao+i]!= ' ' && i< tam*tam; i+=2*tam){
    soma++;
  }
  for(int i = 2*tam; tabuleiro[posicao-i]!= ' ' && (posicao-i)>0; i+=2*tam){
    soma++;
  }
  if(soma == 5){
    printf("Qwirkleeeee!!!!!!!!!!!!!\n\n\n");
    soma+=6;
  }
  // printf("SCORE MARCADO: %d\n", soma);
  pontos[ordem]+=soma+1-times;
}