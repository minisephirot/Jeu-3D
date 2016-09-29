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

    int x = 54;
    int y = 54;
    double a = 0;
    double b = 0;

    SDL_EnableKeyRepeat(10, 10); //Permet la répétition des entrées de clavier en régénérant l'evenement de touche préssée toute les 10ms
    while(exit) //Permet de gérer les inputs de l'utilisateurs
    {
        if(SDL_PollEvent(&event)){
         switch(event.key.keysym.sym){
            case SDLK_ESCAPE: //On appuie sur echap, on sort de la boucle et quitte le jeu
                exit = 0;
                break;
            case SDLK_w: // Si l'utilisateur appuie sur Z, faire avancer la caméra (axe x)
                x=x+1;
                break;
            case SDLK_s: // Si l'utilisateur appuie sur S, faire reculer la caméra (axe x)
                x=x-1;
                break;
            case SDLK_a: // Si l'utilisateur appuie sur Q, faire aller la caméra a gauche (axe y)
                y=y+1;
                break;
            case SDLK_d: // Si l'utilisateur appuie sur Z, faire aller la caméra a droite (axe y)
                y=y-1;
                break;
            case SDLK_UP: // Si l'utilisateur appuie sur Fleche haut, faire pivoter la caméra vers le haut (axe z)
                a=a+1;
                break;
            case SDLK_DOWN: // Si l'utilisateur appuie sur fleche bas , faire pivoter la caméra vers le bas (axe z)
                a=a-1;
                break;
            case SDLK_LEFT: // Si l'utilisateur appuie sur fleche gauche, faire pivoter la caméra vers la gauche (axe y)
                b=b+1;
                break;
            case SDLK_RIGHT: // Si l'utilisateur appuie sur fleche droite, faire pivoter la caméra vers la droite (axe y)
                b=b-1;
                break;
            default:
                break;
         }
        }
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        camera(x,y,20,x+3,y+b,20+a);
        glPopMatrix();

        // Boucle qui forme les cubes utilisés pour "parquer" le joueur (fais à deux sur mon PC)
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
