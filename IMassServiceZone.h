#pragma once
class IMassServiceZone
{
    Interval GetFreeInterval(Interval &newInterval);

    void AddAircraftInterval(int aircraftId, Interval &freeInterval);

    void RemoveAircraftInterval(int aircraftId);

    void Reset();
};

