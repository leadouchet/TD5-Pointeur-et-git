#include "Classe_ABR.h"
 

//Constructeur par defaut
ABR::ABR(){
  cle_=nullptr;
  fg_=nullptr;
  fd_=nullptr;
}


// Methodes :
bool ABR::vide(){
 	if (cle_== nullptr){
 		return true;
 	}
 	else {return false;}
 }

ABR ABR::recherche(int nb, ABR racine){
	//retourne un arbre vide 
	if (racine.validation() == false){
		return ABR(10);
	}
	if (*racine.cle() == nb){return racine;}
	else{
		if (*racine.cle() < nb){
			recherche(nb,*racine.fd());
		}
		else {recherche(nb,*racine.fg());}
	}
}
