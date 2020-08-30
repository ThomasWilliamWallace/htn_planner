#include "HTNWorldState.hpp"
#include <cmath>
#include "AbstractPlayerData.hpp"
#include "AbstractItem.hpp"
#include "pLog.hpp"
#include <sstream>

//***********************************************************
HTNWorldState::HTNWorldState(AbstractPlayerData* playerPtr, PlayerMap& playerMap, std::vector<AbstractItem*>& worldItems,
                             AbstractPlayerData* requester, std::vector<AbstractPlayerData*> attackers, std::vector<AbstractPlayerData*> playersInTheRoom):
    m_ptrToSelf(playerPtr),
    m_health(round(m_ptrToSelf->pStats.getHealth())),
    m_sanity(round(m_ptrToSelf->pStats.getSanity())),
    m_strength(round(m_ptrToSelf->pStats.getStrength())),
    m_agility(round(m_ptrToSelf->pStats.getAgility())),
    m_intelligence(round(m_ptrToSelf->pStats.getIntelligence())),
    m_evading(m_ptrToSelf->lastAction->m_action == Actions::evade),
    m_location(m_ptrToSelf->locationClass.location),
    m_missionClass(playerPtr->missionClass),
    m_requester(requester),
    m_attackers(attackers),
    m_playersInTheRoom(playersInTheRoom)
{
    for (auto &item : worldItems)
    {
        m_items.push_back(std::make_shared<SimItem>(item, item->m_itemType, item->m_locationClass.location, item->m_carryingPlayer));
        if ((m_items.back()->m_carryingPlayer) == m_ptrToSelf)
        {
            m_itemCarriedPtr = m_items.back();
        }
    }
//    std::cout << "constructed HTNWorldState.m_items:\n";
//    for (auto& itemPtr : m_items)
//    {
//        std::cout << itemPtr << "; realItem=" << itemPtr->m_realItem << "\n";
//    }
//    std::cout << "\n";
}

HTNWorldState::HTNWorldState(HTNWorldState &ws2):
    m_ptrToSelf(ws2.m_ptrToSelf),
    m_health(ws2.m_health),
    m_sanity(ws2.m_sanity),
    m_strength(ws2.m_strength),
    m_agility(ws2.m_agility),
    m_intelligence(ws2.m_intelligence),
    m_evading(ws2.m_evading),
    m_location(ws2.m_location),
    m_missionClass(ws2.m_missionClass),
    m_itemCarriedPtr(nullptr),
    m_requester(ws2.m_requester),
    m_attackers(ws2.m_attackers),
    m_playersInTheRoom(ws2.m_playersInTheRoom)
{
    for (auto &item : ws2.m_items)
    {
        m_items.emplace_back(std::make_shared<SimItem>(item.get()));
        m_items.back()->m_realItem = item->m_realItem;
        if (ws2.m_itemCarriedPtr == item)
        {
            m_itemCarriedPtr = m_items.back();
        }
    }
//    std::cout << "COPY constructed HTNWorldState.m_items:\n";
//    for (auto& itemPtr : m_items)
//    {
//        std::cout << itemPtr << "; realItem=" << itemPtr->m_realItem << "\n";
//    }
//    std::cout << "\n";
}

HTNWorldState& HTNWorldState::operator=(const HTNWorldState& ws2)
{
    m_ptrToSelf = ws2.m_ptrToSelf;
    m_health = ws2.m_health;
    m_sanity = ws2.m_sanity;
    m_strength = ws2.m_strength;
    m_agility = ws2.m_agility;
    m_intelligence = ws2.m_intelligence;
    m_evading = ws2.m_evading;
    m_location = ws2.m_location;
    m_itemCarriedPtr = nullptr;
    m_requester = ws2.m_requester;
    m_attackers = ws2.m_attackers;
    m_playersInTheRoom = ws2.m_playersInTheRoom;
    
    m_items.clear();
    for (auto &item : ws2.m_items)
    {
        m_items.emplace_back(std::make_shared<SimItem>(item.get()));
        m_items.back()->m_realItem = item->m_realItem;
        if (ws2.m_itemCarriedPtr == item)
        {
            m_itemCarriedPtr = m_items.back();
        }
    }
//    std::cout << "ASSIGNMENT constructed HTNWorldState.m_items:\n";
//    for (auto& itemPtr : m_items)
//    {
//        std::cout << itemPtr << "; realItem=" << itemPtr->m_realItem << "\n";
//    }
//    std::cout << "\n";
    m_missionClass = ws2.m_missionClass;
    return *this;
}

void HTNWorldState::Print()
{
	std::stringstream ss;
	ss << "HTNWorldState::Print\n";
    ss << "m_health:" << m_health << "\n";
    ss << "m_sanity:" << m_sanity << "\n";
    ss << "m_strength:" << m_strength << "\n";
    ss << "m_agility:" << m_agility << "\n";
    ss << "m_intelligence:" << m_intelligence << "\n";
    ss << "m_evading:" << m_evading << "\n";
    ss << "m_location:" << static_cast<int>(m_location) << "\n";
    ss << "m_ptrToSelf:" << m_ptrToSelf << "\n";
    ss << "m_itemCarriedPtr:" << GetRaw(m_itemCarriedPtr) << "\n";
    ss << "m_requester:" << m_requester << "\n";
    for (auto &simItem : m_items)
    {
		ss << "SimItem: " << simItem->ToString() << " carried by ";
		if (simItem->m_carryingPlayer != nullptr)
		{
			ss << simItem->m_carryingPlayer->m_playerName;
		}
		else
		{
			ss << "NULLPTR";
		}
		ss << " in the " << simItem->m_locationClass.ToString() << " with a link to real item " << simItem << "\n";
    }

    for (auto &p : m_attackers)
    {
        ss << "Being attacked by player " << p->m_playerName << " in the " << LocationToString(m_location) << ".\n";
    }
    for (auto &p : m_playersInTheRoom)
    {
		if (p != nullptr)
			ss << "PlayerData " << p->m_playerName << " is also in the " << LocationToString(m_location) << ".\n";
		else
            throw "ERROR NULL PLAYERDATA VALUE\n";
    }
    ss << "]\n";
    ss << "m_missionClass:" << m_missionClass->MissionName() << "\n";
    pLog(ss);
}

bool HTNWorldState::IsInTheRoom(AbstractPlayerData* playerPtr)
{
    for (auto &p : m_playersInTheRoom)
    {
        if (p == playerPtr)
        {
            return true;
        }
    }
    return false;
}
