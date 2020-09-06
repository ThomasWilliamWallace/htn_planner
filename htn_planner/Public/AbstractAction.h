#pragma once

#include <vector>
#include <iostream>
#include "PlatformSpecific.h"

class AbstractMission;

UENUM(BlueprintType, Blueprintable)
enum class Actions
{
    attack,
    useRoom,
    goToLibrary,
    goToGym,
    goToCircuitTrack,
    goToBedroom,
    goToMainHall,
    evade,
    makeFriends,
    offerMission,
    pickUpItemByPtr,
    pickUpItemByType,
    dropItem,
    requestItem,
    acceptRequest,
    declineRequest,
    noAction, // serves as a flag for any unset actions
    LAST = noAction
};

std::string ActionToString(Actions action);

class BaseAction
{
public:
    BaseAction(Actions action): m_action(action) {};
    virtual std::string ToString();
    Actions m_action;
};

class AttackAction : public BaseAction
{
public:
    AttackAction(AbstractPlayerData* targetPlayer): BaseAction(Actions::attack), m_targetPlayer(targetPlayer) {};
    AbstractPlayerData* m_targetPlayer;
};

class PickUpItemByPtrAction : public BaseAction
{
public:
    PickUpItemByPtrAction(AbstractItem* itemFocusPtr): BaseAction(Actions::pickUpItemByPtr), m_itemFocusPtr(itemFocusPtr) {};
    AbstractItem* m_itemFocusPtr;
};

class PickUpItemByTypeAction : public BaseAction
{
public:
    PickUpItemByTypeAction(EItemType itemType): BaseAction(Actions::pickUpItemByType), m_itemType(itemType) {};
    EItemType m_itemType;
};

class RequestItemAction : public BaseAction
{
public:
    RequestItemAction(AbstractPlayerData* targetPlayer): BaseAction(Actions::requestItem), m_targetPlayer(targetPlayer) {};
    AbstractPlayerData* m_targetPlayer;
};

class MakeFriendsAction : public BaseAction
{
public:
    MakeFriendsAction(AbstractPlayerData* targetPlayer): BaseAction(Actions::makeFriends), m_targetPlayer(targetPlayer) {};
    AbstractPlayerData* m_targetPlayer;
};

class OfferMissionAction : public BaseAction
{
public:
    OfferMissionAction(AbstractPlayerData* targetPlayer, std::shared_ptr<AbstractMission> offeredMission): BaseAction(Actions::offerMission), m_targetPlayer(targetPlayer), m_offeredMission(offeredMission) {};
    AbstractPlayerData* m_targetPlayer;
    std::shared_ptr<AbstractMission> m_offeredMission;
};
