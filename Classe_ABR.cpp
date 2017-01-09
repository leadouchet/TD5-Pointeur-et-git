#include "Classe_ABR.h"
 
//constructors
ABR::ABR(int a){
	valeur_ = a;
	cle_ = &valeur_;	
	fg_ = nullptr;
	fd_ = nullptr;
}

ABR::ABR(const ABR& model){
	valeur_ = model.valeur_;
	cle_ = model.cle_;
	fg_ = model.fg_ ;
	fd_ = model.fd_;
}

//Constructeur par defaut
ABR::ABR(){
  valeur_ = 0;
  cle_=&valeur_;
  fg_=nullptr;
  fd_=nullptr;
}

//getters
int* ABR::cle(){
	return cle_;
}
ABR* ABR::fg(){
	return fg_;
}

ABR* ABR::fd(){
	return fd_;
}
//Setter 
void ABR::set_cle(int a){
	valeur_=a;
}
// Methodes :
bool ABR::validation(){
 	if (fg_ == nullptr && fd_ == nullptr){
 		return false;
 	}
 	else {return true;}
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
