#include "libqwirkle.h"

int main(){
  printf("\e[H\e[2J");
  
    int njog;
    int cheat = -1;
  do{
    printf("Informe o numero de jogadores:\n");
    scanf("%d", &njog);
    if(njog>18){
      printf("Nao ha pecas o suficiente para mais do que 18 jogadores");
    }
  }while(njog >18 );
  getchar();
  int *pontos = (int*) malloc(njog*sizeof(int));
  if(pontos == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }
  for(int i = 0; i<njog; i++){
    pontos[i]=0;
  }
  char *pecas = malloc(216*sizeof(char));
  if(pecas == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }
  char **nomes = (char**) malloc(njog*sizeof(char*));
  if(nomes == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }
  for(int i = 0; i< njog; i++){
    char *nick = (char*) malloc(50*sizeof(char));
    if(nick == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }
    nomes[i]=nick;
    printf("digite um nome para o jogador #%d:" , i+1);
    fgets(nomes[i], 50,stdin);
  }
  printf("\e[H\e[2J");
  for(int k = 0; k < 6; k++){
    for(int i = 0; i<6; i++){
      for(int j = 0; j<6; j ++){
        pecas[k]= 'A'+i;
        k++;
        pecas[k]= '1'+j;
        k++;
        pecas[k]= 'A'+i;
        k++;
        pecas[k]= '1'+j;
        k++;
        pecas[k]= 'A'+i;
        k++;
        pecas[k]= '1'+j;
        k++;
      }
    }
  }
  char *jogador = malloc(njog*12*sizeof(char));
  if(jogador == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }

  do{
    char c;
    printf("Jogar em Modo Cheat (S/N)? ");
    scanf("%c",&c);
    getchar();
    if(c == 'S' || c== 's'){
      cheat = 1;
    }else if(c == 'N' || c == 'n'){
      cheat = 0;
    }else{
      printf("<Resposta invalida>\n");
    }
  }while(cheat == -1);

  for(int j = 0; j<12*njog; j+=2){
   int dealer = 1;

   srand(time(NULL)+j);
   while((pecas[dealer]==0)||((dealer+2)%2!=0)){
     dealer = rand() % 216;
    }
   jogador[j] = pecas[dealer];
   jogador[j+1]= pecas[dealer+1];
   if(!cheat){
      pecas[dealer]= 0;
      pecas[dealer+1] = 0;
    }
  }

  int k = 0;
  for(int i = 0; i< njog;i++){
    printf("\nPecas do jogador %s\n", nomes[i]);
    for(int j = 0; j< 12; j+=2){
      printf("%c", jogador[k]);
      k++;
      printf("%c ", jogador[k]);
      k++;
    }
    printf("\n\n");
  }
  int primeiro = 0;
  int max = 0;
  for(int i = 0; i< njog*12; i+=12){
    int somal = 0;
    int soman = 0;
    for(int j = 0; j< 6; j++){
      for(int k = 0; k < 12; k+=2){
        if(jogador[k+i]=='A'+j){
          somal ++;
        }
        if(jogador[k+i+1] == '1'+j){
          soman ++;
        }
      }
      if(somal > max){
        max = somal;
        primeiro = i;
      }
      if(soman> max){
        max = soman;
        primeiro = i;
      }
      somal = 0;
      soman = 0;
    }
  }
  primeiro /= 12;
  printf("O primeiro a jogar é: %s\n", nomes[primeiro]);
  int ordem;
  ordem = primeiro;

   int tam = 1;
  char *tabuleiro = (char*)malloc(2*sizeof(char));
  if(tabuleiro == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }
  tabuleiro[0] = ' ';
  tabuleiro[1] = ' ';
  tabu(tam, tabuleiro);
  int end = 1;
  while(end){
    printf("__________________________________________________\n\nVez do jogador %s\nScore: %d\nSuas pecas sao:\n", nomes[ordem],pontos[ordem]);
    for(int i = 0; i<12;i++){
      printf("%c", jogador[(ordem*12)+i]);
      if((i+3)%2==0){
        printf(" ");
      }
    }
    printf("\n\nPara JOGAR digite - 1\nPara TROCAR PECAS digite - 2\nPara PASSAR digite - 3\n\n______________________________________________\n");
    int escolha;
    scanf("%d", &escolha);
    getchar();
    int xant;
    int yant;
    int trava;
    int times = 0;

    int flag;
    if(escolha ==1){
        trava = 0;
        while(escolha != 2){
          if(!cheat){
            flag = jogar(ordem, jogador, tam, tabuleiro, pecas, pontos, times, &xant, &yant,&trava);
            times++;
          }else{
            flag = jogarch(ordem, tam, tabuleiro, pecas, pontos, times, &xant, &yant,&trava);
            times++;
          }

        if(flag == -1){
          end = 0;
          ganhador(njog, pontos, nomes);
          break;
        }
        if(flag){
          tabuleiro = aumentatab(&tam, tabuleiro);
          if(xant != -1){
            xant++;
          }

          if(yant != -1){
            yant++;
          }
        }
        printf("\e[H\e[2J");
        tabu(tam, tabuleiro);
        printf("__________________________________________________\n\nVez do jogador %s\nSuas pecas sao:\n", nomes[ordem]);
        for(int i = 0; i<12;i++){
          printf("%c", jogador[(ordem*12)+i]);
          if((i+3)%2==0){
            printf(" ");
          }
        }
        printf("\nScore: %d\n", pontos[ordem]);
        // printf("\nVezes jogadas: %d\n", times);
        printf("Jogada anterior: %d %d\n", yant, xant);
        printf("Para jogar novamente digite 1.\nPara terminar a jogada digite 2.\n______________________________________________\n");
        scanf("%d", &escolha);
        getchar();
        if(escolha == 2){
          if(!cheat){
            for(int i = 0; i < times; i ++){
              for(int j = 0; j < 12; j+=2){
                if(jogador[ordem*12 +j]=='/'){
                  // printf("ENCONTREI UMA VAZIA CARALHO\n");
                  // exit(0);
                  srand(time(NULL));
                  int dealer = 1;
                  while((pecas[dealer]==0)||((dealer+2)%2!=0)){
                    dealer = rand() % 216;
                  }
                  jogador[ordem*12+j] = pecas[dealer];
                  jogador[ordem*12+j+1]= pecas[dealer+1];
                  pecas[dealer]= 0;
                  pecas[dealer+1] = 0;
                  break;
                }
              }
            }
          }
          times = 0;
        }
      }
    }else if(escolha == 2){
      trocar(pecas,jogador,ordem);
    }
    printf("\e[H\e[2J");
    tabu(tam, tabuleiro);
    ordem++;
    if(ordem == njog){
      ordem = 0;
    }
  }
  for(int i = 0; i <njog; i++){
    free(nomes[i]);
  }
  free(nomes);
  free(jogador);
  free(tabuleiro);
  free(pontos);
  free(pecas);

  return 0;
}