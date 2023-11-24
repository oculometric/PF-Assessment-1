#include "main.h"

#include <string>

using namespace std;

void main()
{
    // pick the number
    int target_number = random(1, 100);

    int num_guesses = 0;

    while (true)
    {
        // get input from user
        num_guesses++;
        string str_guess;
        cout << "enter a guess: ";
        getline(cin, str_guess);
        int user_guess;
        try
        {
            user_guess = stoi(str_guess);
        }
        catch (exception e) { continue;  }

        if (user_guess == target_number) break;
        else
        {
            // respond based on how far away the user is
            int difference = abs(user_guess - target_number);
            if (difference >= 50) cout << "freezing";
            else if (difference >= 35) cout << "colder";
            else if (difference >= 25) cout << "cold";
            else if (difference >= 15) cout << "warm";
            else if (difference >= 10) cout << "warmer";
            else if (difference >= 5) cout << "hot";
            else cout << "boiling";
            cout << endl;
        }
    }

    // tell the player they won
    cout << "you got it! the number was " << target_number << endl;
    cout << "it took you " << num_guesses << " guesses" << endl;
}