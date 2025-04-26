#pragma once

#include <iostream>
#include <memory> 
#include "Utility.h"
#include "UniqueId.h"

using namespace std;

class CDevice {
private:
	int mId;
	string mName;
	string mManufacturer;
	shared_ptr<CUniqueId> mIdGenerator;

	bool mStatus = false; //True if active

protected:
	//Setters
	void SetId();
	void SetName();
	void SetManufacturer();

public:
	//Constructor
	CDevice(shared_ptr<CUniqueId> IdGenerator);

	//Getters
	int GetId();
	string GetName();
	string GetManufacturer();

	//Status related
	void Activate();
	void Deactivate();
	bool CheckConnection();
	string CheckConnectionString();

	// Details
	virtual void EditDeviceMenu();
	virtual	void InteractionEvent();
	virtual void ViewInfo();

	//Screen
	int DeviceScreen();

	~CDevice();
};