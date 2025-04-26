#include "Light.h"

CLight::CLight(shared_ptr<CUniqueId> IdGenerator) : CDevice(IdGenerator)
{
	SetBrightness();
	SetColor();
}

void CLight::SetBrightness()
{
	cout << "Please set your brightness level (0 - 100):" ;
	mBrightness = GetNumber(0, 100);;
}

void CLight::SetColor()
{
	cout << "Please set your light color (ex. white):" << endl;
	mColor = GetString();
}

void CLight::EditDeviceMenu()
{
	// Show the edit menu
	cout << "What do you want to edit:" << endl;
	cout << "(1) Id" << endl;
	cout << "(2) Name" << endl;
	cout << "(3) Manufacturer" << endl;
	cout << "(4) Brightness" << endl;
	cout << "(5) Color" << endl;
	
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
		SetBrightness();
		break;
	case 5:
		SetColor();
		break;
	}
}

void CLight::InteractionEvent()
{
	// Checks if the device is active
	if (CheckConnection()) {		
		cout << "To change the light brightness please press 1 (one)" << endl;
		cout << "To change the light color please press 2 (two)" << endl;

		short input = 0;

		while (input <= 0 && input > 2) {
			cin >> input;
		}
		
		(input == 1) ? SetBrightness() : SetColor();
	}
	else {
		cout << endl << SetRed("ERROR: Please activate your device first!") << endl << endl;
	}
}

void CLight::ViewInfo()
{
	CDevice::ViewInfo();
	cout << "Brightness Level: " << mBrightness << endl << "Colour: " << mColor << endl;
}
