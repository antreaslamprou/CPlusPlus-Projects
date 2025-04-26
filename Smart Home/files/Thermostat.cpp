#include "Thermostat.h"

CThermostat::CThermostat(shared_ptr<CUniqueId> IdGenerator) : CDevice(IdGenerator)
{
	SetTemperature();
}

void CThermostat::SetTemperature()
{
	cout << "Please set the targeted temperature (16-32):";
	mTemperature = GetNumber(16, 32);
}

void CThermostat::EditDeviceMenu()
{
	// Show the edit menu
	cout << "What do you want to edit:" << endl;
	cout << "(1) Id" << endl;
	cout << "(2) Name" << endl;
	cout << "(3) Manufacturer" << endl;
	cout << "(4) Temperature" << endl;
	
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
		SetTemperature();
		break;
	}
}

void CThermostat::InteractionEvent()
{
	// Checks if the device is active
	if (CheckConnection()) {
		SetTemperature();
	}
	else {
		cout << endl << SetRed("ERROR: Please activate your device first!") << endl << endl;
	}
}

void CThermostat::ViewInfo()
{
	CDevice::ViewInfo();
	cout << "Target Temperature: " << mTemperature << endl;
}