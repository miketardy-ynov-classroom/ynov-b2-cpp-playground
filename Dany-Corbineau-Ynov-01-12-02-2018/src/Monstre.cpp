#include "Monstre.h"

Monstre::Monstre(int pv, int att, int def)
{
    this->att=att;
    this->pv=pv;
    this->def=def;
}

Monstre::~Monstre()
{
    //dtor
}

int Monstre::attaquer()
{
    return rand()*att/RAND_MAX;
}

int Monstre::prendre_dega(int dega)
{
    int frap=(dega-rand()*this->def/RAND_MAX);
    if(frap<=0)
        frap=1;
    this->pv-=frap;
    if(this->pv<=0){
        this->pv=0;
        return (0);
    }
    return 1;
}

void Monstre::afficherMonstre()
{
    printf("Monstre : %dpv",this->pv);
}

void Monstre::afficherMonstreComplet()
{
    printf("Monstre : %dpv %datt %ddef\n",this->pv,this->att,this->def);
}

