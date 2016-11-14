/************************************
 *          Les Fonctions           *
 *          Projet d'AP3            *
 *                                  *
 * fait par : Elliot This           *
 *         et Rémi Le Brech         *
 *                                  *
 * Crée le 28 septembre 2016        *
 ************************************/

/*Protocol sdl3d
  protocol qui initialise opengl et sdl
  x et y sont la taille de la fenetre
  c est le fovy, le cham de vision */
void sdl3d(int x, int y, int c);


/*Fonction Camera
  Fonctions qui initalise la camera
  x, y et z sont les coordonné de la camera
  e1, e2 et e3 sont les coordonné du point qui fixe la camera */
void camera(double x, double y, double z, double e1, double e2, double e3);



/*Fonction qui dessine les cubes sur une meme matrice
  taille est la taille des cube
  x, y et z la postion par rapport a la matrice
  a, b et c l'angle du cube sur la matrice */
void cube(int taille, double x, double y, double z,double a, double b, double c);

void sphere(int x, int y , int z, int a, int b, int c);


void sphere_position(int x,int y , int z, int a, int b, int c);


/*Fonction qui dessine les cubes sur un repere
  taille est la taille des cube
  x, y et z la postion
  a, b et c l'angle des cubes */
void cube_position(int taille, double x, double y, double z,double a, double b, double c);


double direction(double a);
