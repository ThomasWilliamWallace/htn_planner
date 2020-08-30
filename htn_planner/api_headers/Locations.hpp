#pragma once

#include <iostream>
#include "PlatformSpecific.hpp"

enum class ELocations : uint8
{
    mainHall,
    gym,
    circuitTrack,
    library,
    bedroom
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