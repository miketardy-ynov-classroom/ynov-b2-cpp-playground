#include "Joueur.h"


Joueur::Joueur(int pv, int att, int def)
{
    this->att=att;
    this->pv=pv;
    this->def=def;
    this->xp=0;
}

Joueur::~Joueur()
{

}

int Joueur::attaquer()
{

    int frap=rand()*att/RAND_MAX;
    //printf("--- Le joueur frape a %d\n",frap);
    return frap;
}

int Joueur::prendre_dega(int dega)
{
    int frap=(dega-rand()*this->def/RAND_MAX);
    frap = frap<=0 ? 1 : 0;
    this->pv-=frap+1;
    if(this->pv<=0){
        this->pv=0;
        return (0);
    }
    return 1;
}

void Joueur::soigner(int soin)
{
    this->pv+=soin;
}

void Joueur::afficherPlayer()
{
    printf("Player : %dpv",this->pv);
}

bool Joueur::isKill()
{
    return (this->pv<=0) ? true : false;
}





