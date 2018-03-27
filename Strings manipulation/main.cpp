#include <iostream>

using namespace std;

int main()
{
    // Déclaration des variables
    string a = "";
    string b = "";


    // Assignation de valeurs
    cout << "Enter the first string" << endl;
    cin >> a;
    cout << "Enter the second string" << endl;
    cin >> b;

    // Taille des strings
    cout << "First string length : " << a.length() << " // Second string length : " << b.length() << endl;

    // Concaténation des strings
    string c = a+b;
    cout << "Let's concatenate these strings to get a bigger one : " << c << endl;

    // Variable de substitution pour swap les deux premiers chars
    char substitute = a[0];
    // Swap de b[0] dans a[0]
    a[0] = b[0];
    // Swap de a[0] dans b[0]
    b[0] = substitute;
    // Affichage en console
    cout << a << " " << b << endl;

    return 0;
}
