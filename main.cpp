#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "lib_sdl_fst.h"

//blablabla

void sdl3d(int x, int y, int c);

int main(int argc, char *argv[])
{
    SDL_Event event;
    sdl3d(600,600, 100);
    SDL_WM_SetCaption("Base 3D", NULL);

    for(;;)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
              exit(0);
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




