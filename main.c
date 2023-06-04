#include <stdio.h>
#include <stdlib.h>

void tabuleiro(){
  int i, j;
  printf(" | 0 | 1 | 2 | 3 | 4 | 5 |\n");
  for(i=0; i<5; i++){
    printf(" | %d",i+1);
    for(j=0; j<5; j++){
      printf(" | .");
    }
    printf(" |\n");
  }
}

void posicionamento(int n[3][2]){
  int i;
  for (i=0; i<3; i++){
    printf("\nDigite a linha do navio %d: ",i+1);
    scanf("%d",&n[i][0]);
    if(n[i][0] >=1 && n[i][0] <=5){
      printf("Digite a coluna do navio %d: ",i+1);
      scanf("%d",&n[i][1]);
      while(n[i][1] <1 || n[i][1] >5){
        printf("Valor inválido, digite um número no intervalo [1,5]: ");
        scanf("%d",&n[i][1]);
      }
    }else{
      while(n[i][0] <1 || n[i][0] >5){
        printf("Valor inválido, digite um número no intervalo [1,5]: ");
        scanf("%d",&n[i][0]);
      }
      printf("Digite a coluna do navio %d: ",i+1);
      scanf("%d",&n[i][1]);
      while(n[i][1] <1 || n[i][1] >5){
        printf("Valor inválido, digite um número no intervalo [1,5]: ");
        scanf("%d",&n[i][1]);
      }
    }
  }
  system("clear");
}

int main(){
  int navios1[3][2], navios2[3][2];
  tabuleiro();
  printf("\nJogador 1, digite as coordenadas dos seus três navios:\n");
  posicionamento(navios1);
  tabuleiro();
  printf("\nJogador 2, digite as coordenadas dos seus três navios:\n");
  posicionamento(navios2);
  return 0;
}