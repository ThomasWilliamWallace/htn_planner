#pragma once

#include <iostream>
#include "AbstractItem.hpp"

class AbstractPlayerData;

enum class Missions
{
    noMission,
    increaseStrength,
    increaseAgility,
    increaseIntelligence,
    bringItemToRoom
};

//https://stackoverflow.com/questions/7010827/named-constructor-idiom-and-new-operator
enum class RandomMission{
    CreateRandomMission
};

class AbstractMission
{
public:
    AbstractMission(AbstractPlayerData* owner);
    AbstractMission(RandomMission r, AbstractPlayerData* playerPtr);
    AbstractMission(Missions mission, AbstractPlayerData* owner, double objective);
    AbstractMission(Missions mission, AbstractPlayerData* owner, EItemType itemE, ELocations location);
    AbstractMission(const AbstractMission& missionClass);
    
    Missions m_mission;
    AbstractPlayerData* m_owner;
    double m_objective; //objective for stat increase missions
    EItemType m_itemType;
    LocationClass m_locationClass;
    
    std::string MissionName();
    virtual ~AbstractMission() = default;
    std::string MissionNarrative();
};

Missions GetRandomMission();