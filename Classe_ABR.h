
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
void insertion(int a);
ABR* recherche(int nb);  
void min();
void max();
};
