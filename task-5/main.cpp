#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// capitalise the next text character of a sentence after a sentence end
string sentence_caps(string str)
{
	string output;
	bool capitalise_next = true;
	for (char c : str)
	{
		if (capitalise_next && c != ' ')
		{
			// capitalise this character, clear flag
			output += toupper(c);
			capitalise_next = false;
		}
		else
		{
			// decapitalise this character
			output += tolower(c);

			// if at the end of a sentence, set capitalise flag
			if (c == '.' || c == '!' || c == '?') capitalise_next = true;
		}
	}

	return output;
}

// capitalise whole string, char by char
string all_upper(string str)
{
	string output;
	for (char c : str)
	{
		output += toupper(c);
	}
	return output;
}

// decapitalise whole string, char by char
string all_lower(string str)
{
	string output;
	for (char c : str)
	{
		output += tolower(c);
	}
	return output;
}

void main()
{
	cout << "enter some text: ";
	string text;
	getline(cin, text);

	cout << "Sentence case: " << sentence_caps(text) << endl;
	cout << "Lower case: " << all_lower(text) << endl;
	cout << "Upper case: " << all_upper(text) << endl;
}