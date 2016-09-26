#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "lib_sdl_fst.h"
// Récupère les libraires OpenGL/SDL

int main(int argc, char *argv[])
{
    SDL_Event event;
    sdl3d(600,600, 100);
    SDL_WM_SetCaption("Base 3D", NULL);
    int exit=1;

    while(exit) //Permet de gérer les inputs de l'utilisateurs
    {
        SDL_WaitEvent(&event);

        switch(event.key.keysym.sym)
        {
            case SDLK_ESCAPE: //On appuie sur echap, on sort de la boucle et quitte le jeu
                exit = 0;
                break;
            case SDLK_z:
                camera(3,4,3,0,0,0);
                break;
            default:
                break;
        }
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        camera(3,4,3,0,0,0);

        glPushMatrix();
        cube(1,0,0,0,50,0,0);
        cube(1,-3,-3,0,0,0,0);
        glPopMatrix();

        glPushMatrix();
        cube(1,-3,-3,0,0,0,0);
        glPopMatrix();


        glFlush();
        SDL_GL_SwapBuffers();

    }

    return 0;
}



