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
#define TAILLE_PLATEAU 20
#define TAILLE_CUBES 45
#define VITESSE_DEPLACEMENT 0.75
#define VITESSE_ORIENTATION 0.75


int main(int argc, char *argv[])
{
/*  *****************
    * Les Variables *
    *****************  */

    // variable annoncant la fin de jeu
    int exit;

    //Position de la camera
    double x, y;
    double dx, dy;
    //direction
    double b;

    bool w=false;
    bool s=false;
    bool a=false;
    bool d=false;
    bool esc=false;
    bool fgauche=false;
    bool fdroite=false;

/*  *****************
    *     Debut     *
    *****************  */


    //---------Initialisation des variables---------
     exit=1;
     x = 39;
     y = 39;
     b = 0;

    //---------initialisation de la fenetre---------
    SDL_Event event;
    sdl3d(800,600, 100);
    SDL_WM_SetCaption("Base 3D", NULL);

    SDL_EnableKeyRepeat(10, 10); //Permet la répétition des entrées de clavier toute les 10ms

    /************************
     *     Debut du jeu     *
     ************************/
   freopen("CON", "w", stdout);
   freopen("CON", "w", stderr);

    while(exit)
    {
        //---------Début Des Events---------
        /*while (SDL_PollEvent(&event))*/{
            SDL_PumpEvents();
            dx = cos(b*M_PI/180)*VITESSE_DEPLACEMENT;
            dy = sin(b*M_PI/180)*VITESSE_DEPLACEMENT;

            Uint8 *keystates = SDL_GetKeyState(NULL);

            w = keystates[SDLK_w];
            s = keystates[SDLK_s];
            a = keystates[SDLK_a];
            d = keystates[SDLK_d];
            esc = keystates[SDLK_ESCAPE];
            fgauche = keystates[SDLK_LEFT];
            fdroite = keystates[SDLK_RIGHT];

            // Fin du jeu : echap ou fermé
            if (esc){
            exit=0;
            }
            printf("%d %d %d %d %d %d \n", w, a, s, d, fgauche, fdroite);
            //Déplcement de la caméra sur l'axe x et y
            if (w){
            x += dx;
            y += dy;
            }
            if (s){
            x -= dx;
            y -= dy;
            }
            if (a){
            x -= dy;
            y += dx;
            }
            if (d){
            x += dy;
            y -= dx;
            }
            if (fgauche){
            b=b+VITESSE_ORIENTATION;
            }
            if (fdroite){
            b=b-VITESSE_ORIENTATION;
            }
      }
      //---------Fin des Events---------


      // La variable b n'a pas besoin d'etre plus grand que 360
      if (b>360)
        b = 0;
      if (b<-1)
        b=359;

      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      camera(x,y,20,x+dx,y+dy,20); //explnication en annexe

      //---------Génération des cubes qui tuent---------
        cube_position(TAILLE_CUBES/2.5,7*(TAILLE_CUBES),7*(TAILLE_CUBES),3,1,2,3);


      //---------Fin de la génération---------

      //---------Debut Du Plateau---------
      int i=0;
      while(i<=TAILLE_PLATEAU){
        cube_position(TAILLE_CUBES/2,TAILLE_PLATEAU*(TAILLE_CUBES),i*(TAILLE_CUBES),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),TAILLE_PLATEAU*(TAILLE_CUBES),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),0,0,0,0,0);
        cube_position(TAILLE_CUBES/2,0,i*(TAILLE_CUBES),0,0,0,0);
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



