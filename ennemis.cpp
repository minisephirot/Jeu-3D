#include "ennemis.h"
#include "lib_fst.h"
#include "sdlglutils.h"


void deplcementEnnemis(Ennemis *cube, int ncubes, int scorejoueur)
{
    GLuint texture2 = loadTexture("texture/mur.jpg");
	for (int i=0; i<ncubes; i++) {
      //---------Géstion des Ennemis---------
      //****************************************

          cube[i].x+=cube[i].dx * (scorejoueur/40) ;
          cube[i].y+=cube[i].dy * (scorejoueur/40) ;
          //---gestion mouvement---
          if (cube[i].x >= ((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES))
          {
		cube[i].dx *= -1 ;
		cube[i].x = cube[i].x - 6;
          }
          if (cube[i].x <= TAILLE_CUBES)
          {
		cube[i].dx *= -1 ;
		cube[i].x = cube[i].x + 6;
          }

          if (cube[i].y <= TAILLE_CUBES)
          {
		cube[i].dy *= -1 ;
		cube[i].y = cube[i].y + 6;
          }
          if(cube[i].y >= ((TAILLE_CUBES*TAILLE_PLATEAU)-TAILLE_CUBES))
          {
		cube[i].dy *= -1 ;
		cube[i].y = cube[i].y - 6;
          }
          //---gestion collision intercubes---
          if ((((cube[i-1].x)-TAILLE_CUBES/2)-33) >= (((cube[i].x)-TAILLE_CUBES/2)-33) &&
            (((cube[i-1].x)+TAILLE_CUBES/2)-33) <= (((cube[i].x)+TAILLE_CUBES/2)+33) &&
            (((cube[i-1].y)-TAILLE_CUBES/2)-33) >= (((cube[i].y)-TAILLE_CUBES/2)-33) &&
            (((cube[i-1].y)+TAILLE_CUBES/2)-33) <= (((cube[i].y)+TAILLE_CUBES/2)+33))
          {
            cube[i].dx *= -1 ;
            cube[i-1].dx *= -1 ;
          }
          if ((((cube[i+1].x)-TAILLE_CUBES/2)-33) >= (((cube[i].x)-TAILLE_CUBES/2)-33) &&
            (((cube[i+1].x)+TAILLE_CUBES/2)-33) <= (((cube[i].x)+TAILLE_CUBES/2)+33) &&
            (((cube[i+1].y)-TAILLE_CUBES/2)-33) >= (((cube[i].y)-TAILLE_CUBES/2)-33) &&
            (((cube[i+1].y)+TAILLE_CUBES/2)-33) <= (((cube[i].y)+TAILLE_CUBES/2)+33))
          {
            cube[i].dx *= -1 ;
            cube[i+1].dx *= -1 ;
          }
          //---fin gestion---

          glBindTexture(GL_TEXTURE_2D, texture2);
          cube_position(TAILLE_CUBES/2,cube[i].x,cube[i].y,0,90,0,0);

	}
      //---------Fin de géstion---------
      //**************************************
}



void generationbonus(Bonus *scoring, int nbonus){
 for (int i=0; i<nbonus; i++) {



     sphere_position(scoring[i].x,scoring[i].y,scoring[i].z,1,1,1);

	}
}
