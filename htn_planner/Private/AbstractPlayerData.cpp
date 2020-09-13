#include "AbstractPlayerData.h"
#include "Locations.h"
#include <sstream>
#include "pLog.h"
#include "Constants.h"

std::string CharacterName(AbstractPlayerData* playerPtr)
{
    if (playerPtr == nullptr)
        return "c_empty";
    else
        return playerPtr->m_playerName;
}

void AbstractPlayerData::PrintPlayer()
{
    std::stringstream ss;
    ss << "*** PLAYER " << m_playerName << " ***\n";
    ss << "action=" << action->ToString() << "\n";
    ss << "lastAction=" << lastAction->ToString() << "\n";
    ss << "location=" << locationClass.ToString() << "\n";
    ss << "lastLocation=" << lastLocationClass.ToString() << "\n";
    ss << "attacked=" << BoolToString(attacked) << "\n";
    ss << "narrative=" << narrative << "\n";
    ss << "missionClass=";
    if (missionClass.get() != nullptr) {
        ss << missionClass->MissionNarrative() << "\n";
    }
    else {
        ss << "NULLPTR\n";
    }
    ss << "\n";
    pLog(ss);
    //pStats.PrintStats();
}

// Member variables set in constructor to work with Unreal Engine.
AbstractPlayerData::AbstractPlayerData()
{
    action = std::make_shared<BaseAction>(EActions::useRoom);
    lastAction = std::make_shared<BaseAction>(EActions::useRoom);
    attacked = false;
    narrative = "Narrative not set";
    m_playerName = "No-name";
    missionClass = std::make_shared<AbstractMission>(RandomMission::CreateRandomMission, this);
}