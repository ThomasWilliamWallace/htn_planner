#include "AbstractAction.hpp"
#include "AbstractMission.hpp"

std::string ActionToString(Actions action)
{
    switch(action)
    {
        case Actions::evade:
            return "Evade";
        case Actions::attack:
            return "Attack";
        case Actions::useRoom:
            return "UseRoom";
        case Actions::goToGym:
            return "GoToGym";
        case Actions::goToBedroom:
            return "GoToBedroom";
        case Actions::goToLibrary:
            return "GoToLibrary";
        case Actions::goToMainHall:
            return "GoToMainHall";
        case Actions::goToCircuitTrack:
            return "GoToCircuitTrack";
        case Actions::makeFriends:
            return "MakeFriends";
        case Actions::offerMission:
            return "OfferMission";
        case Actions::pickUpItemByPtr:
            return "PickUpItem";
        case Actions::pickUpItemByType:
            return "PickUpItemByType";
        case Actions::dropItem:
            return "DropItem";
        case Actions::requestItem:
            return "RequestItem";
        case Actions::acceptRequest:
            return "acceptRequest";
        case Actions::declineRequest:
            return "declineRequest";
        case Actions::noAction:
            throw "ERROR NO ACTION";
    }
    throw "ERROR UnrecognisedAction";
}

std::string BaseAction::ToString() {
    return ActionToString(m_action);
}