#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int tuto()
{
  
  bool continuer;
  int choix;
  SDL_Surface *ecran = NULL, 
  *tuto = NULL;
  SDL_Rect position;

  
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("NOM DU JEU", NULL);
  
  position.x = 0;
  position.y = 0;

  choix = 1;

  tuto = SDL_LoadBMP("tuto.bmp");

  continuer = true;
  SDL_Event event;
  while (continuer){
    SDL_WaitEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
        continuer = 0;
        choix = 0;
      break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE: 
            continuer = 0;
            choix = 0;
          break;
          case SDLK_SPACE: 
            continuer = 0;
          break;
        }
        break;
    }

    SDL_BlitSurface(tuto, NULL, ecran, &position);
    SDL_Flip(ecran);

  }

  SDL_FreeSurface(tuto);

  return choix;
}
