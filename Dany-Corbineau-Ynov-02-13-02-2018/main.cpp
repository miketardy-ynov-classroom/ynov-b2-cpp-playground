#include "main_header.h"


int main ( int argc, char** argv )
{
    DC_Ecran *e=new DC_Ecran(SCREEN_X,SCREEN_Y,NULL,"Graphe",0,true,true,1);
    long timeDisplay=0;
    bool looping=true;
    SDL_Event event;
    TTF_Font *police=TTF_OpenFont("Roboto-Regular.ttf",32);
    char startPath[1024]="C:\\Users\\Dany CORBINEAU\\Documents\\programmation maison\\C\\Dany-Corbineau-Ynov-02-13-02-2018";

    DirData *dd=NULL;
    int nbDir=getDirData(startPath,dd);
    DirTextureText *textures=generateTexturs(police,dd,nbDir);


    while(looping){

        /*
            event
        */
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_KEYDOWN){
                if(event.key.keysym.sym==SDLK_ESCAPE)
                    looping=false;
            }
            else if(event.type==SDL_QUIT){
                looping=false;
            }
            else if(event.type==SDL_MOUSEBUTTONDOWN){
                char pathName[512];
                int dirValue=getDirOnClic(dd,nbDir,event.button.x,event.button.y);
                printf("Last Path : %s ",startPath);
                if(dirValue>=0){
                    strcpy(pathName,dd[dirValue].name);
                    if(strcmp("..",pathName)==0 &&strlen(startPath)>3){
                        startPath[strlen(startPath)-1]=0;
                        for(int j=strlen(startPath)-1;j>0;--j){
                            if(startPath[j]=='\\')
                                break;
                            startPath[j]=0;
                        }
                    }
                    else{
                        if(startPath[strlen(startPath)-1]=='\\')
                            startPath[strlen(startPath)-1]=0;
                        sprintf(startPath,"%s%c%s",startPath,'\\',pathName);
                    }
                    printf(" new Path : %s \n",startPath);
                    e->vider_ecran();
                    e->matrice_2d();

                    tracer_rectangle(0,0,SCREEN_X,SCREEN_Y,255,255,255);

                    e->aff_ecran();
                    reactualiserDossier(startPath,dd,textures,&nbDir,police);

                }
            }
        }

        /*
            Display
        */
        if(clock()-timeDisplay>1000.0/60.0)
        {
            e->vider_ecran();
            e->matrice_2d();

            tracer_rectangle(0,0,SCREEN_X,SCREEN_Y,255,255,255);
            afficherDossierEtFichier(textures,dd,nbDir);
            tracer_ligne(SCREEN_X/2,0,SCREEN_X/2,SCREEN_Y,255,255,255);

            e->aff_ecran();

            SDL_Delay(1000.0/60.0/2.0);
            timeDisplay=clock();
        }


    }

    TTF_CloseFont(police);
    free(dd);
    delete e;
    return 0;
}

int getDirData(string path,DirData * &dd){
    DIR* racine=opendir(path.c_str());
    dirent *d;
    int j=0;
    struct stat st;

    while( (d=readdir(racine)) ){
        if(strcmp(d->d_name,".")!=0){
            char newPath[512];
            sprintf(newPath,"%s\\%s",path.c_str(),d->d_name);
            stat(newPath, &st);

            dd=(DirData*)realloc(dd,sizeof(DirData)*(j+1));
            dd[j].d_size=getFileSize(newPath);
            strcpy(dd[j].name,d->d_name);
            ++j;
        }
    }
    return j;
}

int isDir(char *name)
{
    if ((strchr(name, '.')) == NULL){
        return 1;
    }
    else
        return 0;
}

int getFileSize(char *path)
{
    FILE *f=fopen(path,"r");
    int j;
    for(j=0; (fgetc(f)) != EOF ; ++j );
    fclose(f);
    return j;
}

DirTextureText *generateTexturs(TTF_Font *police,DirData *dd, int nbDir ){
    DirTextureText *ret=(DirTextureText*)malloc(sizeof(DirTextureText)*nbDir);

    int j;
    for(j=0;j<nbDir;j++){
        ret[j].id=cree_texture_chaine_longeur(dd[j].name,police,{0,0,0},&ret[j].x,&ret[j].y);
    }
    return ret;
}

void afficherDossierEtFichier(DirTextureText *t,DirData *data, int nbDir ){
    int nbDirectory=countNbDir(data,nbDir);
    nbDirectory+=1;
    long long filesSize=getTotalFileSize(data,nbDir);
    int deplacement=0;

    for(int j=0,k=0,l=0;j<nbDir;++j){
        if(isDir(data[j].name) || strcmp(data[j].name,".")==0 || strcmp(data[j].name,"..")==0){
            tracer_rectangle(0,k*SCREEN_Y/nbDirectory,SCREEN_X/2,SCREEN_Y/nbDirectory+1,128+(j*(int)pow(2,8*3)/2/nbDir)/255/255%128,128+(j*(int)pow(2,8*3)/2/nbDir)%128,128+(j*(int)pow(2,8*3)/2/nbDir)/255%128);
            tracer_rectangle_texture(0,k*SCREEN_Y/nbDirectory,  t[j].x*32/t[j].y,   32,   t[j].id);
            ++k;
        }
        else{
            tracer_rectangle(SCREEN_X/2,deplacement,SCREEN_X/2,data[j].d_size*SCREEN_Y/filesSize,128,255-(data[j].d_size*128/filesSize),128+(data[j].d_size*128/filesSize));
            if(data[j].d_size*SCREEN_Y/filesSize>32)
                tracer_rectangle_texture(SCREEN_X/2,deplacement,  t[j].x*32/t[j].y,   32,   t[j].id);
            else
                tracer_rectangle_texture(SCREEN_X/2,deplacement,  t[j].x*(data[j].d_size*SCREEN_Y/filesSize)/t[j].y,   (data[j].d_size*SCREEN_Y/filesSize),   t[j].id);
            ++l;
            deplacement+=data[j].d_size*SCREEN_Y/filesSize;
        }
    }

}
void reactualiserDossier(char *path,DirData *&data,DirTextureText *&t,int *nbDir, TTF_Font *police){
    free(data);
    for(int j=0;j<*nbDir;j++)
        glDeleteTextures(1,&(t[j].id));
    free(t);
    data=NULL;
    t=NULL;
    *nbDir=getDirData(path,data);
    t=generateTexturs(police,data,*nbDir);
}


int countNbDir(DirData *data, int nbDir){
    int k=0;
    for(int j=0; j<nbDir;++j)
        if(isDir(data[j].name))
            ++k;
    return k;
}
long long getTotalFileSize(DirData *data, int nbDir){
    long long ret=0;
    for(int j=0; j<nbDir;++j)
        if(!isDir(data[j].name))
            ret+=data[j].d_size;
    return ret;
}

int getDirOnClic(DirData *data, int nbDir,int cX,int cY){
    int ret=-1;
    int nbDirectory=countNbDir(data,nbDir);
    nbDirectory+=1;

    if(cX<SCREEN_X/2){
        for(int j=0,k=0;j<nbDir;++j){
            if(isDir(data[j].name)==1 || strcmp(data[j].name,"..")==0){
                if(cY>k*SCREEN_Y/nbDirectory && cY<(k+1)*SCREEN_Y/nbDirectory)
                    return j;
                ++k;
            }
        }
    }
    return ret;
}




