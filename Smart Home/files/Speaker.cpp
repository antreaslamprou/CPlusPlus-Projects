#include "Speaker.h"

CSpeaker::CSpeaker(shared_ptr<CUniqueId> IdGenerator) : CDevice(IdGenerator)
{
	SetVolume();
}

void CSpeaker::SetVolume()
{
	cout << "Please set the volume level (0-100):";
	mVolume = GetNumber(0, 100);
}

void CSpeaker::EditDeviceMenu()
{
	// Show the edit menu
	cout << "What do you want to edit:" << endl;
	cout << "(1) Id" << endl;
	cout << "(2) Name" << endl;
	cout << "(3) Manufacturer" << endl;
	cout << "(4) Volume" << endl;

	// Get user input and do the corresponding operation
	int input = GetNumber(1, 4);
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
	case 4:
		SetVolume();
		break;
	}
}

void CSpeaker::InteractionEvent()
{
	// Checks if the device is active
	if (CheckConnection()) {
		SetVolume();
	}
	else {
		cout << endl << SetRed("ERROR: Please activate your device first!") << endl << endl;
	}
}

void CSpeaker::ViewInfo()
{
	CDevice::ViewInfo();
	cout << "Volume Level: " << mVolume << endl;
}
