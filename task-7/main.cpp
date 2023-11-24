#include <iostream>
#include <string>
#include <vector>

using namespace std;

// define the possible classes of character
const vector<string> character_classes = { "Samauri", "Archer", "Knight", "Wizard" };

// struct to store the character
struct character_details
{
    string name;
    int class_id;
};

// output a description of the player's character details
void describe_character(character_details* player_character)
{
    cout << "Player details:" << endl;
    cout << "  Name  - " << player_character->name << endl;
    cout << "  Class - " << character_classes[player_character->class_id] << endl;
}

void main()
{   
    int character_class_index = -1;
    // get user input until the user picks a valid class
    while (true)
    {
        cout << "Select a class from the list below, by entering its number: " << endl;
        for (int i = 0; i < character_classes.size(); i++)
            cout << i+1 << ": " << character_classes[i] << endl;
        cout << endl;
        cout << "> ";

        string str;
        cin >> str;
        try
        {
            character_class_index = stoi(str) - 1;
        }
        catch (exception e) { continue; }

        if (character_class_index >= character_classes.size() || character_class_index < 0)
        {
            cout << "Invalid selection. Please enter a choice between 1 and " << character_classes.size() << " inclusive." << endl;
        }
        else
        {
            cout << "You selected " << character_classes[character_class_index] << endl;
            break;
        }
    }

    cout << endl;

    // get the player name from the user
    cout << "Please enter your name: ";
    string name;
    cin.ignore();
    getline(cin, name);

    // insert these values into a struct
    character_details* player_character = new character_details();
    player_character->name = name;
    player_character->class_id = character_class_index;

    cout << endl;

    // describe the character
    describe_character(player_character);
}