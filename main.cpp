/************************************
 *           NOM DU JEU             *
 *          Projet d'AP3            *
 *                                  *
 * fait par : Elliot This           *
 *         et Rémi Le Brech         *
 *                                  *
 * Crée le 28 septembre 2016        *
 ************************************/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "lib_sdl_fst.h"

// Les define :
#define TAILLE_X_PLATEAU 15 
#define TAILLE_CUBES 38


int main(int argc, char *argv[])
{
/*  *****************
    * Les Variables *
    *****************  */
    
    // variable annoncant la fin de jeu
    int exit; 
    
    //Position de la camera
    int x, y;
 
    //oriantation de la camera
    double b;


/*  *****************
    *     Debut     *
    *****************  */


    //---------Initialisation des variables---------
     exit=1;
     x = 39;
     y = 39;
     b = 2;

    //---------initialisation de la fenetre---------
    SDL_Event event;
    sdl3d(800,600, 100);
    SDL_WM_SetCaption("Base 3D", NULL);
    



    SDL_EnableKeyRepeat(10, 10); //Permet la répétition des entrées de clavier toute les 10ms

    /************************
     *     Debut du jeu     *
     ************************/
    while(exit) 
    {

        //---------Début Des Events---------
        if(SDL_PollEvent(&event)){
         switch(event.key.keysym.sym){
            // Fin du jeu : echap ou fermé
            case SDLK_ESCAPE: 
                exit = 0;
                break;

            //Déplcement de la caméra sur l'axe x et y
            case SDLK_z: 
                x-=2*cos(b);
                y+=2*sin(b);
                break;
            case SDLK_s: 
                x+=2*cos(b);
                y-=2*sin(b);
                break;
            case SDLK_q: 
                y=y+2;
                break;
            case SDLK_d: 
                y=y-2;
                break;

            //orientation de la caméra sur l'axe x et y
            case SDLK_LEFT:
                b=b-0.1;          
                break;
            case SDLK_RIGHT: 
                b=b+0.1;
                break;
            default:
                break;
        }
      }
      //---------Fin des Events---------


      // La variable b n'a pas besoin d'etre plus grand que 2PI
      if (b>2*3.14)
        b = 0;
      if (b<-2*3.14)
        b=0;
  
      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );    
      camera(x,y,20,x-cos(b)*20,y+sin(b)*20,20);
  

      //---------Debut Du Plateau---------
      int i=0;
      while(i<=TAILLE_X_PLATEAU){
        cube_position(TAILLE_CUBES/2,TAILLE_X_PLATEAU*(TAILLE_CUBES+2),i*(TAILLE_CUBES+2),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES+2),TAILLE_X_PLATEAU*(TAILLE_CUBES+2),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES+2),0,0,0,0,0);
        cube_position(TAILLE_CUBES/2,0,i*(TAILLE_CUBES+2),0,0,0,0);
        i++;
      }
      //---------Fin Du Plateau---------


      glFlush();
      SDL_GL_SwapBuffers();


    }
    /************************
     *      Fin du jeu      *
     ************************/

  return 0;

/****************
 *     Fin      *
 ****************/
}



