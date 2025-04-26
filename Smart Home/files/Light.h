#pragma once

#include <iostream>
#include "Device.h"

using namespace std;

class CLight : public CDevice {
private:
	unsigned short mBrightness; //0-100
	string mColor;

protected:
	//Setters
	void SetBrightness();
	void SetColor();

public:
	//Constructor
	CLight(shared_ptr<CUniqueId> IdGenerator);

	//Details
	void EditDeviceMenu() override;
	void InteractionEvent() override;
	void ViewInfo() override;
};