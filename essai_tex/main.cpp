#include "main.h"

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

glEnable(GL_TEXTURE_2D);
texture1 = loadTexture("stainedglass05.jpg");
glBindTexture(GL_TEXTURE_2D, texture1);


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
      for(int i = 0; i<20*5; i=i+5){
        cube_position(3,i,0,0,0,0,0);
      }

    glFlush();
    SDL_GL_SwapBuffers();
  }


}

