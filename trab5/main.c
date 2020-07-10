#include "libqwirkle.h"

int main(){
  printf("\e[H\e[2J");
    int njog;
  do{
  printf("Informe o numero de jogadores:\n");
  scanf("%d", &njog);
  if(njog>18){
    printf("Nao ha pecas o suficiente para mais do que 18 jogadores");
  }
  }while(njog >18);
  getchar();
  int *pontos = (int*) malloc(njog*sizeof(int));
  if(pontos == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
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

  for(int j = 0; j<12*njog; j+=2){
   int dealer = 0;
   while((pecas[dealer]==0)||((dealer+2)%2!=0)){
     dealer = rand() % 216;
    }
   jogador[j] = pecas[dealer];
   jogador[j+1]= pecas[dealer+1];
   pecas[dealer]= 0;
   pecas[dealer+1] = 0;
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

  printf("__________________________________________________\n\nVez do jogador %s\nSuas pecas sao:\n", nomes[ordem]);
  for(int i = 0; i<12;i++){
    printf("%c", jogador[(ordem*12)+i]);
    if((i+3)%2==0){
      printf(" ");
    }
  }
  printf("\n\nPara JOGAR digite: 1\nPara TROCAR PECAS digite: 2\n\n______________________________________________ ");
  int escolha;
  scanf("%d", &escolha);
  getchar();
  int tam = 1;
  char *tabuleiro = (char*)malloc(2*sizeof(char));
  if(tabuleiro == NULL){
    printf("Nao ha memoria suficiente");
    exit(0);
  }
  tabuleiro[0] = ' ';
  tabuleiro[1] = ' ';
  tabu(tam, tabuleiro);
  int flag;
  if(escolha ==1){
      while(escolha != 2){
      flag = jogar(ordem, jogador, tam, tabuleiro,pecas);
      if(flag){
        tabuleiro = aumentatab(&tam, tabuleiro);
      }
      tabu(tam, tabuleiro);
      printf("Para jogar novamente digite 1.\nPara terminar a jogada digite 2.\n______________________________________________\n");
      scanf("%d", &escolha);
      getchar();
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