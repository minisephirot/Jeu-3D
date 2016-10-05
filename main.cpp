#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "lib_sdl_fst.h"


int main(int argc, char *argv[])
{
/*  *****************
    * Les Variables *
    *****************  */

    int x = 19;
    int y = 19;
    double a = 0;
    double b = 0;

// initialisation
    SDL_Event event;
    sdl3d(800,600, 100);
    SDL_WM_SetCaption("Base 3D", NULL);
    int exit=1;



    SDL_EnableKeyRepeat(10, 10); //Permet la répétition des entrées de clavier toute les 10ms
    while(exit) 
    {
        if(SDL_PollEvent(&event)){
         switch(event.key.keysym.sym){
            // Fin du jeu : echap ou fermé
            case SDL_QUIT:
                exit = 0;
            break;
            case SDLK_ESCAPE: 
                exit = 0;
                break;
            //Déplcement de la caméra sur l'axe x et y
            case SDLK_z: 
                x=x+2;
                break;
            case SDLK_s: 
                x=x-2;
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
                printf ("%f   ", b);
                break;
            case SDLK_RIGHT: 
                b=b+0.1;
                break;
            default:
                break;
         }
        }
    // La variable b n'a pas besoin d'etre plus grand que 2PI
    if (b>2*3.14)
      b = 0;
    if (b<-2*3.14)
      b=0;

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
        camera(x,y,20,x-cos(b)*20,y+sin(b)*20,20);

        // creation du plateau
        int i=0;
        while(i<=15){
            cube_position(18,15*38,i*38,0,0,0,0);
            cube_position(18,i*38,15*38,0,0,0,0);
            cube_position(18,i*38,0,0,0,0,0);
            cube_position(18,0,i*38,0,0,0,0);
            i++;
        }

        glFlush();
        SDL_GL_SwapBuffers();

    }

    return 0;
}
