/************************************
 *          Les Fonctions           *
 *          Projet d'AP3            *
 *                                  *
 * fait par : Elliot This           *
 *         et Rémi Le Brech         *
 *                                  *
 * Crée le 28 septembre 2016        *
 ************************************/
#include "lib_fst.h"
#include "sdlglutils.h"

/*Protocol sdl3d
  protocol qui initialise opengl et sdl
  x et y sont la taille de la fenetre
  c est le fovy, le cham de vision */
void sdl3d(int x, int y, int c){
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_SetVideoMode(x, y, 32, SDL_OPENGL);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(c,(double)x/y,1,1500);
    glEnable(GL_DEPTH_TEST);
}



/*Fonction Camera
  Fonctions qui initalise la camera
  x, y et z sont les coordonné de la camera
  e1, e2 et e3 sont les coordonné du point qui fixe la camera */
void camera(double x, double y, double z, double e1, double e2, double e3){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(x,y,z,e1,e2,e3,0,0,1);
}



/*Fonction qui dessine les cubes sur une meme matrice
  taille est la taille des cube
  x, y et z la postion par rapport a la matrice
  a, b et c l'angle du cube sur la matrice */
//GLuint texture1;

void cube(double taille,double x,double y,double z,double a,double b,double c){


    glTranslated(x,y,z);
    glRotated(a,b,c,1);

    glBegin(GL_QUADS);
    //1 gauche
    glTexCoord2d(0,1);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,taille,taille);
   //2 haut
    glTexCoord2d(0,1);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,taille);
   //3 droite
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(0,1);
    glVertex3d(-taille,-taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(-taille,-taille,-taille);
    //4 sol
    glTexCoord2d(0,1);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,-taille);
    //5 deriere
    glTexCoord2d(0,1);
    glVertex3d(-taille,taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,-taille,-taille);
    glTexCoord2d(0,0);
    glVertex3d(-taille,taille,-taille);
    //6 devant
    glTexCoord2d(0,1);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glEnd();
}

void cubeennemis(double taille,double x,double y,double z,double a,double b,double c){


    glTranslated(x,y,z);
    glRotated(a,b,c,1);

    glBegin(GL_QUADS);
    //1 gauche
    glTexCoord2d(0,1);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(0.5,0);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(0.5,1);
    glVertex3d(-taille,taille,taille);
   //2 haut
    glTexCoord2d(0.5,1);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(0.5,0);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,taille);
   //3 droite
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(0.5,1);
    glVertex3d(-taille,-taille,taille);
    glTexCoord2d(0.5,0);
    glVertex3d(-taille,-taille,-taille);
    //4 sol
    glTexCoord2d(0.5,1);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(0.5,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,-taille);
    //5 deriere
    glTexCoord2d(0.5,1);
    glVertex3d(-taille,taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,-taille,-taille);
    glTexCoord2d(0.5,0);
    glVertex3d(-taille,taille,-taille);
    //6 devant
    glTexCoord2d(0.5,1);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(0.5,0);
    glVertex3d(taille,taille,-taille);
    glEnd();
}

void cubeennemis_position(int taille, double x, double y, double z,double a, double b, double c){
        glPushMatrix();
        cubeennemis(taille,x,y,z,a,b,c);
        glPopMatrix();
}

void sphere(int x, int y , int z) {
  static double a = 1;
  a = a + 1.5;
  glTranslated(x,y,z);
  glRotated(a,0,0,1);
  GLUquadricObj* pQuadric = gluNewQuadric();
  glTexCoord2d(0,1);
  //glColor3f(255,255,0);
  glScalef(0.25, 1.0, 1.0);
  gluQuadricTexture( pQuadric, GL_TRUE);
  gluSphere(pQuadric,25,64,16);
}

void sphere_position(int x,int y , int z){
  glPushMatrix();
  sphere(x,y,z);
  glPopMatrix();
}

void plat(double taille,double x,double y,double z,double a,double b,double c){
    glTranslated(x,y,z);
    glRotated(a,b,c,1);
    glBegin(GL_QUADS);
    glTexCoord2d(0,8);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(8,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(8,8);
    glVertex3d(-taille,-taille,-taille);
    glEnd();
}

void plat_pos(double taille,double x,double y,double z,double a,double b,double c){
        glPushMatrix();
        plat(taille,x,y,z,a,b,c);
        glPopMatrix();
}

void plafond(double taille,double x,double y,double z,double a,double b,double c){
    glTranslated(x,y,z);
    glRotated(a,b,c,1);
    glBegin(GL_QUADS);
    glTexCoord2d(0,1);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,-taille);
    glEnd();
}

void plaf_pos(double taille,double x,double y,double z,double a,double b,double c){
        glPushMatrix();
        plafond(taille,x,y,z,a,b,c);
        glPopMatrix();
}

/*Fonction qui dessine les cubes sur un repere
  taille est la taille des cube
  x, y et z la postion
  a, b et c l'angle des cubes */
void cube_position(int taille, double x, double y, double z,double a, double b, double c){
        glPushMatrix();
        cube(taille,x,y,z,a,b,c);
        glPopMatrix();
}

double direction(double a){
    while (a>360)
      a-= 360;

    while (a<0)
      a+= 360;
    return a;
}

void interface(){
    glEnable(GL_TEXTURE_2D);
    glMatrixMode (GL_PROJECTION);
    glPushMatrix ();
    glLoadIdentity ();
    glOrtho (0,800,0,600, -1.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex2d(0,0 );
    glTexCoord2d(1, 0); glVertex2d(800,0);
    glTexCoord2d(1, 1); glVertex2d(800,600);
    glTexCoord2d(0, 1); glVertex2d(0,600);
    glEnd();

    //End 2D
    glMatrixMode (GL_PROJECTION);
    glPopMatrix ();
    glMatrixMode (GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

}

void interface0(){
    glEnable(GL_TEXTURE_2D);
    glMatrixMode (GL_PROJECTION);
    glPushMatrix ();
    glLoadIdentity ();
    glOrtho (0,800,0,600, -1.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex2d(438,471);
    glTexCoord2d(0, 1); glVertex2d(438,534);
    glTexCoord2d(1, 1); glVertex2d(475,534);
    glTexCoord2d(1, 0); glVertex2d(475,471);
    glEnd();

    //End 2D
    glMatrixMode (GL_PROJECTION);
    glPopMatrix ();
    glMatrixMode (GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

}

void interface10(){
    glEnable(GL_TEXTURE_2D);
    glMatrixMode (GL_PROJECTION);
    glPushMatrix ();
    glLoadIdentity ();
    glOrtho (0,800,0,600, -1.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex2d(438-50,471);
    glTexCoord2d(0, 1); glVertex2d(438-50,534);
    glTexCoord2d(1, 1); glVertex2d(475-50,534);
    glTexCoord2d(1, 0); glVertex2d(475-50,471);
    glEnd();

    //End 2D
    glMatrixMode (GL_PROJECTION);
    glPopMatrix ();
    glMatrixMode (GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

}

void interface100(){
    glEnable(GL_TEXTURE_2D);
    glMatrixMode (GL_PROJECTION);
    glPushMatrix ();
    glLoadIdentity ();
    glOrtho (0,800,0,600, -1.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex2d(438-100,471);
    glTexCoord2d(0, 1); glVertex2d(438-100,534);
    glTexCoord2d(1, 1); glVertex2d(475-100,534);
    glTexCoord2d(1, 0); glVertex2d(475-100,471);
    glEnd();

    //End 2D
    glMatrixMode (GL_PROJECTION);
    glPopMatrix ();
    glMatrixMode (GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

}

int choixscore(int scored, int *centaine){
    int res = 0;
        switch ((scored-100* *centaine)/10) {
            case 1 :
                res = 1 ;
                break;
            case 2 :
                res = 2 ;
                break;
            case 3 :
                res = 3 ;
                break;
            case 4 :
                res = 4 ;
                break;
            case 5 :
                res = 5 ;
                break;
            case 6 :
                res = 6 ;
                break;
            case 7 :
                res = 7 ;
                break;
            case 8 :
                res = 8 ;
                break;
            case 9 :
                res = 9 ;
                break;
            case 10 :
                *centaine = *centaine + 1 ;
                res = 0 ;
                break;
        }
    return res;
}

void tri(int n, int *tab){
  int a,i,j;
  for(i=0; i<(n-1); i++){
    for(j=i+1; j<(n); j++){
      if(tab[i]<tab[j]){
        a = tab[i];
        tab[i] = tab[j];
        tab[j] = a;
      }
    }
  }
}
