#pragma once

#include <vector>
#include <iostream>
#include "Locations.hpp"
#include "Constants.hpp"
#include "PlatformSpecific.hpp"
#include "AbstractMission.hpp"
#include "AbstractItem.hpp"
#include "AbstractPlayerData.hpp"

class HTNWorldState
{
public:
    AbstractPlayerData* m_ptrToSelf;
    int m_health;
    int m_sanity;
    int m_strength;
    int m_agility;
    int m_intelligence;
    int m_evading;
    ELocations m_location;
    std::shared_ptr<AbstractMission> m_missionClass;
    std::vector< std::shared_ptr<SimItem> > m_items;
    std::vector< std::shared_ptr<SimItem> > m_itemsToKeep; //items added to this list will not be surrendered if requested.
    std::shared_ptr<SimItem> m_itemCarriedPtr;
    AbstractPlayerData* m_requester; // Pointer to the player who is requesting the currently carried item.
    std::vector<AbstractPlayerData*> m_attackers;
    std::vector< AbstractPlayerData* > m_playersInTheRoom;
    bool IsInTheRoom(AbstractPlayerData* playerPtr);
    HTNWorldState(HTNWorldState &ws2);
    HTNWorldState(AbstractPlayerData* playerPtr, PlayerMap& playerMap, std::vector<AbstractItem*>& worldItems,
                  AbstractPlayerData* requester, std::vector<AbstractPlayerData*> attackers, std::vector<AbstractPlayerData*> playersInTheRoom);
    HTNWorldState& operator=(const HTNWorldState& ws2);
    void Print();
};
