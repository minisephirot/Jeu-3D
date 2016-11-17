// Les define :
#define TAILLE_PLATEAU 20
#define TAILLE_CUBES 44
#define VITESSE_DEPLACEMENT 4
#define VITESSE_ORIENTATION 4

#ifndef CLASS
#define CLASS
class Ennemis
{
  public :

  double x;
  double y;
  int vitesse;
  double dx;
  double dy;
  double direc;
};

class Bonus
{
  public :

  double x;
  double y;
  double z;

};
#endif // CLASS

int gameStart();
