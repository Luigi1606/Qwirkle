#include "libqwirkle.h"

void tabu(int tam, char *tabuleiro){
  printf("  ");
  int k =0;
  for(int i = 0; i<tam; i++){
    printf("| %d ", i);
  }
  printf("|\n");
  for(int i = 0; i<tam; i++){
    for(int j = 0; j < tam+2; j++){
      printf("__  ");
    }
    printf("\n\n");
    printf("%d |", i);
    do{
      printf("%c", tabuleiro[k]);
      k++;
      printf("%c |", tabuleiro[k]);
      k++;
    }while((k+2*tam) % tam*2 !=0);
    printf(" %d\n", i);

  }
  for(int j = 0; j < tam+2; j++){
    printf("__  ");
  }
  printf("\n\n  ");
  for(int i = 0; i<tam; i++){
    printf("| %d ", i);
  }
  printf("|\n");
}