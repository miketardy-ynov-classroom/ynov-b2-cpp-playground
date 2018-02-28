#include "Base_DC.h"


GLuint cree_texture_chaine_beau_text_longeur(char *c,TTF_Font *f,SDL_Color v,int *x,int *y)
{
    SDL_Surface *s=NULL;
    GLuint p=0;
    s=TTF_RenderText_Blended(f,c,v);
    *x=s->w;
    *y=s->h;
    p=charge_surface(s);
    free(s);

    return p;
}



void tracer_ligne(double pos_x,double pos_y,double pos_x2,double pos_y2,char r,char g, char b)
{
    glBindTexture(GL_TEXTURE_2D,0);
    glBegin(GL_LINES);
    glColor3ub(r,g,b);
    glVertex2d(pos_x,pos_y);
    glVertex2d(pos_x2,pos_y2);
    glEnd();
}

GLuint cree_texture_nombre(double x,TTF_Font *f,SDL_Color v)
{
    SDL_Surface *s=NULL;
    GLuint p=0;
    int j,t=1;
    char text[600]={0};

    sprintf(text,"%.10lf",x);

    for(j=0;j<600&&text[j]!=0;j++)
    {
        if(t==1&&text[j]=='.')
        {
            t=0;
        }
        else if(text[j]=='0'&&t==0)
        {
            text[j]=0;
        }
    }

    s=TTF_RenderText_Solid(f,text,v);
    p=charge_surface(s);
    free(s);

    return p;
}

void tracer_rectangle_texture_angle(double pos_x,double pos_y,double long_x,double large_y,double alpha,GLuint texture)
{
    glPushMatrix();
    glTranslated(pos_x+long_x/2,pos_y+large_y/2,0);
    glRotated(-alpha,0,0,1);
    glBindTexture(GL_TEXTURE_2D,texture);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex2d(-long_x/2,large_y/2);
    glTexCoord2d(0,1);
    glVertex2d(-long_x/2,-large_y/2);
    glTexCoord2d(1,1);
    glVertex2d(long_x/2,-large_y/2);
    glTexCoord2d(1,0);
    glVertex2d(long_x/2,+large_y/2);
    glEnd();
    glPopMatrix();
}
GLuint cree_texture_chaine_longeur(char *c,TTF_Font *f,SDL_Color v,int *x,int *y)
{
    SDL_Surface *s=NULL;
    GLuint p=0;
    s=TTF_RenderText_Solid(f,c,v);
    *x=s->w;
    *y=s->h;
    p=charge_surface(s);
    free(s);

    return p;
}
GLuint cree_texture_chaine(char *c,TTF_Font *f,SDL_Color v)
{
    SDL_Surface *s=NULL;
    GLuint p=0;
    s=TTF_RenderText_Solid(f,c,v);
    p=charge_surface(s);
    free(s);

    return p;
}

void enregistrer_clic_pos(FILE *f,SDL_Event e)
{
    fprintf(f,"%lf*Ecran_x  %lf*Ecran_y\n",(double)e.button.x/e.resize.w,(double)e.button.y/e.resize.h);
}

int ent_aleat(int Max,int Min)
{
    int t=0;
    t=(rand()%(Max-Min+1))+Min;
    return t;
}

void tracer_rectangle(double pos_x,double pos_y,double long_x,double large_y,char r,char g, char b)
{
    glBindTexture(GL_TEXTURE_2D,0);
    glBegin(GL_QUADS);
    glColor3ub(r,g,b);
    glVertex2d(pos_x,pos_y);
    glVertex2d(pos_x+long_x,pos_y);
    glVertex2d(pos_x+long_x,pos_y+large_y);
    glVertex2d(pos_x,large_y+pos_y);
    glEnd();
}

void tracer_rectangle_texture(double pos_x,double pos_y,double long_x,double large_y,GLuint texture)
{
    glBindTexture(GL_TEXTURE_2D,texture);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex2d(pos_x,large_y+pos_y);
    glTexCoord2d(0,1);
    glVertex2d(pos_x,pos_y);
    glTexCoord2d(1,1);
    glVertex2d(pos_x+long_x,pos_y);
    glTexCoord2d(1,0);
    glVertex2d(pos_x+long_x,pos_y+large_y);
    glEnd();
}

GLuint loadTexture(const char * filename)
{

    GLuint glID;
    SDL_Surface * picture_surface = NULL;
    SDL_Surface *gl_surface = NULL;
    SDL_Surface * gl_fliped_surface = NULL;
    Uint32 rmask, gmask, bmask, amask;

    picture_surface = IMG_Load(filename);
    if (picture_surface == NULL)
        return 0;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN

    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else

    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

    SDL_PixelFormat format = *(picture_surface->format);
    format.BitsPerPixel = 32;
    format.BytesPerPixel = 4;
    format.Rmask = rmask;
    format.Gmask = gmask;
    format.Bmask = bmask;
    format.Amask = amask;

    gl_surface = SDL_ConvertSurface(picture_surface,&format,SDL_SWSURFACE);

    gl_fliped_surface = flipSurface(gl_surface);

    glGenTextures(1, &glID);

    glBindTexture(GL_TEXTURE_2D, glID);


    if (1)
    {

        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, gl_fliped_surface->w,
                          gl_fliped_surface->h, GL_RGBA,GL_UNSIGNED_BYTE,
                          gl_fliped_surface->pixels);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
                        GL_LINEAR_MIPMAP_LINEAR);

    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_fliped_surface->w,
                     gl_fliped_surface->h, 0, GL_RGBA,GL_UNSIGNED_BYTE,
                     gl_fliped_surface->pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


    SDL_FreeSurface(gl_fliped_surface);
    SDL_FreeSurface(gl_surface);
    SDL_FreeSurface(picture_surface);

    return glID;
}

SDL_Surface * flipSurface(SDL_Surface * surface)
{
    int current_line,pitch;
    SDL_Surface * fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                   surface->w,surface->h,
                                   surface->format->BitsPerPixel,
                                   surface->format->Rmask,
                                   surface->format->Gmask,
                                   surface->format->Bmask,
                                   surface->format->Amask);



    SDL_LockSurface(surface);
    SDL_LockSurface(fliped_surface);

    pitch = surface->pitch;
    for (current_line = 0; current_line < surface->h; current_line ++)
    {
        memcpy(&((unsigned char* )fliped_surface->pixels)[current_line*pitch],
               &((unsigned char* )surface->pixels)[(surface->h - 1  -
                                                    current_line)*pitch],
               pitch);
    }

    SDL_UnlockSurface(fliped_surface);
    SDL_UnlockSurface(surface);
    return fliped_surface;
}

GLuint charge_surface(SDL_Surface *picture_surface)
{
    GLuint glID;
   if(picture_surface!=NULL)
    {
    SDL_Surface *gl_surface = NULL;
    SDL_Surface * gl_fliped_surface = NULL;
    Uint32 rmask, gmask, bmask, amask;



#if SDL_BYTEORDER == SDL_BIG_ENDIAN

    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else

    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

    SDL_PixelFormat format = *(picture_surface->format);
    format.BitsPerPixel = 32;
    format.BytesPerPixel = 4;
    format.Rmask = rmask;
    format.Gmask = gmask;
    format.Bmask = bmask;
    format.Amask = amask;

    gl_surface = SDL_ConvertSurface(picture_surface,&format,SDL_SWSURFACE);

    gl_fliped_surface = flipSurface(gl_surface);

    glGenTextures(1, &glID);

    glBindTexture(GL_TEXTURE_2D, glID);


    if (1)
    {

        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, gl_fliped_surface->w,
                          gl_fliped_surface->h, GL_RGBA,GL_UNSIGNED_BYTE,
                          gl_fliped_surface->pixels);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
                        GL_LINEAR_MIPMAP_LINEAR);

    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_fliped_surface->w,
                     gl_fliped_surface->h, 0, GL_RGBA,GL_UNSIGNED_BYTE,
                     gl_fliped_surface->pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


    SDL_FreeSurface(gl_fliped_surface);
    SDL_FreeSurface(gl_surface);}


    return glID;
}
