
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
bool vide();
void insertion(int a, ABR racine);
ABR recherche(int nb, ABR racine);  
};
