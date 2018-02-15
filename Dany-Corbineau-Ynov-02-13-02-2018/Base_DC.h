#ifndef BASE_DC_H_INCLUDED
#define BASE_DC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <winsock2.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>




GLuint cree_texture_chaine_beau_text_longeur(char *c,TTF_Font *f,SDL_Color v,int *x,int *y);
void tracer_ligne(double pos_x,double pos_y,double pos_x2,double pos_y2,char r,char g, char b);
void tracer_rectangle_texture_angle(double pos_x,double pos_y,double long_x,double large_y,double alpha,GLuint texture);
GLuint cree_texture_chaine(char *c,TTF_Font *f,SDL_Color v);
void enregistrer_clic_pos(FILE *f,SDL_Event e);
int ent_aleat(int Max,int Min);
void tracer_rectangle(double pos_x,double pos_y,double long_x,double large_y,char r,char g, char b);
void tracer_rectangle_texture(double pos_x,double pos_y,double long_x,double large_y,GLuint texture);
GLuint loadTexture(const char * filename);
SDL_Surface * flipSurface(SDL_Surface * surface);
GLuint charge_surface(SDL_Surface *picture_surface);
GLuint cree_texture_nombre(double x,TTF_Font *f,SDL_Color v);
GLuint cree_texture_chaine_longeur(char *c,TTF_Font *f,SDL_Color v,int *x,int *y);
#endif // BASE_DC_H_INCLUDED
