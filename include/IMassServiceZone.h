#pragma once

/** ��a���� �������� ������
 *
 * File  : IMassServiceZone.h
 * Author:
 *
 * ������� �������� ������
 *
 */
 // SYSTEM INCLUDES
 //

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
# include "CInterval.h"


class IMassServiceZone
{
    virtual CInterval GetFreeInterval(CInterval& newInterval) = 0;

    virtual void AddAircraftInterval(int aircraftId, CInterval& freeInterval) = 0;

    virtual void RemoveAircraftInterval(int aircraftId) = 0;

    virtual void Reset() = 0;
};

