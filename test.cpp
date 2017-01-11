#include "Classe_ABR.h"
#include <stdio.h>


int main(){
  int a[11] = {10,8,6,9,5,7,15,11,17,13,16};
  ABR* racine = new ABR();
  for (int i=0;i<11;i++){
    racine->insertion(a[i]);
}
  racine->parcours();
  int b = racine->min();
  int c = racine->max();
  delete racine;
  
}
