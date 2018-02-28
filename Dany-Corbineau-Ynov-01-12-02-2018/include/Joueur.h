#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Joueur
{
    public:
        /** Default constructor */
        Joueur(int pv,int att,int def);
        /** Default destructor */
        ~Joueur();
        int attaquer();
        int prendre_dega(int dega);
        void soigner(int soin);
        void afficherPlayer();
        bool isKill();

        int getPv(){return pv;}

    protected:

    private:
        int pv;
        int att;
        int def;
        int xp;

};

#endif // JOUEUR_H
