#pragma once

#include <iostream>
#include <memory> 
#include <vector>
#include "Light.h"
#include "SecurityCamera.h"
#include "Speaker.h"
#include "Thermostat.h"

using namespace std;

class CRoom {
private:
	int mId;
	string mName;
	vector<unique_ptr<CDevice>> mRoomDevices;
	shared_ptr<CUniqueId> mIdGenerator;

	//Keeps track of view
	int mCurrentDevice;

public:
	//Constructor
	CRoom(shared_ptr<CUniqueId> IdGenerator);

	//Setters
	void SetName();

	//Getters
	string GetName();
	int GetSize();

	//Device in room settings
	void AddDeviceMenu();

	//checks for devices in room
	bool IsEmpty();

	void ActivateAll();
	void DeactivateAll();

	//List of devices in a room
	void PrintRoom(bool isArrows = false);

	//Screen
	void GoToDeviceScreen();
	int RoomScreen();

	~CRoom();
};