#include "Classe_ABR.h"
#include <stdio.h>
 

//Constructeur par defaut
ABR::ABR(){
  cle_=nullptr;
  fg_=nullptr;
  fd_=nullptr;
}

ABR::~ABR(){
  delete fd_;
  delete fg_;
  delete cle_;
}


// Methodes :
bool ABR::vide(){
 	if (cle_== nullptr){
 		return true;
 	}
 	else {return false;}
 }

ABR* ABR::recherche(int nb){
	//retourne un ABR vide si l'ABR est vide
	if (this->vide() == true){
		// L'ABR est vide
		return this;
		}
	//renvoie le noeud (sous ABR) qui contient cette cle	
	if (*this->cle_ == nb){
		// La cle recherchee est dans ce noeud
		return this;
		}
		
	else{
		// on regarde de quel coté doit se trouver la clé
		if (*this->cle_ < nb){
			if (this->fd_ != nullptr){
				// on regarde si le fils droit existe
				return this->fd_->recherche(nb);
			}
			else{
				return this;
			}
		}
		
		else if (*this->cle_ > nb){
			if (this->fg_ != nullptr){
				// on regarde si le fils gauche existe
				return this->fg_->recherche(nb);
			}
			else{
				return this;
			}
		}
	}
}


void ABR::insertion(int a){
  ABR* parent = this->recherche (a);
  if (parent->vide()==true){
    parent->cle_= new int ;
    *(parent->cle_) = a;
    return;
  }

  //pas indispensable mais cool pour comprendre 

  else if (*parent->cle_ == a)
    return;
  else if (*parent->cle_ != a){
    
    if (*parent->cle_ > a){
      
      parent->fg_ = new ABR();
      parent->fg_->cle_ = new int(a);
    	}

    else {
      parent->fd_ = new ABR();
      parent->fd_->cle_ = new int(a);
    }

  }}

void ABR::parcours(){
  if (this->fg_ != nullptr){
    fg_->parcours();
  }
  printf("%d\n",*this->cle_);
  if (this->fd_ != nullptr){
    fd_->parcours();
 }
}
int ABR::min(){
	if (this->fg_ == nullptr){
		printf("Le min de cet arbre est : %d \n" , *this->cle_);
		return *this->cle_;
	}
	else{ return this->fg_->min();}
}

int ABR::max(){
	if (this->fd_ == nullptr){
		printf("Le min de cet arbre est : %d \n" , *this->cle_);
		return *this->cle_;
	}
	else{ return this->fd_->max();}
}

ABR* ABR::rechercheparent(int nb){
	//retourne un ABR vide si l'ABR est vide
	if (this->vide() == true){
		// L'ABR est vide
		return this;
		}
	//renvoie le noeud (sous ABR) qui contient cette cle	
	if (*this->fg_-> cle_ == nb){
		// La cle recherchee est dans le fil de ce noeud
		return this;
		}
	else if(*this->fd_-> cle_ == nb){
		// La cle recherchee est dans ce noeud
		return this;
		}
	else{
		// on regarde de quel coté doit se trouver la clé
		if (*this->cle_ < nb){
			if (this->fd_ != nullptr){
				// on regarde si le fils droit existe
				return this->fd_->recherche(nb);
			}
			else{
				return this;
			}
		}
		else if (*this->cle_ > nb){
			if (this->fg_ != nullptr){
				// on regarde si le fils gauche existe
				return this->fg_->recherche(nb);
			}
			else{
				return this;
			}
		}
	}
}
void ABR::supress(int a){ //Ne coupe la racine
	ABR* noeud =this->recherche(a);
	ABR* parent = this->rechercheparent(a);
	if (noeud->fg_ == nullptr && noeud->fd_ == nullptr){
		this->supressfeuille(noeud, parent);
	}
	else if(noeud->fg_ == nullptr){
		if (*parent->fg_->cle_== *noeud->cle_){
			parent->fg_ = noeud-> fd_;
		}
		else {
			parent-> fd_ = noeud-> fd_;
		}	
		delete noeud;
	}
	else if(noeud->fd_ == nullptr){
		if (*parent->fg_->cle_== *noeud->cle_){
			parent->fg_ = noeud-> fg_;
		}
		else {
			parent-> fd_ = noeud-> fg_;
		}	
		delete noeud;
	}
	else {
		int Grand = noeud->fg_->max();
		int Petit = noeud->fd_->min();
		if (*noeud->cle_ - Grand > Petit-*noeud->cle_){
			ABR* replace = this->recherche(Petit);
			ABR* parentreplace = this->rechercheparent(Petit);
			replace->fg_= noeud->fg_;
			replace ->fd_=noeud->fd_;
			if (*parent->fg_->cle_== *noeud->cle_){
				parent->fg_ = replace;
			}
			else {
				parent-> fd_ = replace;
			}
			noeud->fg_=nullptr;
			noeud->fd_=nullptr;
			this->supressfeuille(noeud,parentreplace);
		}	
		else {
			ABR* replace = this->recherche(Grand);
			ABR* parentreplace = this->rechercheparent(Grand);
			replace->fg_= noeud->fg_;
			replace ->fd_=noeud->fd_;
			if (*parent->fg_->cle_== *noeud->cle_){
				parent->fg_ = replace;
			}
			else {
				parent-> fd_ = replace;
			}
			noeud->fg_=nullptr;
			noeud->fd_=nullptr;
			this->supressfeuille(noeud,parentreplace);
		}
	}
}

void ABR::supressfeuille(ABR* feuille, ABR* parent){
	if (*parent-> fg_->cle_ == *feuille->cle_){ 
		parent->fg_ = nullptr;
	}
	else {
		parent ->fd_ = nullptr;
	}
	delete feuille;
}
