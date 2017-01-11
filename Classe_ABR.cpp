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
	if (*racine.cle() == nb){return racine;}
	else{
		if (*racine.cle() < nb){
			recherche(nb,*racine.fd());
		}
		else {recherche(nb,*racine.fg());}
	}
}


void ABR::insertion(int a){
  ABR* parent = this->recherche (a);
  if (parent->vide()==true){
    parent->cle_= new int ;
    *(parent->cle_) = a;
  }

  //pas indispensable mais cool pour comprendre 

  else if (*parent->cle_ == a)
    return;
  else if (*parent->cle_ != a){
    
    if (*racine->cle_ < a){
      
      parent->fg_ = new ABR();
      parent->fg_->cle_ = new int(a);
    	}

    else {
      parent->fd_ = new ABR();
      parent->fd_->cle_ = new int(a); 
    }


  }}
