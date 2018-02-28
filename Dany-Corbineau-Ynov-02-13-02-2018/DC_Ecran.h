#ifndef DC_ECRAN_H_INCLUDED
#define DC_ECRAN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Base_DC.h"
#define DC_FULLSCREEN 1
#define DC_ALPHA 2
#define DC_Z_TEST 4
#define DC_TTF 8


class DC_Ecran
{
    private:
    int E_x;
    int E_y;
    double angle_alpha,angle_beta;//degre
    double cam_x,cam_y,cam_z;
    bool alpha;
    bool z_test;
    bool ttf;
    bool fullscreen;

    void DC_Ecran_aff_cam();
    public:
    DC_Ecran(int x,int y,char *im_fond,char *name_ecran,bool Fullscreen,bool Alpha,
                   bool Ttf,bool Z_test);
    ~DC_Ecran();
    void aff_ecran();
    void matrice_2d();
    void matrice_3d();
    void vider_ecran();

    void DC_ecran_set_taille(int x,int y);
    int DC_ecran_get_x();
    int DC_ecran_get_y();

    void DC_Ecran_set_cam_x(double x);
    void DC_Ecran_set_cam_y(double y);
    void DC_Ecran_set_cam_z(double z);
    void DC_Ecran_set_cam_alpha(double a);
    void DC_Ecran_set_cam_beta(double b);


};


#endif // DC_ECRAN_H_INCLUDED
