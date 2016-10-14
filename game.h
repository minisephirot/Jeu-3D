#include "constante.h"

int gameStart(){
/*  *****************
    * Les Variables *
    *****************  */

    // variable annoncant la fin de jeu
    int exit, choix;

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
    bool azerty = false;

/*  *****************
    *     Debut     *
    *****************  */


    //---------Initialisation des variables---------
     exit=1;
     choix = 1;
     x = TAILLE_CUBES*2;
     y = TAILLE_CUBES*2;
     b = 0;

      //---------Génération des Ennemis---------
      //****************************************

        //---------Enemis 1---------
          Ennemis cube1;
          cube1.x = TAILLE_PLATEAU*(TAILLE_CUBES)-(4*TAILLE_CUBES)+40;
          cube1.y = TAILLE_PLATEAU*(TAILLE_CUBES)-(5*TAILLE_CUBES);
          cube1.b = 45;
/*
        //---------Enemis 2---------
          Ennemis cube2;
          cube2.x = (TAILLE_PLATEAU*(TAILLE_CUBES))/2;
          cube2.y = (TAILLE_PLATEAU*(TAILLE_CUBES))/2;
          cube2.sens= 1;
        //---------Enemis 3---------
          Ennemis cube3;
          cube3.x = TAILLE_PLATEAU*(TAILLE_CUBES)-(4*TAILLE_CUBES);
          cube3.y = 5*(TAILLE_CUBES);
          cube3.sens= 1;
*/
      //---------Fin de la génération---------
      //**************************************

    //---------initialisation de la fenetre---------
    sdl3d(800,600, 100);
    SDL_WM_SetCaption("Base 3D", NULL);

    SDL_EnableKeyRepeat(10, 10); //Permet la répétition des entrées de clavier toute les 10ms

    freopen("CON", "w", stdout); // redirects stdout
    freopen("CON", "w", stderr); // redirects stderr

    /************************
     *     Debut du jeu     *
     ************************/

    while(exit)
    {
        //---------Début Des Events---------
            SDL_PumpEvents();
            dx = cos(b*M_PI/180)*VITESSE_DEPLACEMENT;
            dy = sin(b*M_PI/180)*VITESSE_DEPLACEMENT;
            cube1.dx = cos(cube1.b*M_PI/180)*VITESSE_DEPLACEMENT;
            cube1.dy = sin(cube1.b*M_PI/180)*VITESSE_DEPLACEMENT;

            Uint8 *keystates = SDL_GetKeyState(NULL);

            if(!azerty){
              w = keystates[SDLK_w];
              s = keystates[SDLK_s];
              a = keystates[SDLK_a];
              d = keystates[SDLK_d];
            }
            else
            {
              w = keystates[SDLK_z];
              s = keystates[SDLK_s];
              a = keystates[SDLK_q];
              d = keystates[SDLK_d];
}
            esc = keystates[SDLK_ESCAPE];
            fgauche = keystates[SDLK_LEFT];
            fdroite = keystates[SDLK_RIGHT];


            // Fin du jeu : echap ou fermé
            SDL_Event event;
            SDL_PollEvent(&event);
            if ((esc) || (event.type == SDL_QUIT)){
              exit=0;
              choix = 0;
            }

            //choix clavié
            if (event.key.keysym.sym == SDLK_F1)
            {
               if (azerty == true)
               azerty = false;

            }
            if (event.key.keysym.sym == SDLK_F2)
            {
              if (azerty == false)
              azerty = true;
}

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
      //---------Gestion des Collisions aux Ennemis---------
        if (x >= ((cube1.x)-TAILLE_CUBES/2) &&
            x <= ((cube1.x)+TAILLE_CUBES/2) &&
            y >= ((cube1.y)-TAILLE_CUBES/2) &&
            y <= ((cube1.y)+TAILLE_CUBES/2))
            {
                exit=0;
            }

      //---------Fin de la gestion des collisions---------


      // La variable b n'a pas besoin d'etre plus grand que 360
      b = direction(b);
      //---------Fin des Events---------

      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      camera(x,y,20,x+dx,y+dy,20); //explication en annexe


      //---------Géstion des Ennemis---------
      //****************************************

        //---------Enemis 1---------
          cube1.x+=cube1.dx;
          cube1.y+=cube1.dy;
          //---gestion mouvement---
          if (((cube1.x)+TAILLE_CUBES/2) >= (((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES/2)-2))
          {
             cube1.b += 180+b;
             printf("b = %f\n",cube1.b);
          }
          if (((cube1.x)-TAILLE_CUBES/2) <= ((TAILLE_CUBES/2)+2))
          {
             cube1.b += 180+b;
             printf("b = %f\n",cube1.b);
          }

          if (((cube1.y)-TAILLE_CUBES/2) <= ((TAILLE_CUBES/2)+2))
          {
             cube1.b += 180+b;
             printf("b = %f\n",cube1.b);
          }
          if(((cube1.y)+TAILLE_CUBES/2) >= (((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES/2)-2))
          {
             cube1.b += 180+b;
             printf("b = %f\n",cube1.b);
          }
          //---fin gestion---

          cube1.b = direction(cube1.b);

          cube_position(TAILLE_CUBES/2,cube1.x,cube1.y,0,90,0,0);


      //---------Fin de géstion---------
      //**************************************


      //---------Debut Du Plateau---------
        //cube en fond
      cube_position(TAILLE_PLATEAU*TAILLE_CUBES/2,TAILLE_PLATEAU*TAILLE_CUBES/2,TAILLE_PLATEAU*TAILLE_CUBES/2,(TAILLE_PLATEAU*TAILLE_CUBES-TAILLE_CUBES)/2,0,0,0);
      int i=0;
      while(i<=TAILLE_PLATEAU){
        cube_position(TAILLE_CUBES/2,TAILLE_PLATEAU*(TAILLE_CUBES),i*(TAILLE_CUBES),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),TAILLE_PLATEAU*(TAILLE_CUBES),0,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),0,0,0,0,0);
        cube_position(TAILLE_CUBES/2,0,i*(TAILLE_CUBES),0,0,0,0);
        cube_position(TAILLE_CUBES/2,TAILLE_PLATEAU*(TAILLE_CUBES),i*(TAILLE_CUBES),22,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),TAILLE_PLATEAU*(TAILLE_CUBES),22,0,0,0);
        cube_position(TAILLE_CUBES/2,i*(TAILLE_CUBES),0,22,0,0,0);
        cube_position(TAILLE_CUBES/2,0,i*(TAILLE_CUBES),22,0,0,0);
        i++;
      }
      //---------Fin Du Plateau---------

      glFlush();
      SDL_GL_SwapBuffers();


    }
    /************************
     *      Fin du jeu      *
     ************************/

  return choix;

/****************
 *     Fin      *
 ****************/
}
