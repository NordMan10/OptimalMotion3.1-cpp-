#pragma once
/** Крaткое описание класса
 *
 *
 * File  : ClassName.h
 * Author:
 *
 * Длинное описание класса
 *
 */
#include <map>

 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "CInterval.h"
#include "IMassServiceZone.h"

class CSpecialPlace : public IMassServiceZone
{
private:
	int m_Id = 0;

	std::map<int, CInterval> m_ProcessingIntervals = std::map<int, CInterval>();


public:
	CSpecialPlace(int id);


public:
	int GetId() const;

	void AddAircraftInterval(int aircraftId, CInterval& freeInterval);

	std::shared_ptr<CInterval> GetFreeInterval(CInterval& newInterval);

	void RemoveAircraftInterval(int aircraftId);

	void Reset();
};