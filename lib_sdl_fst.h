void sdl3d(int x, int y, int c){
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_SetVideoMode(x, y, 32, SDL_OPENGL);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(c,(double)x/y,1,1000);
    glEnable(GL_DEPTH_TEST);
}

void camera(int x, int y, int z, int e1, int e2, int e3){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(x,y,z,e1,e2,e3,0,0,1);
}

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