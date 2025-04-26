#include "Utility.h"

// Show destructors messages by default
bool allowDestructorMessages = true;

// Run app (when this is true, app wil exit)
bool exitApp = false;

int GetNumber(int min, int max)
{	
	int input;

	// While incorrect input show error and wait for new input
	while (true) {
		// Get input
		cout << endl << "> ";
		cin >> input;
		// Check if valid
		if (cin.fail() || (input < min || input > max)) {
			cout << endl << "\033[31mERROR: Please enter a valid option between " << min << " and " << max  << "\033[0m" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else { //If valid exit loop
			break; 
		}
	}
	system("cls"); //Clear console
	return input;
}

string GetString()
{
	// Get input
	string input;
	cout << "> ";
	getline(cin, input);
	
	// While empty input show error and wait for new input
	while (input.empty())
	{
		getline(cin, input);
	}
	system("cls"); //Clear console
	return input;
}

string SetRed(string text)
{
	// Gets the string and adds the stringcode on beggining and end to make the string appear red
	string output = "\033[31m" + text + "\033[0m";
	return output;
}

string SetGreen(string text)
{
	// Gets the string and adds the stringcode on beggining and end to make the string appear green
	string output = "\033[32m" + text + "\033[0m";
	return output;
}

string SetYellow(string text)
{
	// Gets the string and adds the stringcode on beggining and end to make the string appear yellow
	string output = "\033[33m" + text + "\033[0m";
	return output;
}