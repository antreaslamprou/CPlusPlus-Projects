#include "SmartHome.h"

CSmartHome::CSmartHome() : mIdGenerator(make_shared<CUniqueId>()), mCurrentRoom(-1)
{
	cout << "Please set a name for your household: " << endl;
	mName = GetString();
}

void CSmartHome::AddRoom()
{
	// Adds dynamically a room entity into the house
	mHouseRooms.push_back(make_unique<CRoom>(mIdGenerator));
}

void CSmartHome::ViewRooms(bool isArrows)
{
	// If there are no rooms to show, inform user
	if (mHouseRooms.size() < 1) {
		cout << endl << SetYellow("IMPORTANT: Household is empty! Create a room first.") << endl;
	}
	else { // Show rooms based on the required format (provided from paramater)
		if (isArrows) {
			for (int i = 0; i < mHouseRooms.size(); i++) {
				cout << i + 1 << "-> " << mHouseRooms.at(i)->GetName() << endl;
			}
		}
		else {
			cout << "Household Rooms: " << endl;
			for (int i = 0; i < mHouseRooms.size(); i++) {
				cout << "(" << i + 1 << ") " << mHouseRooms.at(i)->GetName() << endl;
			}
		}
	}
}

void CSmartHome::GoToRoomScreen()
{
	// If there are no rooms, inform user
	if (mHouseRooms.size() == 0) {
		cout << endl << SetRed("ERROR: Household is empty! Create a room first.") << endl << endl;
		return;
	}
	else if (mHouseRooms.size() == 1) { // If there is one room, go to the room
		mCurrentRoom = 0;
		if (mHouseRooms.at(0)->RoomScreen() == 1) 	mHouseRooms.erase(mHouseRooms.begin()); // Delete room if user selects it from room screen
	}
	else { // If there are multiple rooms, show rooms
		ViewRooms();
		cout << endl << "Please choose a room ( 1 - " << mHouseRooms.size() << " )";
		int roomIndex = GetNumber(1, mHouseRooms.size());
		mCurrentRoom = --roomIndex;
		if (mHouseRooms.at(roomIndex)->RoomScreen() == 1) 	mHouseRooms.erase(mHouseRooms.begin() + mCurrentRoom); // Delete room if user selects it from room screen
	}
}

void CSmartHome::HomeScreen()
{
	// Show smart home
	cout << "*************************" << endl;
	cout << " Welcome to " << mName << "!" << endl;
	cout << "*************************" << endl << endl;
	cout << "Here are your rooms:" << endl;

	// Show rooms
	ViewRooms(true);

	// Show operations
	cout << endl << "What would you like to do:" << endl << endl;
	cout << "(1) Add room" << endl;
	cout << "(2) View room" << endl;
	
	cout << endl << "(0) Exit" << endl;

	// Get user input and do the corresponding operation
	int input = GetNumber(0,2);
	switch (input)
	{
	case 0:
		exitApp = true;
		return;
	case 1:
		AddRoom();
		break;
	case 2:
		GoToRoomScreen();
		break;
	}
}

CSmartHome::~CSmartHome()
{
	if (allowDestructorMessages) cout << endl << SetGreen("SUCCESS: House Deleted!") << endl << endl;
}

