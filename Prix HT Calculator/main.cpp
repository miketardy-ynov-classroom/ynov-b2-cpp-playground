#include <iostream>

using namespace std;

int main()
{
    float prixArticle = 0;
    float TVAPercentage = 0;

    cout << "Entrer le prix de votre article en euro" << endl;
    cin >> prixArticle;
    cout << "Entrer la TVA correspondante" << endl;
    cin >> TVAPercentage;
    float TVANumber = TVAPercentage/100;

    cout << "Le prix HT de votre article est de " << prixArticle-prixArticle*TVANumber << " €" << endl;
    return 0;
}
