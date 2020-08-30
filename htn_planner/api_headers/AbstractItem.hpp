#pragma once

#include "Locations.hpp"
#include "PlatformSpecific.hpp"

class AbstractPlayerData;

enum class EItemType : uint8
{
	assaultRifle,
	ball,
	barbell,
	bat,
	baton,
	bottle,
	brick,
	broom,
	cigarette,
	cleaver,
	comb,
	dumbbell,
	dynamite,
	extinguisher,
	hammer,
	knife,
	mirror,
	pipe,
	pistol,
	plank,
	poolCue,
	rock,
	scissors,
	screw,
	sword,
	syringe
};

std::string ItemTypeToString(EItemType itemType);
EItemType GetRandomItemType();

class AbstractItem
{
public:
    EItemType m_itemType;
    LocationClass m_locationClass;
    AbstractPlayerData* m_carryingPlayer;
    
    AbstractItem(EItemType itemE, ELocations location, AbstractPlayerData* carryingPlayer=nullptr): m_itemType(itemE), m_locationClass(location), m_carryingPlayer(carryingPlayer) {};
    
    virtual ~AbstractItem() = default;
    
    std::string ToString();
};

// TODO currently the planning crashes because we don't distinguish between items in the HTN planning world simulation, and items in the 'real' text world.
// The HTN planning then inteferes with the 'real' items, by changing the item m_owner attribute.
// Solution: add a class which can represent the HTN world simulation items, SimItem. It has a pointer back to the real item it is based on.
// An AbstractSimItem base class should be added here, so that HTNPrimitives.cpp can access it. 
// But it needs to be extended in 'text' and 'unreal' code Item.hpp, to have it's pointer towards either 'text' items or 'unreal' actor items.

// TODO CHECK THE GET() CALLS

class SimItem : public AbstractItem
{
public:
    SimItem(AbstractItem* realItem):
        AbstractItem(realItem->m_itemType, realItem->m_locationClass.location, realItem->m_carryingPlayer),
        m_realItem(realItem)
    {};
    SimItem(AbstractItem* realItem, EItemType itemE, ELocations location, AbstractPlayerData* carryingPlayer=nullptr):
        AbstractItem(itemE, location, carryingPlayer),
        m_realItem(realItem)
    {};
    SimItem(SimItem& item):
        SimItem(item.m_realItem, item.m_itemType, item.m_locationClass.location, item.m_carryingPlayer)
    {};
    
    AbstractItem* m_realItem;
};