#include <iostream>
#include <string>

using namespace std;

void main()
{
    string name;
    string username;
    string clan_tag;
    int age;

    cout << "please enter your name: ";
    getline(cin, name);
    cout << "hello, " << name << "!" << endl;

    cout << "please enter your clan tag: ";
    getline(cin, clan_tag);

    cout << "please enter your username: ";
    getline(cin, username);

    while (true)
    {
        cout << "please enter your age: ";
        string age_str;
        cin >> age_str;
        try
        {
            age = stoi(age_str);
            break;
        }
        catch (exception e) {}
    }

    cout << "player details:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "name       : " << name << endl;
    cout << "username   : [" << clan_tag << "]" << username << endl;
    cout << "age        : " << age << endl;
}