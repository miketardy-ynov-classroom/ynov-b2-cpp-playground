#include <iostream>

using namespace std;


/* Dans un service de photocopie, le tarif de chaque copie est :
0.2euros de la première à la dixième copie.
0.15euros de la onzième à la cinquantième.
0.10 à partir de la cinquante et unième.
*/

int main()
{
    int prixTotal = 0;
    int nbrPhotocopie = 0;
    cout << "Bonjour, vous êtes dans votre service de photocopie préféré" << endl
    << "Combien voulez-vous faire de photocopies ?" << endl;
    cin >> nbrPhotocopie;


    if ( nbrPhotocopie >= 1 && nbrPhotocopie < 11 ){
        prixTotal = nbrPhotocopie*0.2;
    } else if ( nbrPhotocopie >= 11 && nbrPhotocopie <=50) {
        prixTotal = 2+(nbrPhotocopie-10) * 0.15;
    } else if ( nbrPhotocopie >= 51 ) {
        prixTotal = 8+(nbrPhotocopie-50) * 0.1;
    }

    cout << "Vous avez choisi de faire " << nbrPhotocopie << " photocopie(s). Vous devez regler " << prixTotal << " euro(s)" << endl;


    return 0;
}
