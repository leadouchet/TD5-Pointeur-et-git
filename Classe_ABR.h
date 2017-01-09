
class ABR {
protected :
  int* cle_;
  ABR* fg_;
  ABR* fd_;

public:
  // Getters
  int* cle();
  ABR* fg();
  ABR* fd();

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
