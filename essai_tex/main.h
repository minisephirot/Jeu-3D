#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "sdlglutils.h"

GLuint texture1;

void cube(double taille,double x,double y,double z,double a,double b,double c){


    glTranslated(x,y,z);
    glRotated(a,b,c,1);
    
    glBegin(GL_QUADS);
    glTexCoord2d(0,1);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,taille,taille);
   //2
    glTexCoord2d(0,1);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,taille);
   //3
    glTexCoord2d(0,1);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,-taille,taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,-taille);
    //4
    glTexCoord2d(0,1);
    glVertex3d(-taille,taille,-taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,taille,-taille);
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,-taille,-taille);
    //5
    glTexCoord2d(0,1);
    glVertex3d(-taille,taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(-taille,-taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(-taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(-taille,taille,-taille);
    //6
    glTexCoord2d(0,1);
    glVertex3d(taille,taille,taille);
    glTexCoord2d(0,0);
    glVertex3d(taille,-taille,taille);
    glTexCoord2d(1,0);
    glVertex3d(taille,-taille,-taille);
    glTexCoord2d(1,1);
    glVertex3d(taille,taille,-taille);
    glEnd();
}


//----------------------------------------Gestion Camera-------------------------------------------
//-------------------------------------------------------------------------------------------------
void camera(double x, double y, double z, double e1, double e2, double e3){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(x,y,z,e1,e2,e3,0,0,1);
}

//---------------------------------------Fonction Cube---------------------------------------------
//-------------------------------------------------------------------------------------------------
void cube_position(double taille,double x,double y,double z,double a,double b,double c){
        glPushMatrix();
        cube(taille,x,y,z,a,b,c);
        glPopMatrix();
}
