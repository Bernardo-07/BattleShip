#include <stdio.h>
#include <stdlib.h>

void tabuleiro(){
  int i, j;
  printf(" |   | 1 | 2 | 3 | 4 | 5 |\n");
  for(i=0; i<5; i++){
    printf(" | %d",i+1);
    for(j=0; j<5; j++){
      printf(" | .");
    }
    printf(" |\n");
  }
}

int main(){
  tabuleiro();
  return 0;
}