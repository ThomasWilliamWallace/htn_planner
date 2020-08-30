#include "PlatformSpecific.hpp"
#include "HTNPlanner.hpp"
#include "AbstractItem.hpp"
#include "AbstractPlayerData.hpp"
#include "Locations.hpp"

HTNPrimitive* GetRaw(HTNPrimitivePtr ptr)
{
    return ptr.get();
}

HTNCompound* GetRaw(HTNCompoundPtr ptr)
{
    return ptr.get();
}

HTNNode* GetRaw(HTNNodePtr ptr)
{
    return ptr.get();
}

HTNMethod* GetRaw(HTNMethodPtr ptr)
{
    return ptr.get();
}

AbstractItem* GetRaw(AbstractItemPtr ptr)
{
    return ptr.get();
}

SimItem* GetRaw(SimItemPtr ptr)
{
    return ptr.get();
}

HTNPrimitivePtr CastNodeToPrimitive(HTNNodePtr htnNodePtr)
{
    return std::static_pointer_cast<HTNPrimitive>(htnNodePtr);
}

HTNCompoundPtr CastNodeToCompound(HTNNodePtr htnNodePtr)
{
    return std::static_pointer_cast<HTNCompound>(htnNodePtr);
}

HTNMethodPtr CastNodeToMethod(HTNNodePtr htnNodePtr)
{
    return std::static_pointer_cast<HTNMethod>(htnNodePtr);
}

StackNodePtr MakeSharedStackNodePtr(HTNNodePtr htnNodePtr, bool isOr)
{
    return std::make_shared<StackNode>(htnNodePtr, isOr);
}

HTNNodePtr MakeShareableCompound(HTNCompound &htnCompound)
{
    return HTNNodePtr(&htnCompound);
}

AbstractItemPtr MakeSharedAbstractItemPtr(EItemType itemType, ELocations location, AbstractPlayerData* carryingPlayer)
{
    return std::make_shared<AbstractItem>(itemType, location, carryingPlayer);
}
