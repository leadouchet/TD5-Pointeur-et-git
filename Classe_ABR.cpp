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


void supress(int a){
	ABR* noeud = recherche(a)
	if (noeud->fg_ == nullptr && noeud->fd_ == nullptr){ 
		delete noeud->cle_
	}
	else if(noeud.fg_ == nullptr){
		noeud.cle_ = noeud->fd_;
		delete noeud.fd;
	} 
	else if (noeud.fd_== nullptr){

	}
}

ABR ABR::rechercheparent(int nb){
	//retourne un arbre vide 
	if (racine.validation( == false){
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
