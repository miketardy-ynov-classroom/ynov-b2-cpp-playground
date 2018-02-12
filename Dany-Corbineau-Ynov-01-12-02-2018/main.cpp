#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Joueur.h"
#include "Monstre.h"

using namespace std;

int main(int argc,char *argv[])
{
    srand(time(NULL));

    Joueur *j1=new Joueur(100,30,20);
    Monstre monstre[]={Monstre(500,2,10),
                        Monstre(100,2,10),
                        Monstre(10000,1,1)};

    for(int j=0;j<3;j++)
    {
        printf("Joueur contre monstre %d : ",j+1);
        monstre[j].afficherMonstreComplet();
        printf("\n\n");
        while(1){
            if(monstre[j].prendre_dega(j1->attaquer())==0){
                break;
            }
            if(j1->prendre_dega(monstre[j].attaquer())==0){
                break;
            }

            j1->afficherPlayer();
            printf("  ---  ");
            monstre[j].afficherMonstre();
            printf("\n");
        }
        if(j1->isKill()){
            printf("Le joueur à perdu contre le monstre %d\n\n",j+1);
            break;
        }
        else{
            printf("Le joueur à battu le monstre %d\n\n",j+1);
            j1->soigner(j1->getPv());
        }
    }

    delete j1;
    return 0;
}
