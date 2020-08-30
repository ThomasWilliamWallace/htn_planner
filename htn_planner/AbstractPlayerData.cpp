#include "AbstractPlayerData.hpp"
#include "Locations.hpp"
#include <sstream>
#include "pLog.hpp"
#include "Constants.hpp"

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
    ss << "missionClass=" << missionClass->MissionNarrative() << "\n";
    ss << "\n";
    pLog(ss, true);
    pStats.PrintStats();
}
