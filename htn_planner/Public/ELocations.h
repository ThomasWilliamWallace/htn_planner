#pragma once

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