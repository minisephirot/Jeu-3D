#include "ennemis.h"

int gameStart(){

/*  *****************
    * Les Variables *
    *****************  */

    // variable annoncant la fin de jeu
    int exit, choix;
    int i;
    int Lasttime = 0, Time = 0, Lasttime2 = 0, Time2 = 0;
    int scorejoueur = 0;

    //Position de la camera
    double x, y;
    double dx, dy;
    //direction
    double direc;

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
     direc = 0;

      //---------Génération des Ennemis et du bonus---------
      //****************************************

	const int ncubes = 3;
	const int nbonus = 1;
          Ennemis cubes[ncubes];
          Bonus scoring[nbonus];

        //---------Enemis 1---------
//          Ennemis cube1;
          cubes[0].x = TAILLE_PLATEAU*(TAILLE_CUBES)-(4*TAILLE_CUBES)+40;
          cubes[0].y = TAILLE_PLATEAU*(TAILLE_CUBES)-(5*TAILLE_CUBES);
          cubes[0].direc = 65;

        //---------Enemis 2---------
//          Ennemis cube2;
          cubes[1].x = (TAILLE_PLATEAU*(TAILLE_CUBES))/2;
          cubes[1].y = (TAILLE_PLATEAU*(TAILLE_CUBES))/2;
          cubes[1].direc = 37;
        //---------Enemis 3---------
//          Ennemis cube3;
          cubes[2].x = TAILLE_PLATEAU*(TAILLE_CUBES)-(4*TAILLE_CUBES);
          cubes[2].y = 5*(TAILLE_CUBES);
          cubes[2].direc = -45;
        //---------Bonus-----------
          scoring[0].x = ((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES)/2;
          scoring[0].y = ((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES)/2;
          scoring[0].z = 9;

      //---------Fin de la génération---------
      //**************************************

    //---------initialisation de la fenetre---------
    sdl3d(800,600, 100);
    SDL_WM_SetCaption("Base 3D", NULL);

    SDL_EnableKeyRepeat(10, 10); //Permet la répétition des entrées de clavier toute les 10ms



    /************************
     *     Debut du jeu     *
     ************************/

for (i=0; i<ncubes; i++) {
            cubes[i].dx = cos(cubes[i].direc*M_PI/180)*VITESSE_DEPLACEMENT;
            cubes[i].dy = sin(cubes[i].direc*M_PI/180)*VITESSE_DEPLACEMENT;
}

    while(exit)
    {
    //-------Actualisation tout les  10ms---
      Time = SDL_GetTicks();
      if (Time - Lasttime > 10) {

      printf("%d %f %f %f" "\n",scorejoueur ,x ,y, scoring[0].z);
      Lasttime = Time;
        //---------Début Des Events---------
            SDL_PumpEvents();
            dx = cos(direc*M_PI/180)*VITESSE_DEPLACEMENT;
            dy = sin(direc*M_PI/180)*VITESSE_DEPLACEMENT;

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
              direc=direc+VITESSE_ORIENTATION;
            }
            if (fdroite){
              direc=direc-VITESSE_ORIENTATION;
            }
      //---------Gestion des collisions---------
        if (x <= ((TAILLE_CUBES/2)+2)){
          x = x + TAILLE_CUBES/7;
        }
        if (x >= (((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES/2)-2)){
          x = x - TAILLE_CUBES/7;
        }
        if (y >= (((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES/2)-2)){
          y = y - TAILLE_CUBES/7;
        }
        if (y <= ((TAILLE_CUBES/2)+2)){
          y = y + TAILLE_CUBES/7;
        }

      //---------Gestion des Collisions aux Ennemis---------
        for (i=0; i<ncubes; i++){
          if (x >= (((cubes[i].x)-TAILLE_CUBES/2)-7) &&
            x <= (((cubes[i].x)+TAILLE_CUBES/2)+7) &&
            y >= (((cubes[i].y)-TAILLE_CUBES/2)-7) &&
            y <= (((cubes[i].y)+TAILLE_CUBES/2)+7))
            {
                //exit=0;
                //choix= gameover();
            }
        }
        for (int i=0; i<=nbonus; i++) {
            if (x >= (((scoring[i].x)-25/2)-7) &&
            x <= (((scoring[i].x)+25/2)+7) &&
            y >= (((scoring[i].y)-25)-7) &&
            y <= (((scoring[i].y)+25)+7))
            {
                Time2 = SDL_GetTicks();
                if (Time2 - Lasttime2 > 1000) {
                    scorejoueur = (scorejoueur+10);
                    Lasttime2 = Time2;
                    scoring[i].x= rand() % ((TAILLE_CUBES*TAILLE_PLATEAU)-80) + (TAILLE_PLATEAU+6);
                    scoring[i].y= rand() % ((TAILLE_CUBES*TAILLE_PLATEAU)-80) + (TAILLE_PLATEAU+6);
                }
            }
        }

      //---------Fin de la gestion des collisions---------


      // La variable b n'a pas besoin d'etre plus grand que 360
      direc = direction(direc);
      //---------Fin des Events---------

      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      camera(x,y,20,x+dx,y+dy,20); //explication en annexe

      deplcementEnnemis(cubes, ncubes);
      generationbonus(scoring, nbonus);

      //---------Debut Du Plateau---------
        //cube en fond
      cube_position(TAILLE_PLATEAU*TAILLE_CUBES/2,TAILLE_PLATEAU*TAILLE_CUBES/2,TAILLE_PLATEAU*TAILLE_CUBES/2, (TAILLE_PLATEAU*TAILLE_CUBES-TAILLE_CUBES)/2,0,0,0);
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
    }
    /************************
     *      Fin du jeu      *
     ************************/

  return choix;

/****************
 *     Fin      *
 ****************/
}
