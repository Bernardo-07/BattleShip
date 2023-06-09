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
      //se as coordenada x digitada está entre 1 e 5 então, irá digitar a coordenada y
      
      while(n[i][1] <1 || n[i][1] >5){
        printf("Valor inválido, digite um número no intervalo [1,5]: ");
        scanf("%d",&n[i][1]);
        //enquanto a coordenada y não estiver no intervalo de 1 a 5, terá que digitar uma nova coordenada
      }
    }else{
      
      while(n[i][0] <1 || n[i][0] >5){
        printf("Valor inválido, digite um número no intervalo [1,5]: ");
        scanf("%d",&n[i][0]);
        //enquanto a coordenada x não estiver no intervalo de 1 a 5, terá que digitar uma nova coordenada
      }
      //ao digitar um valor válido para a coordenada x, então prossiga para digitar a coordenada y
      printf("Digite a coluna do navio %d: ",i+1);
      scanf("%d",&n[i][1]);
      
      while(n[i][1] <1 || n[i][1] >5){
        printf("Valor inválido, digite um número no intervalo [1,5]: ");
        scanf("%d",&n[i][1]);
        //faz a checagem se a coordenada y digitada está no intervalo válido
      }
    }

  }
  system("clear");
}

int main(){
  
  int navios1[3][2], navios2[3][2];
  int tabuleiro1, tabuleiro2;
  int turno = 1;
  int tiro[2];
  int i;
  int pontos1=0, pontos2=0;
  int acerto=0; //acerto foi definido como falso
  char vazio;
  
  tabuleiro();
  printf("\nJogador 1, digite as coordenadas dos seus três navios:\n");
  posicionamento(navios1);
  
  tabuleiro();
  printf("\nJogador 2, digite as coordenadas dos seus três navios:\n");
  posicionamento(navios2);

  do{
    switch(turno){
      case 1:
        system("clear");
        printf("\nVez do jogador 1:\n");
        tabuleiro();
      
        printf("Linha (1-5): ");
        scanf("%d",&tiro[0]);
        printf("Coluna (1-5): ");
        scanf("%d",&tiro[1]);

        for(i=0; i<3; i++){
          if(tiro[0] == navios2[i][0] && tiro[1] == navios2[i][1]){
            acerto = 1;
            pontos1++;
            //se o jogador acertar as coordenadas de algum navio inimigo então sua contagem de pontos aumenta e a variável acerto fica definida como verdadeira
          }
        }
        if (acerto == 1){
          printf("\nVocê acertou o tiro!, Pontos = %d",pontos1);
        }else{
          printf("\nVocê errou o tiro..., Pontos = %d",pontos1);
        }
        printf("\nDigite algo e dê enter para continuar\n");
        scanf("%s",&vazio);
        acerto = 0;
        turno = 2;
        //reseta a variável acerto para falso e muda o turno de jogo
      break;
      case 2:
        system("clear");
        printf("\nVez do jogador 2:\n");
        tabuleiro();
      
        printf("Linha (1-5): ");
        scanf("%d",&tiro[0]);
        printf("Coluna (1-5): ");
        scanf("%d",&tiro[1]);

        for(i=0; i<3; i++){
          if(tiro[0] == navios1[i][0] && tiro[1] == navios1[i][1]){
            acerto = 1;
            pontos2++;
          }
        }
        if (acerto == 1){
          printf("Você acertou o tiro!, Pontos = %d",pontos2);
        }else{
          printf("Você errou o tiro..., Pontos = %d",pontos2);
        }
        printf("\nDigite algo e dê enter para continuar\n");
        scanf("%s",&vazio);
        acerto = 0;
        turno = 1;
      break;
    }
  }while(pontos1!=3 || pontos2!=3); //continua rodando enquanto a contagem de pontos não chega ao máximo (3 pts) 
  
  return 0;
}