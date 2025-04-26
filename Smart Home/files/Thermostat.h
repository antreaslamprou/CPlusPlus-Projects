#pragma once

#include <iostream>
#include "Device.h"

using namespace std;

class CThermostat : public CDevice {
private:
	unsigned short mTemperature;

protected:
	//Setters
	void SetTemperature();

public:
	//Constructor
	CThermostat(shared_ptr<CUniqueId> IdGenerator);

	//Details
	void EditDeviceMenu() override;
	void InteractionEvent() override;
	void ViewInfo() override;
};