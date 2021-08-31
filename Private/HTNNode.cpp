#include "HTNNode.h"
#include "pLog.h"
#include "PlatformSpecificForPlanner.h"
#include "IHTNWorldState.h"

//*******************************************************************
HTNNode::HTNNode(std::string name, HTNType htnType) : m_name(name), m_HTNType(htnType) {}

std::string HTNNode::ToString()
{
    return m_name;
}

//*******************************************************************
HTNPrimitive::HTNPrimitive(std::string name, int type): HTNNode(name, HTNType::Primitive), m_type(type) {}

bool HTNPrimitive::Preconditions(IHTNWorldState const& iHTNWorldState)
{
    ThrowException("HTNPrimitive::Preconditions not defined");
    return true;
}

void HTNPrimitive::Effect(IHTNWorldState &iHTNWorldState)
{
    ThrowException("HTNPrimitive::Effect not defined");
    return;
}

//*******************************************************************
HTNCompound::HTNCompound(std::string name): HTNNode(name, HTNType::Compound), m_alreadyCreatedMethods(false) {}

void HTNCompound::AddMethod(HTNMethod* htnMethod)
{
    m_methods.push_back(HTNMethodPtr(htnMethod));
}

HTNMethodList& HTNCompound::GetMethods(IHTNWorldState const& iHTNWorldState)
{
    if (!m_alreadyCreatedMethods)
    {
        CreateMethods(iHTNWorldState);
        m_alreadyCreatedMethods = true;
    }
    return m_methods;
}

//*******************************************************************
HTNMethod::HTNMethod(std::string name): HTNNode(name, HTNType::Method), m_alreadyCreatedTasks(false) {}

bool HTNMethod::Preconditions(IHTNWorldState const& iHTNWorldState)
{
    ThrowException("HTNMethod::Preconditions not defined");
    return true; //Note: Preconditions should always use the Preconditions iHTNWorldState parameter, rather than the constructor m_iHTNWorldState parameter.
}

void HTNMethod::AddTask(HTNPrimitive* htnPrimitive)
{
    m_nodeList.push_back(HTNPrimitivePtr(htnPrimitive));
}

void HTNMethod::AddTask(HTNCompound* htnCompound)
{
    m_nodeList.push_back(HTNCompoundPtr(htnCompound));
}

HTNNodeList& HTNMethod::GetTasks(IHTNWorldState const& iHTNWorldState)
{
    if (!m_alreadyCreatedTasks)
    {
        CreateTasks(iHTNWorldState);
        m_alreadyCreatedTasks = true;
    }
    return m_nodeList;
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

HTNNodePtr MakeShareableCompound(HTNCompound& htnCompound)
{
    return HTNNodePtr(&htnCompound);
}
