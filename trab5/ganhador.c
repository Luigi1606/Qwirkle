#include "libqwirkle.h"

void ganhador(int njog, int *pontos, char **nomes){
  int maior=0;
  int vencedor;
  int empate[njog+1];
  int flag = 0;
  for(int i = 0; i<njog; i++){
    if(pontos[i] > maior){
      flag = 0;
      maior = pontos[i];
      vencedor = i;
    }else if(pontos[i]==maior){
      empate[flag]=vencedor;
      flag++;
      empate[flag]= i;
      empate[flag+1]= -1;
    }
  }
  if(flag){
    printf("Empate!!!!!!!!!!!!!!\n\nOs vencedores sao:");
    int i = 0;
    while(empate[i]!=-1 && i<njog){
      printf("%s\n", nomes[empate[i]]);
      i++;
    }
  }else{
    printf("O vencedor é: %s", nomes[vencedor]);
  }
}