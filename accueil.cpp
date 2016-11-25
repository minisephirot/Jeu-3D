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
            posFleche.x= 330;SDL_SetColorKey(fleche, SDL_SRCCOLORKEY, SDL_MapRGB(fleche->format, 0, 255, 0));
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
                  posFleche.y= 370;
                  choix = 4;
                  SDL_Delay(100);
                }
                else
                  if (choix == 4)
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
            posFleche.y= 370;
            choix = 4;
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
                else
                  if (choix == 4)
                  {
                    posFleche.x= 330;
                    posFleche.y= 300;
                    choix = 3;
                    SDL_Delay(100);
                  }
          default:
          break;
        }
        default:
        break;
    }

    SDL_BlitSurface(fond, NULL, ecran, &position);SDL_SetColorKey(fleche, SDL_SRCCOLORKEY, SDL_MapRGB(fleche->format, 0, 255, 0));
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

int tabDesScores()
{

  bool continuer;
  int choix;
  SDL_Surface *ecran = NULL,
  *gover = NULL,
  *chiffre = NULL;
  SDL_Rect position, posChiffre, ChoixChiffre;
  //---------Fichier sauvegarde---------
  FILE* fichier = NULL;
  int scoretab[5]={0};


  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("NOM DU JEU", NULL);

  position.x = 0;
  position.y = 0;
  posChiffre.x = 40;
  posChiffre.y = 120;
  ChoixChiffre.x = 0;
  ChoixChiffre.y = 0;
  ChoixChiffre.w = 50;
  ChoixChiffre.h = 50;
//  ChoixChiffre.y += 60;
  choix = 1;

  gover = SDL_LoadBMP("texture/fond_score.bmp");
chiffre = IMG_Load("texture/chiffre.png");

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
    fichier = fopen("score.txt","r");
    if (fichier != NULL){
      fscanf(fichier,"%d\n%d\n%d\n%d\n%d", &scoretab[0], &scoretab[1],&scoretab[2],&scoretab[3],&scoretab[4]);
      fclose(fichier);
    }
    SDL_BlitSurface(gover, NULL, ecran, &position);
    for(int i=0; i<5;i++){
      posChiffre.x = 40;
      ChoixChiffre.y = scoretab[i]/100*59;
      posChiffre.y = 120+i*78;
      SDL_BlitSurface(chiffre, &ChoixChiffre, ecran, &posChiffre);

      ChoixChiffre.y = ((scoretab[i]/10)%10)*59;
      posChiffre.y = 120+i*78;
      posChiffre.x = 69;
      SDL_BlitSurface(chiffre, &ChoixChiffre, ecran, &posChiffre);

      ChoixChiffre.y = 0;
      posChiffre.y = 120+i*78;
      posChiffre.x = 98;
      SDL_BlitSurface(chiffre, &ChoixChiffre, ecran, &posChiffre);
    }

    
    SDL_Flip(ecran);

  }

  SDL_FreeSurface(gover);
  SDL_FreeSurface(chiffre);

  return choix;
}
