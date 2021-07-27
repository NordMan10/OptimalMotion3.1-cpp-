#pragma once
class IMassServiceZone
{
    virtual Interval GetFreeInterval(Interval& newInterval) = 0;

    virtual void AddAircraftInterval(int aircraftId, Interval& freeInterval) = 0;

    virtual void RemoveAircraftInterval(int aircraftId) = 0;

    virtual void Reset() = 0;
};

