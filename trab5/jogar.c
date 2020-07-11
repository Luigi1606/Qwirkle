#include "libqwirkle.h"

int jogar(int ordem, char *jogador, int tam, char *tabuleiro, char*pecas, int *pontos){
  int peca = -1;
  int flag = 1;
  int x;
  int y;
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
  int a;
  int posicao = 0;
  do{
    if(posicao<0){
      printf("Para jogar digite 1.\nPara sair digite 2.\n");
      scanf("%d", &a);
      if(a!=1){
        return 0;
      }
    }
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
      printf("casa ja ocupada\n");
      posicao = -1;
    } 

    for(int i = 1; i< tam;i++){
      if(x < tam-i && tabuleiro[posicao+2*i]!=jogador[ordem*12 +peca] && tabuleiro[posicao +2*i+1]!=jogador[ordem*12+peca+1] && tabuleiro[posicao+2*i]!= ' '){
        printf("jogada invalida\n");
        posicao = -1;
        break;

      }else if(x+1-i > 0 &&  tabuleiro[posicao-2*i]!=jogador[ordem*12+peca]&&tabuleiro[posicao -2*i+1]!=jogador[ordem*12+peca+1] && tabuleiro[posicao-2*1]!= ' '){
        printf("jogada invalida\n");
        posicao = -1;
        break;

      }else if(y < tam-i && tabuleiro[posicao+(2*i*tam)]!=jogador[ordem*12+peca]&&tabuleiro[posicao+1+(2*i*tam)]!=jogador[ordem*12+peca+1] && tabuleiro[posicao+(2*i*tam)]!= ' '){
        printf("jogada invalida\n");
        posicao = -1;
        break;

      }else if(y+1-i > 0 && tabuleiro[posicao-(2*i*tam)]!=jogador[ordem*12+peca]&&tabuleiro[posicao+1-(2*i*tam)]!=jogador[ordem*12+peca+1] && tabuleiro[posicao-(2*i*tam)]!= ' '){
        printf("jogada invalida\n");
        posicao = -1;
        break;
      }
    }
    if(posicao >= 0){
      for(int i = 1; i<tam; i++){
        if(posicao+2*i < (y+1)*2*tam && tabuleiro[posicao+2*i]==jogador[ordem*12+peca] && tabuleiro[posicao+(2*i)+1]==jogador[ordem*12+peca +1]){
          printf("jogada invalida\n");
          posicao = -1;
          break;
        }
        if(posicao-2*i > (2*y*tam)-1 && tabuleiro[posicao-2*i]==jogador[ordem*12+peca] && tabuleiro[posicao+1-(2*i)]==jogador[ordem*12+peca +1]){
          printf("jogada invalida\n");
          posicao = -1;
          break;
        }
        if( posicao+(2*i*tam) <= 2*(tam + x-1)*tam && tabuleiro[posicao+(2*i*tam)]==jogador[ordem*12+peca] && tabuleiro[posicao+1+(2*i*tam)]==jogador[ordem*12+peca +1]){
          printf("jogada invalida\n");
          posicao = -1;
          break;
        }
        if(posicao-(2*i*tam)> 0 && tabuleiro[posicao-(2*i*tam)]==jogador[ordem*12+peca] && tabuleiro[posicao+1-(2*i*tam)]==jogador[ordem*12+peca +1]){
          printf("jogada invalida\n");
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
  }while(tabuleiro[posicao]!= ' ' || posicao < 0);
  tabuleiro[posicao] = jogador[ordem*12+peca];
  tabuleiro[posicao+1] = jogador[ordem*12+peca+1];
   int dealer = 0;
   for(int i = 0; i < 216; i+=2){
     if(pecas[i]!= 0){
       break;
     }else if(i==214){
       pontos[ordem]+=12;
       return-1;
     }
   }
   while((pecas[dealer]==0)||((dealer+2)%2!=0)){
     dealer = rand() % 216;
    }
    jogador[ordem*12+peca] = pecas[dealer];
    jogador[ordem*12+peca+1]= pecas[dealer+1];
    pecas[dealer]= 0;
    pecas[dealer+1] = 0;
    contapont(x, y, posicao,pontos, tam, tabuleiro, ordem);
  if(flag){
   return 1;
  }
  return 0;
}