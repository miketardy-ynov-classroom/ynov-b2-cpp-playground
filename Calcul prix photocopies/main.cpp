#include <iostream>

using namespace std;


/* Dans un service de photocopie, le tarif de chaque copie est :
0.2euros de la premi�re � la dixi�me copie.
0.15euros de la onzi�me � la cinquanti�me.
0.10 � partir de la cinquante et uni�me.
*/

int main()
{
    int prixTotal = 0;
    int nbrPhotocopie = 0;
    cout << "Bonjour, vous �tes dans votre service de photocopie pr�f�r�" << endl
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
