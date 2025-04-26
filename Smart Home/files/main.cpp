/*
Author: Antreas Lamprou
Student ID: 21070510
*/

#include <iostream>
#include <memory> 
#include "SmartHome.h"

using namespace std;

int main() {
	{
		// Create the house using smart pointers
		unique_ptr<CSmartHome> SmartHome = make_unique<CSmartHome>();

		// If variable is true, the loop will exit and end the application
		while (!exitApp)
		{
			SmartHome->HomeScreen();
		}

		//Clear console, disable destructor messages and show a goodbye message
		system("cls");
		allowDestructorMessages = false;
		cout << endl << SetGreen("***  See you (^_^)/  ***") << endl;
	}
	return 0;
} 