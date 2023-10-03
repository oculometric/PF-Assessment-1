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
    cin >> name;

    cout << "hello, " << name << "!" << endl;

    cout << "please enter your clan tag: ";
    cin >> clan_tag;

    cout << "please enter your username: ";
    cin >> username;

    cout << "please enter your age: ";
    string age_str;
    cin >> age_str;
    age = stoi(age_str);

    cout << "player details:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "name       : " << name << endl;
    cout << "username   : [" << clan_tag << "]" << username << endl;
    cout << "age        : " << age << endl;
}