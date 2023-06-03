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
    printf("Digite a coluna do navio %d: ",i+1);
    scanf("%d",&n[i][1]);
  //Está aceitando qualquer valor, mas o certo seria aceitar somente valores de 1 a 5, preciso fazer um jeito de que se o usuário errar ele tenha outra possibilidade de digitar as coordenadas novamente em vez de fechar o programa
  }
}

int main(){
  int navios1[3][2];
  tabuleiro();
  printf("\nJogador 1, digite as coordenadas dos seus três navios:\n");
  posicionamento(navios1);
  //printf("Jogador 2, digite as coordenadas dos seus três navios:\n");
  return 0;
}