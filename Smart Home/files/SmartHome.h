#pragma once

#include <iostream>
#include <cstdlib>
#include "Room.h"

using namespace std;

class CSmartHome {
private:
	string mName;
	vector<unique_ptr<CRoom>> mHouseRooms;
	shared_ptr<CUniqueId> mIdGenerator;

	//Keeps track of view
	int mCurrentRoom;

protected:
	void AddRoom();

public:
	//Constructor
	CSmartHome();

	void ViewRooms(bool isArrows = false);
	
	//Screens
	void GoToRoomScreen();
	void HomeScreen();

	// Destructor
	~CSmartHome();
};