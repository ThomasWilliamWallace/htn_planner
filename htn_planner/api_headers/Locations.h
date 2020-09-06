#pragma once

#include <iostream>
#include "PlatformSpecific.hpp"

UENUM(BlueprintType, Blueprintable)
enum class ELocations : uint8
{
    mainHall,
    gym,
    circuitTrack,
    library,
    bedroom,
    LAST = bedroom
};

class LocationClass
{
public:
    ELocations location;
    LocationClass(ELocations l=ELocations::mainHall) : location(l){}
    LocationClass(const LocationClass& l) : location(l.location) {}
    std::string ToString();
};

std::string LocationToString(ELocations location);
ELocations GetRandomLocation();
