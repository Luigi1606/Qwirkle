#include "libqwirkle.h"

void trocar(char *pecas, char *jogador, int ordem){
  int peca = -1;
  int ntroca;
  printf("Digite o numero de pecas que deseja trocar: ");
  scanf("%d", &ntroca);
  getchar();
  char troc[3];
 for(int i = 0; i<ntroca; i++){
    do{
      printf("digite a peca que deseja trocar (ex: A1): ");
      fgets(troc, 3, stdin);
      for(int i = 0; i< 12; i+=2){
        if(jogador[(ordem*12)+i]==troc[0] && jogador[(ordem*12)+i+1]==troc[1]){
          peca = i;
          break;
        }
      }
    }while(peca<0);
    int dealer = 0;

    while(pecas[dealer]!= 0){
      dealer++;
    }
    pecas[dealer]=troc[0];
    dealer++;
    pecas[dealer]= troc[1];
    
    srand(time(NULL));
    while((pecas[dealer]==0)||((dealer+2)%2!=0)){
      dealer = rand() % 216;
    }
    jogador[ordem*12+peca] = pecas[dealer];
    jogador[ordem*12+peca+1]= pecas[dealer+1];
    pecas[dealer]= 0;
    pecas[dealer+1] = 0;
    getchar();
  }
  
}