#pragma once

#include <iostream>
#include "Device.h"

using namespace std;

class CSpeaker : public CDevice {
private:
	unsigned short mVolume; //0-100

protected:
	//Setters
	void SetVolume();

public:
	//Constructor
	CSpeaker(shared_ptr<CUniqueId> IdGenerator);

	//Details
	void EditDeviceMenu() override;
	void InteractionEvent() override;
	void ViewInfo() override;
};