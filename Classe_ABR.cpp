#include "Classe_ABR.h"
 
//constructors
ABR::ABR(int cle){
	int* cle_ = &cle;
	int** fg_ = nullptr ;
	int** fd_ = nullptr;
} 

ABR::ABR(const ABR& model){
	int* cle_ = model.cle_
	ABR* fg_ = model.fg_ 
	ABR* fd_ = model.fd_
}

//Constructeur par defaut
ABR::ABR(){
  int* cle_=nullptr;
  ABR* fg_=nullptr;
  ABR* fd_=nullptr;
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
ABR::set_cle(int a){
	cle_ = &a;
}
// Methodes :
 ABR::validation(){
 	if (fg_ == nullptr && fd_ == nullptr && cle_ == nullptr){
 		return false;
 	}
 	else {return true};
 }

ABR::recherche(int nb, ABR racine){
	if (*racine.cle_ == nb){
		return racine
	}
}
