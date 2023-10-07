#include <iostream>

using namespace std;

void boxify_text(string text, int padding)
{
    int length = text.length() + 2 + (2 * padding);

    // first line of stars
    for (int i = 0; i < length; i++) cout << "*";
    cout << endl;

    // text
    cout << "*";
    for (int i = 0; i < padding; i++) cout << " ";
    cout << text;
    for (int i = 0; i < padding; i++) cout << " ";
    cout << "*" << endl;

    // second line of stars
    for (int i = 0; i < length; i++) cout << "*";
}

void main()
{
    string text;
    cout << "enter some text: ";
    cin >> text;

    int padding;
    cout << "how much padding? ";
    cin >> padding;

    boxify_text(text, padding);
    
}