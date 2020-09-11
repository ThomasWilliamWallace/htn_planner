#pragma once

UENUM(BlueprintType, Blueprintable)
enum class EMissions : uint8
{
    noMission,
    increaseStrength,
    increaseAgility,
    increaseIntelligence,
    bringItemToRoom,
    LAST = bringItemToRoom
};