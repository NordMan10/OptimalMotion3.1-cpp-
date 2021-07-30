#pragma once

/** Крaткое описание класса
 *
 * File  : IMassServiceZone.h
 * Author:
 *
 * Длинное описание класса
 *
 */
 // SYSTEM INCLUDES
 //
#include <memory>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
# include "CInterval.h"


class IMassServiceZone
{
    virtual std::shared_ptr<CInterval> GetFreeInterval(CInterval& newInterval) = 0;

    virtual void AddAircraftInterval(int aircraftId, CInterval& freeInterval) = 0;

    virtual void RemoveAircraftInterval(int aircraftId) = 0;

    virtual void Reset() = 0;
};

