#include <GL/gl.h>
#include "ennemis.h"
#include "lib_fst.h"
#include "sdlglutils.h"


void deplcementEnnemis(Ennemis *cube, int ncubes, int scorejoueur,GLuint tex)
{
    double vitesse = scorejoueur / 100.0 ;
	for (int i=0; i<ncubes; i++) {
      //---------Géstion des Ennemis---------
      //****************************************
          cube[i].x+=cube[i].dx * vitesse ;
          cube[i].y+=cube[i].dy * vitesse ;
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
          for (int j=0; j<ncubes; j++) {
            if (j != i ){
              if ((((cube[i-j].x)-TAILLE_CUBES/2)+TAILLE_CUBES/2) >= (((cube[i].x)-TAILLE_CUBES/2)-TAILLE_CUBES/2) &&
              (((cube[i-j].x)+TAILLE_CUBES/2)-TAILLE_CUBES/2) <= (((cube[i].x)+TAILLE_CUBES/2)+TAILLE_CUBES/2) &&
              (((cube[i-j].y)-TAILLE_CUBES/2)+TAILLE_CUBES/2) >= (((cube[i].y)-TAILLE_CUBES/2)-TAILLE_CUBES/2) &&
              (((cube[i-j].y)+TAILLE_CUBES/2)-TAILLE_CUBES/2) <= (((cube[i].y)+TAILLE_CUBES/2)+TAILLE_CUBES/2))
              {
                cube[i].dx *= -1 ;
                cube[i-j].dx *= -1 ;
                cube[i].dy *= -1 ;
                cube[i-j].dy *= -1 ;
              }
              if ((((cube[i+j].x)-TAILLE_CUBES/2)+TAILLE_CUBES/2) >= (((cube[i].x)-TAILLE_CUBES/2)-TAILLE_CUBES/2) &&
              (((cube[i+j].x)+TAILLE_CUBES/2)-TAILLE_CUBES/2) <= (((cube[i].x)+TAILLE_CUBES/2)+TAILLE_CUBES/2) &&
              (((cube[i+j].y)-TAILLE_CUBES/2)+TAILLE_CUBES/2) >= (((cube[i].y)-TAILLE_CUBES/2)-TAILLE_CUBES/2) &&
              (((cube[i+j].y)+TAILLE_CUBES/2)-TAILLE_CUBES/2) <= (((cube[i].y)+TAILLE_CUBES/2)+TAILLE_CUBES/2))
              {
                cube[i].dx *= -1 ;
                cube[i+j].dx *= -1 ;
                cube[i].dy *= -1 ;
                cube[i+j].dy *= -1 ;
              }
            }
          }
          //---fin gestion---

          glBindTexture(GL_TEXTURE_2D, tex);
          cubeennemis_position(TAILLE_CUBES/2,cube[i].x,cube[i].y,0,90,0,0);

	}
      //---------Fin de géstion---------
      //**************************************
}



void generationbonus(Bonus *scoring, int nbonus, GLuint tex){

 for (int i=0; i<nbonus; i++) {


     glBindTexture(GL_TEXTURE_2D, tex);
     sphere_position(scoring[i].x,scoring[i].y,scoring[i].z);

	}
}
