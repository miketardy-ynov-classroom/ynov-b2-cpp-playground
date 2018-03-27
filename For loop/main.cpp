#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;

    cin >> a;
    cin >> b;

    for ( a ; a<=b ; a++) {
    int c = a%2;

    if ( c == 0 && a > 9 ) {
        cout << "Even" << endl;
    }
    if ( c != 0 && a > 9 ) {
        cout << "Odd" << endl;
    }
        switch ( a ) {
    case 1:
        cout << "One" << endl;
    break;
    case 2:
        cout << "Two" << endl;
    break;
    case 3:
        cout << "Three" << endl;
    break;
    case 4:
        cout << "Four" << endl;
    break;
    case 5:
        cout << "Five" << endl;
    break;
    case 6:
        cout << "Six" << endl;
    break;
    case 7:
        cout << "Seven" << endl;
    break;
    case 8:
        cout << "Eight" << endl;
    break;
    case 9:
        cout << "Nine" << endl;
    break;
        }
    }
    return 0;
}
