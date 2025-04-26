#include <iostream>
#include "Device.h"

using namespace std;

CDevice::CDevice(shared_ptr<CUniqueId> IdGenerator) : mIdGenerator(IdGenerator)
{
	mId = mIdGenerator->GetNextId();
	SetName();
	SetManufacturer();
}

void CDevice::SetId()
{
	// Inform user of the danger and get changed id from 1 till 9999
	cout << "Please set the new id for your device: " << endl << SetYellow("*** Use with causion ***") << endl;
	int currentId = GetId();
	int inputId = GetNumber(1, 9999);
	
	// If the id is already taken, inform user, show used ids and redo
	while (!mIdGenerator->IsAvailableId(inputId)) {
		cout << SetRed("ERROR: Id is already in use. Please use another id.") << endl << endl;
		cout << "Already used ids: " ;
		for (int id : mIdGenerator->GetUnavailableIdVector()) {
			cout << id << " ";
		}
		cout << endl;

		inputId = GetNumber(1, 9999);
	}

	// When id changes, remove new id from available ids and add old id to available ids
	mIdGenerator->RemoveId(currentId);
	mIdGenerator->AddId(inputId);

	// Set new id as device id
	mId = inputId;
}

void CDevice::SetName()
{
	cout << "Please set the name for your device: " << endl;
	mName = GetString();
}

void CDevice::SetManufacturer()
{
	cout << "Please set the manufacturer for your device: " << endl;
	mManufacturer = GetString();
}

void CDevice::EditDeviceMenu()
{
	// Show the edit menu
	cout << "What do you want to edit:" << endl;
	cout << "(1) Id" << endl;
	cout << "(2) Name" << endl;
	cout << "(3) Manufacturer" << endl;

	// Get user input and do the corresponding operation
	int input = GetNumber(1, 3);
	switch (input)
	{
	case 1:
		SetId();
		break;
	case 2:
		SetName();
		break;
	case 3:
		SetManufacturer();
		break;
	}
}

int CDevice::GetId()
{
	return mId;
}

string CDevice::GetName()
{
	return mName;
}

string CDevice::GetManufacturer()
{
	return mManufacturer;
}

void CDevice::Activate()
{
	if (mStatus) { //Active
		cout << endl << SetRed("ERROR: The device is already activated!") << endl << endl;
	}
	else { //Inactive
		mStatus = true;
		cout << endl << SetGreen("SUCCESS: The device is now activated!") << endl << endl;
	}
	
}

void CDevice::Deactivate()
{
	if (!mStatus) { //Inactive
		cout << endl << SetRed("ERROR: The device is already deactivated!") << endl << endl;
	}
	else { //Active
		mStatus = false;
		cout << endl << SetGreen("SUCCESS: The device is now dectivated!") << endl << endl;
	}
}

bool CDevice::CheckConnection()
{
	return mStatus;
}

string CDevice::CheckConnectionString()
{
	return mStatus ? "Active" : "Inactive";
}

void CDevice::InteractionEvent()
{
	// Check if device is active
	if (CheckConnection()) {
		cout << endl << "This is a base device" << endl << endl;
	}
	else {
		cout << endl << SetRed("ERROR: Please activate your device first!") << endl << endl;
	}
}

void CDevice::ViewInfo()
{
	cout << "ID: " << mId << endl << "Status: " << CheckConnectionString() << endl << "Name: " << mName << endl << "Manufacturer: " << mManufacturer << endl;
}

int CDevice::DeviceScreen()
{
	while (true) {
		// Show device information
		ViewInfo();

		// Show the options
		cout << endl << "(1) Interact with device" << endl;
		cout << "(2) Edit device" << endl;
		cout << "(3) Delete device" << endl;
		cout << "------------------------" << endl << endl;
		cout << "(4) Activate device" << endl;
		cout << "(5) Deactivate device" << endl;

		cout << endl << "(0) Back" << endl;

		// Get user input and do the corresponding operation
		int input = GetNumber(0, 5);
		switch (input)
		{
		case 0:
			return 0;
		case 1:
			InteractionEvent();
			break;
		case 2:
			EditDeviceMenu();
			break;
		case 3:
			return 1;
		case 4:
			Activate();
			break;
		case 5:
			Deactivate();
			break;
		}
	}
}

CDevice::~CDevice()
{
	if (allowDestructorMessages) cout << endl << SetGreen("SUCCESS: Device Deleted!") << endl << endl;
}
