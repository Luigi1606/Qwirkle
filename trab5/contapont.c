#include "libqwirkle.h"

void contapont(int x, int y, int posicao, int *pontos, int tam, char *tabuleiro, int ordem){
  int soma = 1;
  for(int i = 2; tabuleiro[posicao+i] != ' ' && posicao+i<tam*y*2; i+=2){
    soma++;
  }
  for(int i = 2; tabuleiro[posicao-i] != ' ' && posicao-i>tam*(y-1)*2; i+=2){
    soma++;
  }
  if(soma==6){
    printf("Qwirkleeeee!!!!!!!!!!!!\n\n\n");
    soma +=6;
  }
  pontos[ordem]+=(soma-1);
  soma = 1;
  for(int i = 2*tam; tabuleiro[posicao+i]!= ' ' && i< tam*tam; i+=2*tam){
    soma++;
  }
  for(int i = 2*tam; tabuleiro[posicao-i]!= ' ' && (posicao-i)>0; i+=2*tam){
    soma++;
  }
  if(soma == 6){
    printf("Qwirkleeeee!!!!!!!!!!!!!\n\n\n");
    soma+=6;
  }
  pontos[ordem]+=soma;
}