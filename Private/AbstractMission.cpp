#include "AbstractMission.h"
#include "AbstractPlayerData.h"
#include "Constants.h"
#include <stdexcept>
#include <assert.h>

std::string AbstractMission::MissionName()
{
    switch(m_mission)
    {
        case (EMissions::increaseAgility):
            return "increase agility";
        case (EMissions::increaseStrength):
            return "increase strength";
        case (EMissions::increaseIntelligence):
            return "increase intelligence";
        case (EMissions::bringItemToRoom):
            return "bring item to room";
        case (EMissions::noMission):
            return "no mission";
    }
    ThrowException("UnrecognisedMission");
}

std::string AbstractMission::MissionNarrative()
{
    switch (m_mission)
    {
        case EMissions::noMission:
            return "No Mission\n";
        case EMissions::increaseAgility:
            return "Mission: " + m_owner->m_playerName + " must " + MissionName() + " to " + FormatDouble(m_objective) + ". (current=" + FormatDouble(m_owner->pStats.getAgility()) + ")";
        case EMissions::increaseStrength:
            return "Mission: " + m_owner->m_playerName + " must " + MissionName() + " to " + FormatDouble(m_objective) + ". (current=" + FormatDouble(m_owner->pStats.getStrength()) + ")";
        case EMissions::increaseIntelligence:
            return "Mission: " + m_owner->m_playerName + " must " + MissionName() + " to " + FormatDouble(m_objective) + ". (current=" + FormatDouble(m_owner->pStats.getIntelligence()) + ")";
        case EMissions::bringItemToRoom:
            return "Mission: " + m_owner->m_playerName + " must bring a " + ItemTypeToString(m_itemType) + " to the " + m_locationClass.ToString() + ".";
    }
    ThrowException("ERROR: MISSION TYPE NOT RECOGNISED");
}

EMissions GetRandomMission()
{
    int random = rand() % 100;
    if (random<25)
        return EMissions::increaseStrength;
    else if (random<50)
        return EMissions::increaseAgility;
    else if (random<75)
        return EMissions::increaseIntelligence;
    else
        return EMissions::bringItemToRoom;
}

AbstractMission::AbstractMission(EMissions mission, AbstractPlayerData* owner, double objective):
	m_mission(mission),
	m_owner(owner),
	m_objective(objective)
{
    assert(m_owner!=nullptr);
}

AbstractMission::AbstractMission(EMissions mission, AbstractPlayerData* owner, EItemType itemType, ELocations location):
	m_mission(mission),
	m_owner(owner),
	m_itemType(itemType),
	m_locationClass(location)
{
    assert(m_owner!=nullptr);
}

AbstractMission::AbstractMission(const AbstractMission& missionClass):
    m_mission(missionClass.m_mission),
    m_owner(missionClass.m_owner),
    m_objective(missionClass.m_objective),
    m_itemType(missionClass.m_itemType),
    m_locationClass(missionClass.m_locationClass)
{
    assert(m_owner!=nullptr);
}

AbstractMission::AbstractMission(AbstractPlayerData* owner):
	m_mission(GetRandomMission()),
	m_owner(owner)
{
    m_mission = EMissions::bringItemToRoom;
    m_itemType = EItemType::ball;
    m_locationClass = LocationClass(ELocations::gym);
    return;
    assert(m_owner != nullptr);
    switch (m_mission)
    {
    case EMissions::noMission:
        return;
    case EMissions::increaseAgility:
        m_objective = owner->pStats.getAgility();
        break;
    case EMissions::increaseStrength:
        m_objective = owner->pStats.getStrength();
        break;
    case EMissions::increaseIntelligence:
        m_objective = owner->pStats.getIntelligence();
        break;
    case EMissions::bringItemToRoom:
        m_itemType = GetRandomItemType();
        m_locationClass = GetRandomLocation();
        return;
    default:
        ThrowException("Selected an invalid mission type.");
    }
    m_objective += 3; //todo ensure that the mission is achievable, ie 100 or below
}

AbstractMission::AbstractMission(RandomMission r, AbstractPlayerData* playerPtr):
    AbstractMission(playerPtr)
{}