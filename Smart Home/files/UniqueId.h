#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CUniqueId
{
private:
	// Automated Id Variables
	int mDeviceId;
	int mRoomId;
	vector<int> mTakenIds;

public:
	// Contsructor
	CUniqueId();

	// Device Related Ids
	int GetNextId();
	void AddId(int id);
	void RemoveId(int id);
	bool IsAvailableId(int id);

	// Getters Ids
	int GetAvailableId();
	vector<int> GetUnavailableIdVector();

	// Room Related Ids
	int GetNexRoomId();

};

