#include <SDL_mixer.h>
#include "accueil.h"

int menu(){

  bool continuer;
  int choix;
  SDL_Surface *ecran = NULL,
  *fond = NULL,
  *fleche = NULL;
  SDL_Rect position, posFleche;


  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Arcade : Cube", NULL);
  SDL_EnableKeyRepeat(0,0);
  position.x = 0;
  position.y = 0;
  posFleche.x= 330;
  posFleche.y= 150;

  choix = 1;

  fond = SDL_LoadBMP("texture/cube.bmp");
  fleche = SDL_LoadBMP("texture/fleche.bmp");
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
            SDL_Delay(100);
            }
            else
              if (choix == 2)
              {
                posFleche.x= 330;
                posFleche.y= 300;
                choix = 3;
                SDL_Delay(100);
              }
              else
                if (choix == 3)
                {
                  posFleche.x= 330;
                  posFleche.y= 150;
                  choix = 1;
                  SDL_Delay(100);
                }
          break;
          case SDLK_UP:
            if (choix == 1)
            {
            posFleche.x= 330;
            posFleche.y= 300;
            choix = 3;
            SDL_Delay(100);
            }
            else
              if (choix == 2)
              {
                posFleche.x= 330;
                posFleche.y= 150;
                choix = 1;
                SDL_Delay(100);
              }
              else
                if (choix == 3)
                {
                  posFleche.x= 330;
                  posFleche.y= 220;
                  choix = 2;
                  SDL_Delay(100);

                }
          default:
          break;
        }
        default:
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

int tuto()
{

  bool continuer;
  int choix;
  SDL_Surface *ecran = NULL,
  *tuto = NULL;
  SDL_Rect position;


  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Arcade : Cube", NULL);

  position.x = 0;
  position.y = 0;

  choix = 1;

  tuto = SDL_LoadBMP("texture/tuto.bmp");

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
          case SDLK_RETURN:
              continuer = 0;
          case SDLK_ESCAPE:
            continuer = 0;
          break;
          case SDLK_SPACE:
            continuer = 0;
          break;
          default:
           break;
        }
          default:
            break;
    }

    SDL_BlitSurface(tuto, NULL, ecran, &position);
    SDL_Flip(ecran);

  }

  SDL_FreeSurface(tuto);

  return choix;
}

int gameover()
{

  bool continuer;
  int choix;
  SDL_Surface *ecran = NULL,
  *gover = NULL;
  SDL_Rect position;


  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Arcade : Cube", NULL);
  Mix_Chunk *fail = Mix_LoadWAV("texture/fail.wav");
  Mix_VolumeChunk(fail,6);
  Mix_PlayChannel(1, fail, 0);
  position.x = 0;
  position.y = 0;

  choix = 1;

  gover = SDL_LoadBMP("texture/gameover.bmp");

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
          case SDLK_RETURN:
              continuer = 0;
          case SDLK_ESCAPE:
            continuer = 0;
          break;
          case SDLK_SPACE:
            continuer = 0;
          break;
          default:
           break;
        }
          default:
            break;
    }

    SDL_BlitSurface(gover, NULL, ecran, &position);
    SDL_Flip(ecran);

  }

  SDL_FreeSurface(gover);

  return choix;
}
