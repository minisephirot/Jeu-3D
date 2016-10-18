/************************************
 *           NOM DU JEU             *
 *          Projet d'AP3            *
 *                                  *
 * fait par : Elliot This           *
 *         et Rémi Le Brech         *
 *                                  *
 * Crée le 28 septembre 2016        *
 ************************************/
#include "accueil.h"
#include "tuto.h"
#include "game.h"


int main(int argc, char *argv[])
{
  freopen( "CON", "w", stdout );
  freopen( "CON", "w", stderr );

  int choix;
  choix = 1;
  while(choix!=0){
    choix = menu();
    if(choix == 1)
      choix = gameStart();
    else
      if(choix == 2)
        choix = tuto();
      else
        if(choix == 3)
          choix = 0;
  }


  return 0;
}
