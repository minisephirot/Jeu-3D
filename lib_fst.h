/************************************
 *          Les Fonctions           *
 *          Projet d'AP3            *
 *                                  *
 * fait par : Elliot This           *
 *         et Rémi Le Brech         *
 *                                  *
 * Crée le 28 septembre 2016        *
 ************************************/
#include <SDL/SDL.h>
#include <GL/glu.h>

void sdl3d(int x, int y, int c);
void camera(double x, double y, double z, double e1, double e2, double e3);
void cube(double taille, double x, double y, double z,double a, double b, double c);
void sphere(int x, int y , int z);
void sphere_position(int x,int y , int z);
void cube_position(int taille, double x, double y, double z,double a, double b, double c);
double direction(double a);
void plat(double taille,double x,double y,double z,double a,double b,double c);
void plat_pos(double taille,double x,double y,double z,double a,double b,double c);
void plafond(double taille,double x,double y,double z,double a,double b,double c);
void plaf_pos(double taille,double x,double y,double z,double a,double b,double c);
void cubeennemis(double taille,double x,double y,double z,double a,double b,double c);
void cubeennemis_position(int taille, double x, double y, double z,double a, double b, double c);
void interface();
void interface0();
void interface10();
void interface100();
int choixscore(int score, int* centaine);
//void tri(int n, int tab[n]);

