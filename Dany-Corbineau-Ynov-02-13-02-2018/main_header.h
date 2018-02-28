#ifndef MAIN_HEADER_H_INCLUDED
#define MAIN_HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>
#include <dirent.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <string.h>
#include <SDL/SDL_ttf.h>
#ifndef WIN32
    #include <sys/types.h>
    #include <sys/stat.h>
#endif

#include "DC_Ecran.h"
#include "Base_DC.h"

#define SCREEN_X (6*200)
#define SCREEN_Y 800

typedef struct DirData DirData;
struct DirData{
    char name[512];
    int d_size;
};

typedef struct DirTextureText DirTextureText;
struct DirTextureText{
    GLuint id;
    int x,y;
};


using namespace std;

int isDir(char *name);
int getDirData(string path,DirData * &dd);
int getFileSize(char *path);
DirTextureText *generateTexturs(TTF_Font *police,DirData *dd, int nbDir );
int countNbDir(DirData *data, int nbDir);
void afficherDossierEtFichier(DirTextureText *t,DirData *data, int nbDir );
long long getTotalFileSize(DirData *data, int nbDir);
void reactualiserDossier(char *path,DirData *&data,DirTextureText *&t,int *nbDir, TTF_Font *police);

int getDirOnClic(DirData *data, int nbDir,int cX,int cY);

#endif // MAIN_HEADER_H_INCLUDED
