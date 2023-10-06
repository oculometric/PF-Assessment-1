#include <iostream>

using namespace std;

void main()
{
    string text;
    cout << "enter some text: ";
    cin >> text;

    int length = text.length();

    // first line of stars
    for (int i = 0; i < length + 4; i++) cout << "*";
    cout << endl;

    // text
    cout << "* " << text << " *" << endl;

    // second line of stars
    for (int i = 0; i < length + 4; i++) cout << "*";
}