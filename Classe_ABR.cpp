#include "Classe_ABR.h"
 
//constructors
ABR::ABR(int cle){
	int* cle_ = &cle;
	int** fg_ = nullptr ;
	int** fd_ = nullptr;
} 

ABR::ABR(const ABR& model){
	int* cle_ = model.cle_
	int** fg_ = model.fg_ 
	int** fd_ = model.fd_
}

//Constructeur par defaut
ABR::ABR(){
  int* cle_;
  *cle_ =0;
  int** fg_=nullptr;
  int** fd_=nullptr;
}


// Methodes :
 ABR::validation(){
 	if (fg_ == nullptr && fd_ == nullptr){
 		return false
 	}
 	else {return true}
 }
