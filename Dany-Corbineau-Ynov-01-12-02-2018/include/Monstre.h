#ifndef MONSTRE_H
#define MONSTRE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
class Monstre
{
    public:
        /** Default constructor */
        Monstre(int pv, int att, int def);
        /** Default destructor */
        ~Monstre();

        int attaquer();
        int prendre_dega(int dega);
        void afficherMonstre();
        void afficherMonstreComplet();

    protected:

    private:
        int pv;
        int att;
        int def;
};

#endif // MONSTRE_H
