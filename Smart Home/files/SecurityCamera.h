#pragma once

#include <iostream>
#include "Device.h"

using namespace std;

class CSecurityCamera : public CDevice {
private:
	string mCameraQuality;
	string mPowerType;

protected:
	//Setters
	void SetCameraQuality();
	void SetPowerType();

public:
	//Constructor
	CSecurityCamera(shared_ptr<CUniqueId> IdGenerator);

	// Details
	void EditDeviceMenu() override;
	void InteractionEvent() override;
	void ViewInfo() override;
};