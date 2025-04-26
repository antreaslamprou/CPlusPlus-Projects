#include "Room.h"

CRoom::CRoom(shared_ptr<CUniqueId> IdGenerator) : mIdGenerator(IdGenerator), mCurrentDevice(-1)
{
	// Gets a unique Id, prompts user to give a room name and then shows a success message
	mId = mIdGenerator->GetNexRoomId();
	SetName();
	cout << endl << SetGreen("SUCCESS: Room created!") << endl << endl;
}

void CRoom::SetName()
{
	cout << "Please enter the new room name: " << endl;
	mName = GetString();
}

string CRoom::GetName()
{
	return mName;
}

int CRoom::GetSize()
{
	// Returns the number of devices inside the room
	return mRoomDevices.size();
}

void CRoom::AddDeviceMenu()
{
	// Inform user the reason of input and get the input
	cout << "What kind of device do you want to add:" << endl;
	cout << "(1) Security Camera" << endl;
	cout << "(2) Thermostat" << endl;
	cout << "(3) Smart Speaker" << endl;
	cout << "(4) Smart Light" << endl;

	int input = GetNumber(1, 4);

	// Based on the input, add the equivalent device inside the room vector
	switch (input)
	{
	case 1:
		mRoomDevices.push_back(make_unique<CSecurityCamera>(mIdGenerator));
		break;
	case 2:
		mRoomDevices.push_back(make_unique<CThermostat>(mIdGenerator));
		break;
	case 3:
		mRoomDevices.push_back(make_unique<CSpeaker>(mIdGenerator));
		break;
	case 4:
		mRoomDevices.push_back(make_unique<CLight>(mIdGenerator));
		break;
	}
}

bool CRoom::IsEmpty()
{
	// Check if room has any devices
	return mRoomDevices.size() > 0 ? false : true;
}

void CRoom::ActivateAll()
{
	// If the room has devices
	if (!IsEmpty()) {
		// Checks that at least one device can be activated (it is not already activated)
		bool canOperate = false;
		for (int i = 0; i < mRoomDevices.size(); i++) {
			if (!mRoomDevices.at(i)->CheckConnection()) {
				canOperate = true;
				mRoomDevices.at(i)->Activate();
			}
		}
		system("cls"); //Clear console messages from individual device activation

		// Based on the devices status, inform user of whether the operation is success
		if (canOperate) {
			cout << endl << SetGreen("SUCCESS: All devices in the room have been activated!") << endl << endl;
		}
		else {
			cout << endl << SetRed("ERROR: All devices are already activated!") << endl << endl;
		}
	}
	else { // If room doesnt have devices, inform user
		cout << endl << SetRed("ERROR: Room is empty! Add a device first.") << endl << endl;
	}
}

void CRoom::DeactivateAll()
{
	// If the room has devices
	if (!IsEmpty()) {
		// Checks that at least one device can be deactivated (it is not already deactivated)
		bool canOperate = false;
		for (int i = 0; i < mRoomDevices.size(); i++) {
			if (mRoomDevices.at(i)->CheckConnection()) {
				canOperate = true;
				mRoomDevices.at(i)->Deactivate();
			}
		}
		system("cls"); //Clear console messages from individual device deactivation

		// Based on the devices status, inform user of whether the operation is success
		if (canOperate) {
			cout << endl << SetGreen("SUCCESS: All devices in the room have been deactivated!") << endl << endl;
		}
		else {
			cout << endl << SetRed("ERROR: All devices are already deactivated!") << endl << endl;
		}
	}
	else { // If room doesnt have devices, inform user
		cout << endl << SetRed("ERROR: Room is empty! Add a device first.") << endl << endl;
	}
}

void CRoom::PrintRoom(bool isArrows)
{
	// If the room doenst have devices, inform user
	if (IsEmpty()) {
		cout << endl << SetYellow("IMPORTANT: Room is empty! Add a device first.") << endl;
	}
	else { // If the room has devices, print the devices in the corresponding format (from parameter)
		if (isArrows) {
			for (int i = 0; i < mRoomDevices.size(); i++) {
				string status = "(" + mRoomDevices.at(i)->CheckConnectionString() + ")";
				string statusColored = mRoomDevices.at(i)->CheckConnection() ? SetGreen(status) : SetRed(status);
				cout << i + 1 << " -> " << mRoomDevices.at(i)->GetName() << " " << statusColored << endl;
			}
		}
		else {
			cout << "Room Devices: " << endl;
			for (int i = 0; i < mRoomDevices.size(); i++) {
				cout << "(" << i + 1 << ") " << mRoomDevices.at(i)->GetName() << endl;
			}
		}
	}
}

void CRoom::GoToDeviceScreen()
{
	// If the room doenst have devices, inform user
	if (IsEmpty()) {
		cout << endl << SetRed("ERROR: Room is empty! Add a device first.") << endl << endl;
		return;
	}
	else if (GetSize() == 1) { // If the room has one device, take user to the device screen
		mCurrentDevice = 0;
		if (mRoomDevices.at(0)->DeviceScreen() == 1) mRoomDevices.erase(mRoomDevices.begin()); // Delete device if user selects it from device screen

	}
	else { // If the room has mroe than one device, show room screen
		PrintRoom();
		cout << "Please choose a device ( 1 - " << mRoomDevices.size() << " ):" << endl;
		int deviceIndex = GetNumber(0, GetSize());
		mCurrentDevice = --deviceIndex;
		if (mRoomDevices.at(deviceIndex)->DeviceScreen() == 1) mRoomDevices.erase(mRoomDevices.begin() + mCurrentDevice); // Delete device if user selects it from device screen
	}
}

int CRoom::RoomScreen()
{
	// Show screen till user goes back
	while (true)
	{
		// Show room
		cout << "*************************" << endl;
		cout << " Welcome to " << mName << "!" << endl;
		cout << "*************************" << endl << endl;
		cout << "Here are your devices:" << endl;

		// Show devices
		PrintRoom(true);

		// Show operations
		cout << endl << "What would you like to do:" << endl << endl;
		cout << "(1) Add device" << endl;
		cout << "(2) View device details" << endl;
		cout << "------------------------" << endl << endl;
		cout << "(3) Activate all devices" << endl;
		cout << "(4) Deactivate all devices" << endl;
		cout << "------------------------" << endl << endl;
		cout << "(5) Edit room name" << endl;
		cout << "(6) Delete room" << endl;

		cout << endl << "(0) Back" << endl;

		// Get user input and do the corresponding operation
		int input = GetNumber(0, 6);
		switch (input)
		{
		case 0:
			return 0;
		case 1:
			AddDeviceMenu();
			break;
		case 2:
			GoToDeviceScreen();
			break;
		case 3:
			ActivateAll();
			break;
		case 4:
			DeactivateAll();
			break;
		case 5:
			SetName();
			break;
		case 6:
			return 1;
		}

	}
}

CRoom::~CRoom()
{
	if (allowDestructorMessages) cout << endl << SetGreen("SUCCESS: Room Deleted!") << endl << endl;
}

