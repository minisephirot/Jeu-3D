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
#include "class.h"

// Les define :
#define TAILLE_PLATEAU 20
#define TAILLE_CUBES 44
#define VITESSE_DEPLACEMENT 3
#define VITESSE_ORIENTATION 3

void gameStart(){
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
     x = TAILLE_CUBES*2;
     y = TAILLE_CUBES*2;
     b = 0;

    //---------initialisation de la fenetre---------
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
            SDL_Event croix;
            SDL_PollEvent(&croix);
            if ((esc) || (croix.type == SDL_QUIT)){
              exit=0;
            }
            printf("%d %d %d %d %d %d %f %f %f %f \n", w, a, s, d, fgauche, fdroite, x, y, dx, dy);
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
      //---------Gestion des collisions---------
        if (x <= ((TAILLE_CUBES/2)+2)){
          x = x + TAILLE_CUBES/8;
        }
        if (x >= (((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES/2)-2)){
          x = x - TAILLE_CUBES/8;
        }
        if (y >= (((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES/2)-2)){
          y = y - TAILLE_CUBES/8;
        }
        if (y <= ((TAILLE_CUBES/2)+2)){
          y = y + TAILLE_CUBES/8;
        }

      //---------Fin de la gestion des collisions---------


      // La variable b n'a pas besoin d'etre plus grand que 360
      if (b>360)
        b = 0;
      if (b<-1)
        b=359;

      //---------Fin des Events---------

      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      camera(x,y,20,x+dx,y+dy,20); //explication en annexe


      //---------Génération des Ennemis---------
      //****************************************

        //---------Enemis 1---------
          Ennemis cube1;
          cube1.x = TAILLE_PLATEAU*(TAILLE_CUBES)-(4*TAILLE_CUBES);
          cube1.y = TAILLE_PLATEAU*(TAILLE_CUBES)-(5*TAILLE_CUBES);
          cube_position(TAILLE_CUBES/2,cube1.x,cube1.y,0,0,0,0);

        //---------Enemis 2---------
          Ennemis cube2;
          cube2.x = (TAILLE_PLATEAU*(TAILLE_CUBES))/2;
          cube2.y = (TAILLE_PLATEAU*(TAILLE_CUBES))/2;
          cube_position(TAILLE_CUBES/2,cube2.x,cube2.y,0,0,0,0);

        //---------Enemis 3---------
          Ennemis cube3;
          cube3.x = TAILLE_PLATEAU*(TAILLE_CUBES)-(4*TAILLE_CUBES);
          cube3.y = 5*(TAILLE_CUBES);
          cube_position(TAILLE_CUBES/2,cube3.x,cube3.y,0,0,0,0);

      //---------Fin de la génération---------
      //**************************************


      //---------Debut Du Plateau---------
      int i=0;
      while(i<=TAILLE_PLATEAU){
        cube_position(TAILLE_CUBES/2,TAILLE_PLATEAU*(TAILLE_CUBES),i*(TAILLE_CUBES),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),TAILLE_PLATEAU*(TAILLE_CUBES),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),0,0,0,0,0);
        cube_position(TAILLE_CUBES/2,0,i*(TAILLE_CUBES),0,0,0,0);
        //SOL cube_position((TAILLE_PLATEAU*TAILLE_CUBES)/2,(TAILLE_PLATEAU*TAILLE_CUBES)/2,(TAILLE_PLATEAU*TAILLE_CUBES)/2,(((TAILLE_PLATEAU*TAILLE_CUBES)/2)-TAILLE_PLATEAU*TAILLE_CUBES-21),0,0,0);
        //SKYBOX cube_position((TAILLE_PLATEAU*TAILLE_CUBES)/2,(TAILLE_PLATEAU*TAILLE_CUBES)/2,(TAILLE_PLATEAU*TAILLE_CUBES)/2,(TAILLE_PLATEAU*TAILLE_CUBES)/2,0,0,0);
        i++;
      }
      //---------Fin Du Plateau---------


      glFlush();
      SDL_GL_SwapBuffers();


    }
    /************************
     *      Fin du jeu      *
     ************************/


/****************
 *     Fin      *
 ****************/
}
