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

void sphere(int x, int y , int z, int a, int b, int c) {
  glTranslated(x,y,z);
  glRotated(a,b,c,1);
  GLUquadricObj* pQuadric = gluNewQuadric();
  glTexCoord2d(0,1);
  //glColor3f(255,255,0);
  glScalef(0.25, 1.0, 1.0);
  gluQuadricTexture( pQuadric, GL_TRUE);
  gluSphere(pQuadric,25,64,16);
}

void sphere_position(int x,int y , int z, int a, int b, int c){
  glPushMatrix();
  sphere(x,y,z,a,b,c);
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
