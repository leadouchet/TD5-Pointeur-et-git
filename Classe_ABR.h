
class ABR {
protected :
  int* cle_;
  int** fg_;
  int** fd_;

public:
  // Getters
  int* cle();
  int** fg();
  int** fd();

  // Setters
  void set_cle()

  // Constructors
  ABR();
  ABR(int cle);
  ABR(const ABR& model);

  //destructors


  //methodes
bool validation();
  
ABR recherche(int nb);  
