#include "DC_Ecran.h"

#define M_PI 3.14
void DC_Ecran::DC_Ecran_set_cam_x(double x)
{
    cam_x=x;
}
void DC_Ecran::DC_Ecran_set_cam_y(double y)
{
    cam_y=y;
}
void DC_Ecran::DC_Ecran_set_cam_z(double z)
{
    cam_z=z;
}
void DC_Ecran::DC_Ecran_set_cam_alpha(double a)
{
    angle_alpha=a;
}
void DC_Ecran::DC_Ecran_set_cam_beta(double b)
{
    angle_beta=b;
}

void DC_Ecran::DC_Ecran_aff_cam()
{
    gluLookAt(cam_x,cam_y,cam_z,cam_x+cos(angle_alpha*M_PI/180)*sin(angle_beta*M_PI/180),
              cam_y+sin(angle_alpha*M_PI/180)*cos(angle_beta*M_PI/180),
              cam_z+sin(angle_beta*M_PI/180),
              -cos(angle_alpha*M_PI/180)*sin(angle_beta*M_PI/180),
              -sin(angle_alpha*M_PI/180)*sin(angle_beta*M_PI/180),
              cos(angle_beta*M_PI/180));
}

void DC_Ecran::vider_ecran()
{
    if(z_test!=0)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
}

void DC_Ecran::aff_ecran()
{
    glDepthMask(GL_TRUE);
    glFlush();
    SDL_GL_SwapBuffers();
}

void DC_Ecran::matrice_2d()
{
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,E_x,E_y,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(z_test!=0)
    glDepthMask(GL_FALSE);

}
void DC_Ecran::matrice_3d()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70,(double)E_y/E_x,1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    if(z_test!=0)
    glDepthMask(GL_TRUE);

    this->DC_Ecran_aff_cam();
}






DC_Ecran::DC_Ecran(int x,int y,char *im_fond,char *name_ecran,bool Fullscreen,bool Alpha,
                   bool Ttf,bool Z_test)
{
    SDL_Init(SDL_INIT_VIDEO);
    if(im_fond!=NULL)
        if(im_fond[0]!=0)
            SDL_WM_SetIcon(IMG_Load(im_fond),NULL);
    E_x=x;
    E_y=y;
    alpha=Alpha;
    fullscreen=Fullscreen;
    z_test=Z_test;
    ttf=Ttf;
    if(fullscreen!=0)
    {
        SDL_SetVideoMode(x,y,32,SDL_OPENGL|SDL_FULLSCREEN);
        SDL_WM_SetCaption(name_ecran,NULL);
        glEnable(GL_TEXTURE_2D);

    }
    else
    {
        SDL_SetVideoMode(x,y,32,SDL_OPENGL);
        SDL_WM_SetCaption(name_ecran,NULL);
        glEnable(GL_TEXTURE_2D);
    }
    if(alpha!=0)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    if(z_test!=0)
    {
        glEnable(GL_DEPTH_TEST);
    }
    if(ttf!=0)
    {
        TTF_Init();
    }
}
DC_Ecran::~DC_Ecran()
{
    SDL_Quit();
    if(ttf!=0)
    {
        TTF_Quit();
    }
}

void DC_Ecran::DC_ecran_set_taille(int x,int y)
{
    if(x!=0)
        E_x=x;
    if(y!=0)
        E_y=y;
}
int DC_Ecran::DC_ecran_get_x()
{
    return E_x;
}
int DC_Ecran::DC_ecran_get_y()
{
    return E_y;
}

