#include "libqwirkle.h"

int jogar(int ordem, char *jogador, int tam, char *tabuleiro){
  int peca = -1;
  int flag = 1;
  do{
    char jogada[3];
    printf("digite a peca que deseja jogar (ex: A1)");
    fgets(jogada, 3, stdin);
    for(int i = 0; i< 12; i+=2){
      if(jogador[(ordem*12)+i]==jogada[0] && jogador[(ordem*12)+i+1]==jogada[1]){
        peca = i;
        break;
      }
    }
  }while(peca<0);
  
  int posicao;
  do{
    int x;
    int y;
    do{
      printf("digite a cordenada X para jogar: ");
      scanf("%d", &x);
      if(x<0 || x>=tam){
        printf("jogada invalida\n");
      }
    }while(x<0 || x>=tam);
    do{
      printf("digite a cordenada Y para jogar: ");
      scanf("%d", &y);
      if(y<0||y>=tam){
        printf("jogada invalida\n");
      }
    }while(y<0||y>=tam);
    posicao = 2*x + (2*y*tam);
    if(tabuleiro[posicao]!= ' '){
      printf("casa ja ocupada");
    } 


    if(x!= tam-1 && tabuleiro[posicao+2]!=jogador[peca]&&tabuleiro[posicao +3]!=jogador[peca+1] && tabuleiro[posicao+2]!= ' '){
      printf("jogada invalida");
      posicao = -1;

    }else if(x!= 0 &&  tabuleiro[posicao-2]!=jogador[peca]&&tabuleiro[posicao -1]!=jogador[peca+1] && tabuleiro[posicao-2]!= ' '){
      printf("jogada invalida");
      posicao = -1;

    }else if(y != tam-1 && tabuleiro[posicao+(2*tam)]!=jogador[peca]&&tabuleiro[posicao+1+(2*tam)]!=jogador[peca+1] && tabuleiro[posicao+(2*tam)]!= ' '){
      printf("jogada invalida");
      posicao = -1;

    }else if(y != 0 && tabuleiro[posicao-(2*tam)]!=jogador[peca]&&tabuleiro[posicao+1-(2*tam)]!=jogador[peca+1] && tabuleiro[posicao-(2*tam)]!= ' '){
      printf("jogada invalida");
      posicao = -1;

    }else{
      for(int i = 1; i<tam; i++){
        if(posicao+2*i < (y+1)*2*tam && tabuleiro[posicao+2*i]==jogador[peca] && tabuleiro[posicao+(2*i)+1]==jogador[peca +1]){
          printf("jogada invalida");
          posicao = -1;
          break;
        }
        if(posicao-2*i > (2*y*tam)-1 && tabuleiro[posicao-2*i]==jogador[peca] && tabuleiro[posicao+1-(2*i)]==jogador[peca +1]){
          printf("jogada invalida");
          posicao = -1;
          break;
        }
        if( posicao+(2*i*tam) <= 2*(tam + x-1)*tam && tabuleiro[posicao+(2*i*tam)]==jogador[peca] && tabuleiro[posicao+1+(2*i*tam)]==jogador[peca +1]){
          printf("jogada invalida");
          posicao = -1;
          break;
        }
        if(posicao-(2*i*tam)> 0 && tabuleiro[posicao-(2*i*tam)]==jogador[peca] && tabuleiro[posicao+1-(2*i*tam)]==jogador[peca +1]){
          printf("jogada invalida");
          posicao = -1;
          break;
        }
      }
    }
    if(x==tam-1||x==0){
      flag =1;
    }else if(y==tam-1||y== 0){
      flag = 1;
    }
  }while(tabuleiro[posicao]!= ' ' && posicao > 0);
  tabuleiro[posicao] = jogador[peca];
  tabuleiro[posicao+1] = jogador[peca+1];
  if(flag){
   return 1;
  }
  return 0;
}