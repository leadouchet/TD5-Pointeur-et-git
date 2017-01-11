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

//Un arbre est vide si sa cle_ est un pointeur null
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
  if (parent->vide()==true){ //revient a ecrire *parent.vide()
    parent->cle_= new int ;
    *(parent->cle_) = a; //la valeur du parent pointee par le cle
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

// cette fonction sert a remonter dans l arbre pour trouver le parent d une valeur
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

// Cette fonction sert a supprimer un noeud et rearranger ses fils
void ABR::supress(int a){ //Ne coupe la racine
	ABR* noeud =this->recherche(a);
	ABR* parent = this->rechercheparent(a);

	//Si le noeud n as pas de fils alors c est une feuille 
	if (noeud->fg_ == nullptr && noeud->fd_ == nullptr){
		this->supressfeuille(noeud, parent);
	}
	// Si le noeud n a qu un fils droit, on doit le remplacer par son fils
	else if(noeud->fg_ == nullptr){
		if (*parent->fg_->cle_== *noeud->cle_){ // On regarde si le noeud est le fils droit ou le fils gauche du parent
			parent->fg_ = noeud-> fd_; // la valeur qui point vers le fils gauche du parent va maintenant pointer vers le
			// fils droit du noeud que l'on veut supprimer
		}
		else {
			parent-> fd_ = noeud-> fd_;
		}	
		delete noeud; // On devrait pas faire delete *noeud ?? puisque noeud pointe vers un ABR
	}
	else if(noeud->fd_ == nullptr){ //meme chose si le noeud est un fils gauche
		if (*parent->fg_->cle_== *noeud->cle_){
			parent->fg_ = noeud-> fg_;
		}
		else {
			parent-> fd_ = noeud-> fg_;
		}	
		delete noeud;
	}
	// Lorsque le noeud possede des fils on cherche la valeur maximale des feuilles gauches et la valeur minimale des feuilles droites
	else {
		int Grand = noeud->fg_->max(); // *noeud->fg_->max() ??
		int Petit = noeud->fd_->min();

		if (*noeud->cle_ - Grand > Petit-*noeud->cle_){ //compare quel feuille est plus proche de la valeur du noeud 
			//On echange cette feuille avec le noeud
			ABR* replace = this->recherche(Petit);
			ABR* parentreplace = this->rechercheparent(Petit);
			replace->fg_= noeud->fg_;
			replace ->fd_=noeud->fd_;

			// 
			if (*parent->fg_->cle_== *noeud->cle_){
				parent->fg_ = replace; //On remplace le fils chez le parent
			}
			else {
				parent-> fd_ = replace;
			}
			// on supprime le pointeur fils gauche du parent de la feuille qui a relplace le noeud
			parentreplace->fg_=nullptr
			//noeud->fg_=nullptr;
			//noeud->fd_=nullptr;
			delete *noeud
			//this->supressfeuille(noeud,parentreplace);        //le noeud n a plus de parents
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
			parentreplace->fd_=nullptr
			//noeud->fg_=nullptr;
			//noeud->fd_=nullptr;
			delete *noeud
			//noeud->fg_=nullptr;
			//noeud->fd_=nullptr;
			//this->supressfeuille(noeud,parentreplace);
		}
	}
}


// Cette fonction permet de supprimer une feuille en changeant son parents
void ABR::supressfeuille(ABR* feuille, ABR* parent){
	if (*parent-> fg_->cle_ == *feuille->cle_){ // on cherche si cest un fils droit ou un fils gauche
		parent->fg_ = nullptr;
	}
	else {
		parent ->fd_ = nullptr;
	}
	delete feuille; //*feuille ??
}
