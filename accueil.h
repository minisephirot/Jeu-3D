#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int menu()
{
  
  bool continuer;
  int choix;
  SDL_Surface *ecran = NULL, 
  *fond = NULL,
  *fleche = NULL;
  SDL_Rect position, posFleche;

  
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("NOM DU JEU", NULL);
  
  position.x = 0;
  position.y = 0;
  posFleche.x= 330;
  posFleche.y= 150;

  choix = 1;

  fond = SDL_LoadBMP("cube.bmp");
  fleche = SDL_LoadBMP("fleche.bmp");
  SDL_SetColorKey(fleche, SDL_SRCCOLORKEY, SDL_MapRGB(fleche->format, 0, 255, 0));

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
          case SDLK_RETURN: 
            continuer = 0;
          break;
          case SDLK_DOWN:
            if (choix == 1)
            {
            posFleche.x= 330;
            posFleche.y= 220;
            choix = 2;
            SDL_Delay(200);
            }
            else
              if (choix == 2)
              {
                posFleche.x= 330;
                posFleche.y= 300;
                choix = 3;
                SDL_Delay(200);
              }
              else 
                if (choix == 3)
                {
                  posFleche.x= 330;
                  posFleche.y= 150;
                  choix = 1;
                  SDL_Delay(200);
                }
          break;
          case SDLK_UP:
            if (choix == 1)
            {
            posFleche.x= 330;
            posFleche.y= 300;
            choix = 3;
            SDL_Delay(200);
            }
            else
              if (choix == 2)
              {
                posFleche.x= 330;
                posFleche.y= 150;
                choix = 1;
                SDL_Delay(200);
              }
              else 
                if (choix == 3)
                {
                  posFleche.x= 330;
                  posFleche.y= 220;
                  choix = 2;
                  SDL_Delay(200);

                }
          break;
        }
        break;
    }

    SDL_BlitSurface(fond, NULL, ecran, &position);
    SDL_BlitSurface(fleche, NULL, ecran, &posFleche);

    SDL_Flip(ecran);

  }

  SDL_FreeSurface(fond);
  SDL_FreeSurface(fleche);

  return choix;
}
