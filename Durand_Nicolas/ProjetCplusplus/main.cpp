#include <iostream> //Inclut la biblioth�que input output stream
#include <string> //Inclut la biblioth�que string

using namespace std; //Utilise le namespace Standard

int main()
{
    cout << "Bonjour, que souhaitez vous faire ?" << endl << "1. Hello World" << endl << "2. Bissextile" << endl << "3. Calcul moyenne g�n�rale" << endl << "4. Calculatrice" << endl << "5. Quitter" << endl;

    int choix;
    cin >> choix;

    while (choix > 5 || choix < 1)
    {
        cout << "Merci d'entrer l'un des nombres indiqu�s ici :" << endl << "1. Hello World" << endl << "2. Bissextile" << endl << "3. Calcul moyenne g�n�rale" << endl << "4. Calculatrice" << endl << "5. Quitter" << endl;
        cin >> choix;
    }

    switch (choix)
    {
        case 1: //Hello World !
            {
                string bonjour ("Bonjour tout le monde !"), commentVa ("Comment allez-vous ?"); //Stock des phrases dans des variables
                cout << bonjour << endl << commentVa << endl; //Affiche bonjour dans un terminal windows
            }
        case 2: //D�termine si une ann�e est Bissextile
            {
                cout << "Entrez une ann�e pour savoir si elle est bissextile : ";
                int annee;
                cin >> annee;

                if (annee%4 != 0)
                {
                    cout << "L'ann�e" << annee << " N'EST PAS bissextile.";
                }
                else
                {
                    if (annee%100 == 0)
                    {
                        if (annee%400 != 0)
                        {
                            cout << "l'ann�e " << annee << " N'EST PAS bissextile.";
                        }
                        else
                        {
                            cout << "L'ann�e " << annee << " EST bissextile.";
                        }
                    }
                    else
                    {
                        cout << "L'ann�e " << annee << " EST bissextile.";
                    }
                }
            }
        case 3:  //Calcul de la moyenne g�n�rale (Pour l'instant le IF s'execute m�me si la condition n'est pas remplie)
            {
                cout << "Bonjour et bienvenue dans le programme de calcul de moyenne g�n�rale." << endl << "Combien de notes voulez-vous rentrer ? (Si vous en avez trop mis il suffit de rentrer un co�fficient nul pour ne pas les prendre en compte)" << endl << "Nombre de notes : ";

                int nombreNotes;
                float moyenne = 0;
                float somme = 0;
                cin >> nombreNotes;
                int numeroNote = 1;
                while (numeroNote <= nombreNotes)
                {
                    cout << "Veuillez entrer la note n�" << numeroNote << " : ";
                    float note;
                    cin >> note;

                    cout << "Veuilllez entrer le coefficient correspondant : ";
                    float coeff;
                    cin >> coeff;

                    moyenne += (note*coeff);
                    somme += coeff;
                    cout << moyenne << "   " << somme << endl;

                    cout << "numeroNote : " << numeroNote << endl;
                    cout << "nombreNotes : " << nombreNotes << endl;
                    if (numeroNote = nombreNotes)
                    {
                        moyenne = (moyenne/somme);
                        cout << "Votre moyenne g�n�rale est donc de " << moyenne << "." << endl;
                    }
                    else
                    {

                    }

                    numeroNote ++;
                }

            }
        case 4: //Fonctionne comme une calculatrice (pas termin�e pour l'instant)(PS.: J'aurais peut-�tre oubli� de retirer le "travail en cours" malgr� sa compl�tion)
            {

            }
        case 5: //Quite le programme
            {
                cout << "A bient�t !";
                break;
            }
    }

    return 0;
}
