#include <iostream>
#include <string>

using namespace std;

void boxify_text(string text, int padding)
{
    int length = text.length() + 2 + (2 * padding);

    // first line of stars
    for (int i = 0; i < length; i++) cout << "*";
    cout << endl;

    // padding lines
    string padding_line = "*";
    for (int i = 0; i < length-2; i++) padding_line += " ";
    padding_line += "*";

    for (int i = 0; i < padding; i++) cout << padding_line << endl;

    // text
    cout << "*";
    for (int i = 0; i < padding; i++) cout << " ";
    cout << text;
    for (int i = 0; i < padding; i++) cout << " ";
    cout << "*" << endl;

    // padding lines
    for (int i = 0; i < padding; i++) cout << padding_line << endl;

    // second line of stars
    for (int i = 0; i < length; i++) cout << "*";
}

void main()
{
    string text;
    cout << "enter some text: ";
    getline(cin, text);

    int padding;
    cout << "how much padding? ";
    cin >> padding;

    boxify_text(text, padding);
    
}