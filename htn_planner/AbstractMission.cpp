#include "AbstractMission.hpp"
#include "AbstractPlayerData.hpp"
#include "Constants.hpp"
#include <stdexcept>
#include <assert.h>

std::string AbstractMission::MissionName()
{
    switch(m_mission)
    {
        case (Missions::increaseAgility):
            return "increase agility";
        case (Missions::increaseStrength):
            return "increase strength";
        case (Missions::increaseIntelligence):
            return "increase intelligence";
        case (Missions::bringItemToRoom):
            return "bring item to room";
        case (Missions::noMission):
            return "no mission";
    }
    throw "UnrecognisedMission";
}

std::string AbstractMission::MissionNarrative()
{
    switch (m_mission)
    {
        case Missions::noMission:
            return "No Mission\n";
        case Missions::increaseAgility:
            return "Mission: " + m_owner->m_playerName + " must " + MissionName() + " to " + FormatDouble(m_objective) + ". (current=" + FormatDouble(m_owner->pStats.getAgility()) + ")";
        case Missions::increaseStrength:
            return "Mission: " + m_owner->m_playerName + " must " + MissionName() + " to " + FormatDouble(m_objective) + ". (current=" + FormatDouble(m_owner->pStats.getStrength()) + ")";
        case Missions::increaseIntelligence:
            return "Mission: " + m_owner->m_playerName + " must " + MissionName() + " to " + FormatDouble(m_objective) + ". (current=" + FormatDouble(m_owner->pStats.getIntelligence()) + ")";
        case Missions::bringItemToRoom:
            return "Mission: " + m_owner->m_playerName + " must bring a " + ItemTypeToString(m_itemType) + " to the " + m_locationClass.ToString() + ".";
    }
    throw "ERROR: MISSION TYPE NOT RECOGNISED";
}

Missions GetRandomMission()
{
    int random = rand() % 100;
    if (random<25)
        return Missions::increaseStrength;
    else if (random<50)
        return Missions::increaseAgility;
    else if (random<75)
        return Missions::increaseIntelligence;
    else
        return Missions::bringItemToRoom;
}

AbstractMission::AbstractMission(Missions mission, AbstractPlayerData* owner, double objective):
	m_mission(mission),
	m_owner(owner),
	m_objective(objective)
{
    assert(m_owner!=nullptr);
}

AbstractMission::AbstractMission(Missions mission, AbstractPlayerData* owner, EItemType itemType, ELocations location):
	m_mission(mission),
	m_owner(owner),
	m_itemType(itemType),
	m_locationClass(location)
{
    assert(m_owner!=nullptr);
}

AbstractMission::AbstractMission(const AbstractMission& missionClass) :
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
    assert(m_owner!=nullptr);
	//m_mission = Missions::bringItemToRoom;
	//m_itemType = EItemType::ball;
	//m_locationClass = ELocations::mainHall; // GetRandomLocation();
	//return;
	switch (m_mission)
	{
	case Missions::noMission:
		break;
	case Missions::increaseAgility:
		m_objective = m_owner->pStats.getAgility();
		break;
	case Missions::increaseStrength:
		m_objective = m_owner->pStats.getStrength();
		break;
	case Missions::increaseIntelligence:
		m_objective = m_owner->pStats.getIntelligence();
		break;
	case Missions::bringItemToRoom:
		m_itemType = GetRandomItemType();
		m_locationClass = GetRandomLocation();
		break;
	}
	m_objective += 3; //todo ensure that the mission is achievable, ie 100 or below
}

AbstractMission::AbstractMission(RandomMission r, AbstractPlayerData* playerPtr) :
	m_owner(playerPtr)
{
    assert(m_owner!=nullptr);
    m_mission = GetRandomMission();
    switch (m_mission)
    {
        case Missions::noMission:
            return;
        case Missions::increaseAgility:
            m_objective = playerPtr->pStats.getAgility();
            break;
        case Missions::increaseStrength:
            m_objective = playerPtr->pStats.getStrength();
            break;
        case Missions::increaseIntelligence:
            m_objective = playerPtr->pStats.getIntelligence();
            break;
        case Missions::bringItemToRoom:
            m_itemType = GetRandomItemType();
            m_locationClass = GetRandomLocation();
            return;
	default:
	    throw std::invalid_argument("Selected an invalid mission type.");
    }
    m_objective += 3; //todo ensure that the mission is achievable, ie 100 or below
}