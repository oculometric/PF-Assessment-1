#include <iostream>
#include <string>

using namespace std;

void main()
{
    float num;
    while (true)
    {
        string num_str;
        cout << "enter a number to square: ";
        cin >> num_str;
        try    
        {
            num = stof(num_str);
            break;
        }
        catch (exception e) {}
    }
    float sqr = num * num;
    cout << num << " squared is " << sqr;
}