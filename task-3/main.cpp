#include <iostream>
#include <string>

using namespace std;

void main()
{
    string num_str;
    cout << "enter a number to square: ";
    cin >> num_str;

    float num = stof(num_str);

    float sqr = num * num;
    cout << num << " squared is " << sqr;
}