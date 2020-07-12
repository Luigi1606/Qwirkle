#include "libqwirkle.h"

int jogarch(int ordem, int tam, char *tabuleiro, char*pecas, int *pontos, int times, int *xant, int *yant, int *trava){
  int peca = -1;
  int flag = -1;
  int x;
  int y;

  do{
    char jogada[3];
    printf("digite a peca que deseja jogar CHEAT MODE(ex: A1): ");
    fgets(jogada, 3, stdin);
    for(int i = 0; i< 216; i+=2){
      if(pecas[i]==jogada[0] && pecas[i+1]==jogada[1]){
        peca = i;
        break;
      }
    }
  }while(peca<0);
  int a;
  int posicao = 0;
  do{
    if(posicao<0){
      printf("Para jogar em outra coordenada digite 1.\nPara cancelar jogada digite 2.\n");
      scanf("%d", &a);
      if(a!=1){
        return 0;
      }
    }
    do{
      printf("digite as cordenadas (X Y) para jogar: ");
      scanf("%d %d",&y, &x);
      if(x<0||x>=tam || y<0 || y>=tam){
        printf("jogada invalida\n");
      }
    }while(x<0||x>=tam || y<0 || y>=tam);
    posicao = 2*x + (2*y*tam);

    if(tabuleiro[posicao]!= ' '){
        printf("casa ja ocupada\n");
        posicao = -1;
      }
    if(posicao != -1){
        if(times==1){
          if(y == *yant){
            *trava = 1; //Travado na linha
            if(x > *xant){
              for(int l =1; l< x-*xant; l++){
                if(tabuleiro[posicao-l*2]==' '){
                  printf("Jogada Invalida\n");
                  posicao = -1;
                  break;
                }
              }
            }else{
              for(int l =1; l< *xant-x; l++){
                if(tabuleiro[posicao+l*2]==' '){
                  printf("Jogada Invalida\n");
                  posicao = -1;
                  break;
                }
              }
            }
          }else if(x == *xant){
            *trava = 2;

            if(y > *yant){
              for(int l=tam; l< (y-*yant)*tam; l += tam){
                if(tabuleiro[posicao-l*2]==' '){
                  printf("Jogada Invalida\n");
                  posicao = -1;
                  break;
                }
              }
            }else{
              for(int l =tam; l<(*yant-y)*tam; l+= tam){
                if(tabuleiro[posicao+l*2]==' '){
                  printf("Jogada Invalida\n");
                  posicao = -1;
                  break;
                }
              }
            }

          }else{
            printf("Jogada Invalida\n");
            posicao = -1;
          }
        }else if(times > 1){
          if(*trava == 1){
            if(y != *yant){
              printf("Jogada Invalida\n");
              posicao = -1;
            }else{
              
            }
          }else{
            if(*trava == 1){
                if(y != *yant){
                  printf("Jogada Invalida\n");
                  posicao = -1;
                }else{
                  if(x > *xant){
                  for(int l =1; l< x-*xant; l++){
                    if(tabuleiro[posicao-l*2]==' '){
                      printf("Jogada Invalida\n");
                      posicao = -1;
                      break;
                    }
                  }
                }else{
                  for(int l =1; l< *xant-x; l++){
                    if(tabuleiro[posicao+l*2]==' '){
                      printf("Jogada Invalida\n");
                      posicao = -1;
                      break;
                    }
                  }
                }
              }
            }else if(*trava == 2){
              if(x != *xant){
                printf("Jogada Invalida\n");
                posicao = -1;
              }else{
                if(y > *yant){
                  for(int l=tam; l< (y-*yant)*tam; l += tam){
                    if(tabuleiro[posicao-l*2]==' '){
                      printf("Jogada Invalida\n");
                      posicao = -1;
                      break;
                    }
                  }
                }else{
                  for(int l =tam; l<(*yant-y)*tam; l+= tam){
                    if(tabuleiro[posicao+l*2]==' '){
                      printf("Jogada Invalida\n");
                      posicao = -1;
                      break;
                    }
                  }
                }
              }
            }
          }
        }
    
    int somaesp = 0;
    if(tam>1){
      if((x == tam -1) || (tabuleiro[posicao+2]==' ')){
        somaesp ++;
      }
      if((x == 0) || (tabuleiro[posicao-2]==' ')){
        somaesp ++;
      }
      if((y == tam-1)||(tabuleiro[posicao+(2*tam)] == ' ')){
        somaesp ++;
      }
      if((y == 0)||(tabuleiro[posicao-(2*tam)] == ' ')){
        somaesp ++;
      }
      if(somaesp == 4){
        printf("jogada invalida\n");
        posicao = -1;
      }
    }

      for(int i = 1; i< 2;i++){
        if(x < tam-i && (tabuleiro[posicao+2*i]!=pecas[ peca] && tabuleiro[posicao +2*i+1]!=pecas[peca+1]) && tabuleiro[posicao+2*i]!= ' '){
          printf("jogada invalida\n");
          posicao = -1;
          break;

        }else if(x+1-i > 0 && tabuleiro[posicao-2*i]!=pecas[peca]&&tabuleiro[posicao -2*i+1]!=pecas[peca+1] && tabuleiro[posicao-2*1]!= ' '){
          printf("jogada invalida\n");
          posicao = -1;
          break;

        }else if(y < tam-i && tabuleiro[posicao+(2*i*tam)]!=pecas[peca]&&tabuleiro[posicao+1+(2*i*tam)]!=pecas[peca+1] && tabuleiro[posicao+(2*i*tam)]!= ' '){
          printf("jogada invalida\n");
          posicao = -1;
          break;

        }else if(y+1-i > 0 && tabuleiro[posicao-(2*i*tam)]!=pecas[peca]&&tabuleiro[posicao+1-(2*i*tam)]!=pecas[peca+1] && tabuleiro[posicao-(2*i*tam)]!= ' '){
          printf("jogada invalida\n");
          posicao = -1;
          break;
        }
      }
    }
    
  if(posicao != -1){
      for(int i = 1; i<6 && tabuleiro[posicao+2*i]!= ' '; i++){
        if(posicao+2*i < (y+1)*2*tam && tabuleiro[posicao+2*i]==pecas[peca] && tabuleiro[posicao+(2*i)+1]==pecas[peca +1]){
          printf("jogada invalida\n");
          posicao = -1;
          break;
        }
      }
      for(int i = 1; i<6 && tabuleiro[posicao-2*i]!= ' '; i++){
        if(posicao-2*i > (2*y*tam)-1 && tabuleiro[posicao-2*i]==pecas[peca] && tabuleiro[posicao+1-(2*i)]==pecas[peca +1]){
          printf("jogada invalida\n");
          posicao = -1;
          break;
        }
      }for(int i = 1; i<6 && tabuleiro[posicao+(2*tam*i)]!= ' '; i++){
        if( posicao+(2*i*tam) <= 2*(tam + x-1)*tam && tabuleiro[posicao+(2*i*tam)]==pecas[peca] && tabuleiro[posicao+1+(2*i*tam)]==pecas[peca +1]){
          printf("jogada invalida\n");
          posicao = -1;
          break;
        }
      }for(int i = 1; i<6 && tabuleiro[posicao-(2*tam*i)]!= ' '; i++){
        if(posicao-(2*i*tam)> 0 && tabuleiro[posicao-(2*i*tam)]==pecas[peca] && tabuleiro[posicao+1-(2*i*tam)]==pecas[peca +1]){
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
  }while(posicao == -1);
  
  tabuleiro[posicao] = pecas[peca];
  tabuleiro[posicao+1] = pecas[peca+1];
  *xant = x;
  *yant = y;
   int dealer = 0;
   for(int i = 0; i < 216; i+=2){
     if(pecas[i]!= 0){
       break;
     }else if(i==214){
       pontos[ordem]+=12;
       return-1;
     }
   }
   
    pecas[peca]= 0;
    pecas[peca+1] = 0;
    contapont(x, y, posicao,pontos, tam, tabuleiro, ordem, times);
  if(flag==1){
   return 1;
  }
  return 0;
}