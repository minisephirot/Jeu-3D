#include "constante.h"

void deplcementEnnemis(Ennemis *cube, int ncubes)
{
	for (int i=0; i<ncubes; i++) {
      //---------Géstion des Ennemis---------
      //****************************************

          cube[i].x+=cube[i].dx;
          cube[i].y+=cube[i].dy;
          //---gestion mouvement---
          if (cube[i].x >= ((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES))
          {
		cube[i].dx *= -1;
          }
          if (cube[i].x <= TAILLE_CUBES)
          {
		cube[i].dx *= -1;
          }

          if (cube[i].y <= TAILLE_CUBES)
          {
		cube[i].dy *= -1;
          }
          if(cube[i].y >= ((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES))
          {
		cube[i].dy *= -1;
          }
          //---fin gestion---



          cube_position(TAILLE_CUBES/2,cube[i].x,cube[i].y,0,90,0,0);

	}
      //---------Fin de géstion---------
      //**************************************
}

void generationbonus(Bonus *scoring, int nbonus)
{
 for (int i=0; i<nbonus; i++) {

     scoring[i].z = scoring[i].z+sin(scoring[i].z)*4;

     sphere_position(scoring[i].x,scoring[i].y,scoring[i].z,1,1,1);

	}
}
