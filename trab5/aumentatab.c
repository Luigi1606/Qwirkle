#include "libqwirkle.h"

char *aumentatab(int *tam, char *tabuleiro){
  *tam +=2;
  char *p = (char *) malloc(*tam**tam*2*sizeof(char));
  if(p == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }
  char b;
  int i = 0;
  int j =0;
  while(i<*tam*2){
    p[i] = ' ';
    i++;
  }
  for(int m = 0; m < *tam-2; m++){
    p[i]= ' ';
    i++;
    p[i]= ' ';
    i++;
    j=0;
    do{
      p[i] = tabuleiro[j+(m*(*tam-2)*2)];
      i++;
      j++;
      p[i] = tabuleiro[j+(m*(*tam-2)*2)];
      i++;
      j++;
    }while(j < (*tam-2)*2 );
    p[i]= ' ';
    i++;
    p[i]= ' ';
    i++;
  }
  for(int l = 0; l<*tam*2; l++){
    p[i]=' ';
    i++;
  }
  free(tabuleiro);
  return p;
}