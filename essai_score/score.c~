#include <stdlib.h>

#include <stdio.h>

void tri(int n, int tab[n]);

int main(){
  int k;
  FILE* fichier = NULL;
  fichier = fopen("score.txt","w");
  fprintf(fichier, "10\n1\n4\n7\n1");
  fclose(fichier);


  fichier = fopen("score.txt","r");
  int score[5]={0};
  fscanf(fichier,"%d\n%d\n%d\n%d\n%d", &score[0], &score[1],&score[2],&score[3],&score[4]);
  printf("%d\n%d\n%d\n%d\n%d\n\n", score[0], score[1],score[2],score[3],score[4]);
  tri(5,score);
  fclose(fichier);
  return 0;
}

void tri(int n, int tab[n]){
  int a,i,j,k;
  for(i=0; i<(n-1); i++){
    for(j=i+1; j<(n); j++){
      if(tab[i]>tab[j]){
        a = tab[i];
        tab[i] = tab[j];
        tab[j] = a;
      }
    }
  }
  
  for(k = 0; k<(n); k++)
    printf("%d\n",tab[k]);
}
