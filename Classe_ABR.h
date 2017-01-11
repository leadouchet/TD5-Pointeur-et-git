
class ABR {
protected :
  int* cle_;
  ABR* fg_;
  ABR* fd_;

public:

  // Constructors
  ABR();

  //destructors
  
  ~ABR();
  //methodes
void supress(int a);
void supressfeuille(ABR* feuille, ABR* parent)

bool vide();
  
ABR* recherche(int nb, ABR racine);  
ABR* rechercheparent(int nb);
void insertion(int a);
ABR* recherche(int nb);
void parcours();  
void min();
void max();

};
