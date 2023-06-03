#include <stdio.h>

void tabuleiro(){
  int i, j;
  for(i=0; i<5; i++){
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