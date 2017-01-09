#include "Classe_ABR.h"
#include <stdio.h>


int main(){
  int a = 2;
  ABR arbre = ABR(a);
  ABR newa = arbre.recherche(2,arbre);
  printf("%d\n",*newa.cle());
}
