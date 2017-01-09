
class ABR {
protected :
  int valeur_;
  int* cle_;
  ABR* fg_;
  ABR* fd_;

public:
  // Getters
  int* cle();
  ABR* fg();
  ABR* fd();

  // Setters
  void set_cle(int a);

  // Constructors
  ABR();
  ABR(int a);
  ABR(const ABR& model);

  //destructors


  //methodes
bool validation();
  
ABR recherche(int nb, ABR racine);  
};
