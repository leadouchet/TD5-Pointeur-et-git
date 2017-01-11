
class ABR {
protected :
  int* cle_;
  ABR* fg_;
  ABR* fd_;

public:

  // Constructors
  ABR();

  //destructors
  void supress(int a);

  //methodes

bool vide();
  
ABR recherche(int nb, ABR racine);  
};
