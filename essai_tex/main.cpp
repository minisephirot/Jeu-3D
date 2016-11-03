#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "sdlglutils.h"

    GLuint texture1;

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
void cube(double taille,double x,double y,double z,double a,double b,double c){

glEnable(GL_TEXTURE_2D);
texture1 = loadTexture("stainedglass05.jpg");
glBindTexture(GL_TEXTURE_2D, texture1);
    
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

void cube_position(double taille,double x,double y,double z,double a,double b,double c){
        glPushMatrix();
        cube(taille,x,y,z,a,b,c);
        glPopMatrix();
}


//-------------------------------------------------------------------------------------------------
//----------------------------------------Debut Du Main--------------------------------------------
//-------------------------------------------------------------------------------------------------
int main(){
   
    //-------------Initialisation openGl--------------
    //------------------------------------------------
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(100,(double)640/480,1,1500);
    glEnable(GL_DEPTH_TEST);




    int continuer = 1 ;
    bool w=false;
    bool s=false;
    bool a=false;
    bool d=false;
    double x, y;
  //----------------Debut de boucle-----------------
  //------------------------------------------------
  while(continuer){
  
    //--------------Evenement-----------------------
      SDL_PumpEvents();
      Uint8 *keystates = SDL_GetKeyState(NULL);
      bool esc = false; 
      esc = keystates[SDLK_ESCAPE];
      SDL_Event event;
      SDL_PollEvent(&event);
      if ((esc) || (event.type == SDL_QUIT)){
          continuer=0;
       }
       w = keystates[SDLK_z];
       s = keystates[SDLK_s];
       a = keystates[SDLK_q];
       d = keystates[SDLK_d];

       if (w){
           x += 1;
       }
       if (s){
           x -= 1;
       }
       if (a){
           y += 1;
       }
       if (d){
           y -= 1;
       }
      
    //-------------Camera+Cube------------------------
      camera(x,y,0,y,x+3,0);
      cube_position(3,0,0,0,0,0,0);

    glFlush();
    SDL_GL_SwapBuffers();
  }


}

