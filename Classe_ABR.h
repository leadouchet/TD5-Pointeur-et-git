
class ABR {
protected :
  int* cle_;
  ABR* fg_;
  ABR* fd_;

public:

  // Constructors
  ABR();

  //destructors


  //methodes
void supress(int a);
void supressfeuille(ABR* feuille, ABR* parent)

bool vide();
  
ABR* recherche(int nb, ABR racine);  
ABR* rechercheparent(int nb)
};
