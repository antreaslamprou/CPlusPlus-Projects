#include "SecurityCamera.h"

CSecurityCamera::CSecurityCamera(shared_ptr<CUniqueId> IdGenerator) : CDevice(IdGenerator)
{
	SetCameraQuality();
	SetPowerType();
}

void CSecurityCamera::SetCameraQuality()
{
	cout << "Please set the camera quality:" << endl;
	mCameraQuality = GetString();
}

void CSecurityCamera::SetPowerType()
{
	cout << "Please set the power type:" << endl;
	mPowerType = GetString();
}

void CSecurityCamera::EditDeviceMenu()
{
	// Show the edit menu
	cout << "What do you want to edit:" << endl;
	cout << "(1) Id" << endl;
	cout << "(2) Name" << endl;
	cout << "(3) Manufacturer" << endl;
	cout << "(4) Camera Quality" << endl;
	cout << "(5) Power Type" << endl;

	// Get user input and do the corresponding operation
	int input = GetNumber(1, 5);
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
		SetCameraQuality();
		break;
	case 5:
		SetPowerType();
		break;
	}
}

void CSecurityCamera::InteractionEvent()
{
	// Checks if the device is active
	if (CheckConnection()) {
		cout << endl << "Now viewing camera: " << GetName() << endl << endl;
	}
	else {
		cout << endl << SetRed("ERROR: Please activate your device first!") << endl << endl;
	}
}

void CSecurityCamera::ViewInfo()
{
	CDevice::ViewInfo();
	cout << "Camera Quality: " << mCameraQuality << endl << "Power Type: " << mPowerType << endl;
}
