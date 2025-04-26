#pragma once

#include <iostream>
#include <string>
#include <limits> 

using namespace std;

// Global Variables
extern bool allowDestructorMessages;
extern bool exitApp;

// Get Input
int GetNumber(int min, int max);
string GetString();

// Change Output Color
string SetRed(string text);
string SetGreen(string text);
string SetYellow(string text);
