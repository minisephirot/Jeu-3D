/************************************
 *          Les Fonctions           *
 *          Projet d'AP3            *
 *                                  *
 * fait par : Elliot This           *
 *         et Rémi Le Brech         *
 *                                  *
 * Crée le 28 septembre 2016        *
 ************************************/


/*fonction qui initialise opengl et sdl
  x et y sont la taille de la fenetre
  c est le fovy, le cham de vision */
void sdl3d(int x, int y, int c){
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_SetVideoMode(x, y, 32, SDL_OPENGL);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(c,(double)x/y,1,1000);
    glEnable(GL_DEPTH_TEST);
}



/*Fonctions qui initalise la camera 
  x, y et z sont les coordonné de la camera
  e1, e2 et e3 sont les coordonné du point qui fixe la camera */
void camera(int x, int y, int z, int e1, int e2, int e3){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(x,y,z,e1,e2,e3,0,0,1);
}



/*Fonction qui dessine les cubes sur une meme matrice
  taille est la taille des cube
  x, y et z la postion par rapport a la matrice
  a, b et c l'angle du cube sur la matrice */
void cube(int taille, int x, int y, int z,double a, double b, double c){
    glTranslated(x,y,z);
    glRotated(a,b,c,1);
glBegin(GL_QUADS);
    glColor3ub(255,0,0); //1
    glVertex3d(taille,taille,taille);
    glVertex3d(taille,taille,-taille);
    glVertex3d(-taille,taille,-taille);
    glVertex3d(-taille,taille,taille);
glColor3ub(0,0,255);    //2
    glVertex3d(taille,-taille,taille);
    glVertex3d(taille,taille,taille);
    glVertex3d(-taille,taille,taille);
    glVertex3d(-taille,-taille,taille);
glColor3ub(0,255,0);    //3
    glVertex3d(taille,-taille,-taille);
    glVertex3d(taille,-taille,taille);
    glVertex3d(-taille,-taille,taille);
    glVertex3d(-taille,-taille,-taille);
glColor3ub(50,50,50);    //4
    glVertex3d(-taille,taille,-taille);
    glVertex3d(taille,taille,-taille);
    glVertex3d(taille,-taille,-taille);
    glVertex3d(-taille,-taille,-taille);
glColor3ub(50,100,200);    //5
    glVertex3d(-taille,taille,taille);
    glVertex3d(-taille,-taille,taille);
    glVertex3d(-taille,-taille,-taille);
    glVertex3d(-taille,taille,-taille);
glColor3ub(100,50,100);    //6
    glVertex3d(taille,taille,taille);
    glVertex3d(taille,-taille,taille);
    glVertex3d(taille,-taille,-taille);
    glVertex3d(taille,taille,-taille);
    glEnd();

}

/*Fonction qui dessine les cubes sur un repere
  taille est la taille des cube
  x, y et z la postion
  a, b et c l'angle des cubes */
void cube_position(int taille,int x,int y,int z,int a,int b,int c){
        glPushMatrix();
        cube(taille,x,y,z,a,b,c);
        glPopMatrix();
}

