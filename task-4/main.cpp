#include <iostream>

using namespace std;

void main()
{
    string text;
    cout << "enter some text: ";
    cin >> text;

    int length = text.length();

    for (int i = 0; i < length + 4; i++)
        cout << "*";
    cout << endl;
    cout << "* " << text << " *" << endl;
    for (int i = 0; i < length + 4; i++)
        cout << "*";
}