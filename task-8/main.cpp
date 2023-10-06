#include <iostream>
#include <string>
#include <vector>

using namespace std;

// struct holding the contents of an inventory slot
struct inventory_slot
{
    int item_id = -1;
    string item_description = "Empty";
};

// define descriptions of item IDs
const vector<string> item_descriptions = {"Sword", "Shield", "Bottle", "Golden Rune", "Gun", "Cobblestone"};

// get the name of an item from its id
string item_description_for_id(unsigned int id)
{
    if (id >= item_descriptions.size()) return "";
    return item_descriptions[id];
}

// split a string into a vector<string> at a delimiting char
vector<string> split_str(string str, char c)
{
    vector<string> result;
    size_t offset = 0;
    while (offset < str.length())
    {
        size_t next = str.find(c, offset);
        if (next == -1) next = str.length();
        string segment = str.substr(offset, next-offset);
        if (segment.length() > 0) result.push_back(segment);
        offset = next + 1;
    }
    return result;
}

// class which safely handles the inventory
class inventory_manager
{
private:
    // backing data
    vector<inventory_slot> inventory;

public:
    // set the contents of an inventory slot
    bool set_slot(unsigned int slot, unsigned int item_id)
    {
        if (slot >= inventory.size()) return false;

        inventory[slot].item_id = item_id;
        inventory[slot].item_description = item_description_for_id(item_id);

        return true;
    }

    // make an inventory slot empty
    bool clear_slot(unsigned int slot)
    {
        if (slot >= inventory.size()) return false;

        inventory[slot].item_id = -1;
        inventory[slot].item_description = "Empty";

        return true;
    }

    // get the contents of an inventory slot
    inventory_slot get_slot(unsigned int slot)
    {
        if (slot >= inventory.size()) return inventory_slot{ -2, "" };

        return inventory[slot];
    }

    // set the size of the inventory. clears the inventory in the process
    void set_size(unsigned int size)
    {
        inventory.clear();
        for (int i = 0; i < size; i++)
            inventory.push_back(inventory_slot());
    }

    // get the size of the inventory
    int get_size()
    {
        return inventory.size();
    }
};

void main()
{
    inventory_manager im;

    string result;
    int inventory_size = -1;

    // prompt the user for inventory size, until they behave (input a valid number)
    while (true)
    {
        cout << "Enter the size of the inventory: ";
        cin >> result;
        try
        {
            inventory_size = stoi(result);
        }
        catch (exception e)
        {
            cout << "Enter a number for the inventory size." << endl << endl;
            continue;
        }
        if (inventory_size > 0) break;
        else cout << "The inventory must have at least 1 slot." << endl << endl;
    }

    // init inventory
    im.set_size((unsigned int)inventory_size);
    cout << "Inventory initialised with " << inventory_size << " slots." << endl << endl;

    // start mainloop where we process commands
    bool continue_mainloop = true;
    cin.ignore();
    while (continue_mainloop)
    {
        // get the user input
        string command;
        while (command.size() < 1)
        {
            cout << "> ";
            getline(cin, command);
        }
        cout << endl;

        // split input at space
        vector<string> split_command = split_str(command, ' ');

        // if the user didnt enter a command, try again
        if (split_command.size() == 0)
        {
            cout << "Enter a command." << endl << endl;
            continue;
        }

        // handle view command
        if (split_command[0] == "view")
        {
            // try again if the user didn't give enough arguments
            if (split_command.size() < 2)
            {
                cout << "'view' needs an argument: view <slot to view>" << endl << endl;
                continue;
            }

            // try to get the argument as an int, try again if it isn't valid
            int slot_to_view = stoi(split_command[1]);
            if (slot_to_view < 0)
            {
                cout << "Slot to view must be an index in the inventory." << endl << endl;
                continue;
            }
            inventory_slot slot_data = im.get_slot((unsigned int)slot_to_view);
            if (slot_data.item_id == -2)
            {
                cout << "Slot to view must be an index in the inventory." << endl << endl;
                continue;
            }

            // respond to the command
            cout << "Inventory slot " << slot_to_view << " information:" << endl;
            cout << "  Contents: " << slot_data.item_description << endl << endl;
        }
        // handle show_all command
        else if (split_command[0] == "show_all")
        {
            cout << "Inventory:" << endl;
            for (int i = 0; i < im.get_size(); i++)
            {
                cout << "  Slot " << i << ": " << im.get_slot(i).item_description << endl;
            }
            cout << endl;
        }
        // handle set command
        else if (split_command[0] == "set")
        {
            // if the user didn't give enough arguments, try again
            if (split_command.size() < 3)
            {
                cout << "'set' needs two arguments: set <slot to set> <item id>" << endl << endl;
                continue;
            }

            // try to get the slot and item ids, try again if invalid
            int slot_to_set = stoi(split_command[1]);
            if (slot_to_set < 0)
            {
                cout << "Slot to set must be an index in the inventory." << endl << endl;
                continue;
            }
            int item_id = stoi(split_command[2]);
            if (item_id < 0 || item_id >= item_descriptions.size())
            {
                cout << "Item ID must be within the list of valid item IDs." << endl << endl;
                continue;
            }
            
            // try to set the slot, if it was out of range, try again
            bool result = im.set_slot(slot_to_set, item_id);
            if (!result)
            {
                cout << "Slot to view must be an index in the inventory." << endl << endl;
                continue;
            }
        }
        // handle items command
        else if (split_command[0] == "items")
        {
            for (int i = 0; i < item_descriptions.size(); i++)
            {
                cout << "  " << i << ": " << item_description_for_id(i) << endl;
            }
            cout << endl;
        }
        // handle exit command
        else if (split_command[0] == "exit")
        {
            continue_mainloop = false;
        }
        else
        {
            cout << "Enter a valid command." << endl << endl;
        }
    }
}