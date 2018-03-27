#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter a digit between 1 & 9" << endl;
    int n = 0;
    cin >> n;

    if ( n < 1) {
        cout << "Less than one" << endl;
    }

    if ( n > 9) {
        cout << "Greater than nine" << endl;
    }
    switch ( n ) {
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
    default:
        cout << "This digit is not between 1 & 9 !!" << endl;
    break;
}
    return 0;
}
