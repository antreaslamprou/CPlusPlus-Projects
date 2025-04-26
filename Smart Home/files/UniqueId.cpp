#include "UniqueId.h"

CUniqueId::CUniqueId()
{
	// Define the id variables
	mDeviceId = 0;
	mRoomId = 0;
}


int CUniqueId::GetNextId()
{
	// Find the next available id
	while (!IsAvailableId(mDeviceId + 1)) {
		mDeviceId++;
	}

	// Make that id unavailable and return it
	AddId(mDeviceId + 1);
	return ++mDeviceId;
}

void CUniqueId::AddId(int id)
{
	// Adds an id to the unavailable ids vector
	mTakenIds.push_back(id);
}

void CUniqueId::RemoveId(int id)
{
	//Find the element in the vector
	auto index = find(mTakenIds.begin(), mTakenIds.end(), id);

	//If found, remove it
	if (index != mTakenIds.end()) {
		mTakenIds.erase(index);
	}
}

bool CUniqueId::IsAvailableId(int id)
{
	// Checks if an id is available
	return count(mTakenIds.begin(), mTakenIds.end(), id) > 0 ? false : true;
}

int CUniqueId::GetAvailableId()
{
	// Returns the current available id
	return mDeviceId;
}

vector<int> CUniqueId::GetUnavailableIdVector()
{
	// Returns a vector with the unavailable ids
	return mTakenIds;
}

int CUniqueId::GetNexRoomId()
{
	// Returns the next available room id 
	return ++mRoomId;
}
