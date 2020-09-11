#include "AbstractAction.h"
#include "AbstractMission.h"

std::string ActionToString(EActions action)
{
    switch(action)
    {
        case EActions::evade:
            return "Evade";
        case EActions::attack:
            return "Attack";
        case EActions::useRoom:
            return "UseRoom";
        case EActions::goToGym:
            return "GoToGym";
        case EActions::goToBedroom:
            return "GoToBedroom";
        case EActions::goToLibrary:
            return "GoToLibrary";
        case EActions::goToMainHall:
            return "GoToMainHall";
        case EActions::goToCircuitTrack:
            return "GoToCircuitTrack";
        case EActions::makeFriends:
            return "MakeFriends";
        case EActions::offerMission:
            return "OfferMission";
        case EActions::pickUpItemByPtr:
            return "PickUpItem";
        case EActions::pickUpItemByType:
            return "PickUpItemByType";
        case EActions::dropItem:
            return "DropItem";
        case EActions::requestItem:
            return "RequestItem";
        case EActions::acceptRequest:
            return "acceptRequest";
        case EActions::declineRequest:
            return "declineRequest";
        case EActions::noAction:
            ThrowException("ERROR NO ACTION");
    }
    ThrowException("ERROR UnrecognisedAction");
}

std::string BaseAction::ToString() {
    return ActionToString(m_action);
}