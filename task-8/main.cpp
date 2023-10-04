#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct inventory_slot
{
    int item_id = -1;
    string item_description = "Empty";
};

vector<string> item_descriptions = {"Sword", "Shield", "Bottle", "Golden Rune", "Gun", "Cobblestone"};

string item_description_for_id(unsigned int id)
{
    if (id >= item_descriptions.size()) return "";
    return item_descriptions[id];
}

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

class inventory_manager
{
private:
    vector<inventory_slot> inventory;

public:
    bool set_slot(unsigned int slot, unsigned int item_id)
    {
        if (slot >= inventory.size()) return false;

        inventory[slot].item_id = item_id;
        inventory[slot].item_description = item_description_for_id(item_id);

        return true;
    }

    bool clear_slot(unsigned int slot)
    {
        if (slot >= inventory.size()) return false;

        inventory[slot].item_id = -1;
        inventory[slot].item_description = "Empty";

        return true;
    }

    inventory_slot get_slot(unsigned int slot)
    {
        if (slot >= inventory.size()) return inventory_slot{ -2, "" };

        return inventory[slot];
    }

    void set_size(unsigned int size)
    {
        inventory.clear();
        for (int i = 0; i < size; i++)
            inventory.push_back(inventory_slot());
    }

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

    im.set_size((unsigned int)inventory_size);
    cout << "Inventory initialised with " << inventory_size << " slots." << endl << endl;

    bool continue_mainloop = true;
    cin.ignore();
    while (continue_mainloop)
    {
        string command;
        while (command.size() < 1)
        {
            cout << "> ";
            getline(cin, command);
        }
        cout << endl;

        vector<string> split_command = split_str(command, ' ');

        if (split_command.size() == 0)
        {
            cout << "Enter a command." << endl << endl;
            continue;
        }

        if (split_command[0] == "view")
        {
            if (split_command.size() < 2)
            {
                cout << "'view' needs an argument: view <slot to view>" << endl << endl;
                continue;
            }

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
            cout << "Inventory slot " << slot_to_view << " information:" << endl;
            cout << "  Contents: " << slot_data.item_description << endl << endl;
        }
        else if (split_command[0] == "show_all")
        {
            cout << "Inventory:" << endl;
            for (int i = 0; i < im.get_size(); i++)
            {
                cout << "  Slot " << i << ": " << im.get_slot(i).item_description << endl;
            }
            cout << endl;
        }
        else if (split_command[0] == "set")
        {
            if (split_command.size() < 3)
            {
                cout << "'set' needs two arguments: set <slot to set> <item id>" << endl << endl;
                continue;
            }
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
            bool result = im.set_slot(slot_to_set, item_id);
            if (!result)
            {
                cout << "Slot to view must be an index in the inventory." << endl << endl;
                continue;
            }
        }
        else if (split_command[0] == "items")
        {
            for (int i = 0; i < item_descriptions.size(); i++)
            {
                cout << "  " << i << ": " << item_description_for_id(i) << endl;
            }
            cout << endl;
        }
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