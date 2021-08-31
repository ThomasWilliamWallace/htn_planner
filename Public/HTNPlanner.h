#pragma once

#include "HTNNode.h"

class IHTNWorldState;

struct StackNode //represents 'm_htnNode &&' or 'm_htnNode ||'
{
    HTNNodePtr m_htnNode;
    bool m_isOr;
    StackNode(HTNNodePtr htnNode, bool isOr): m_htnNode(htnNode), m_isOr(isOr) {};
};

typedef std::shared_ptr<StackNode> StackNodePtr;
StackNodePtr MakeSharedStackNodePtr(HTNNodePtr htnNodePtr, bool isOr);

HTNPrimitiveList HTN_PLANNER_API HTNIterative(IHTNWorldState & iHTNWorldState, HTNCompound &htnCompound, int searchDepth);
