#pragma once

#include <vector>
#include <deque>
#include <iostream>


class IHTNWorldState;

class HTNNode;
class HTNPrimitive;
class HTNCompound;
class HTNMethod;
typedef std::shared_ptr<HTNNode> HTNNodePtr;
typedef std::vector< HTNNodePtr > HTNNodeList;
typedef std::shared_ptr<HTNPrimitive> HTNPrimitivePtr;
typedef std::deque< HTNPrimitivePtr > HTNPrimitiveList;
typedef std::shared_ptr<HTNCompound> HTNCompoundPtr;
typedef std::vector< HTNCompoundPtr > HTNCompoundList;
typedef std::shared_ptr<HTNMethod> HTNMethodPtr;
typedef std::vector< HTNMethodPtr > HTNMethodList;

enum class HTNType
{
    Primitive,
    Compound,
    Method
};

class HTN_PLANNER_API HTNNode
{
public:
    std::string m_name;
    HTNType m_HTNType;
    HTNNode(std::string name, HTNType htnType);
    virtual ~HTNNode() = default;
    std::string ToString();
};

class HTN_PLANNER_API HTNPrimitive : public HTNNode
{
public:
    const int m_type;  // Store an enum representing the corresponding Unreal Engine action. Can't have an enum type, as this htn_planner is compiled before Unreal, and so the enum is not accessible.
    // In future, the actual Unreal enum file could be included from htn_planner. And, when compiling for terminal, an alternate enum file could be included.
    HTNPrimitive(std::string name, int type);
    virtual bool Preconditions(IHTNWorldState const& iHTNWorldState); //must be true before this task can occur in the plan.
    virtual void Effect(IHTNWorldState & iHTNWorldState); //simplified, predicted effect of taking this action. Will be applied to the simulated world during planning.
    virtual ~HTNPrimitive() override = default;
};

class HTN_PLANNER_API HTNCompound : public HTNNode
{
private:
    bool m_alreadyCreatedMethods;
protected:
    virtual void CreateMethods(IHTNWorldState const& iHTNWorldState) = 0;
public:
    HTNMethodList m_methods;  //Vector of methods. Each method is a vector of tasks.
    HTNCompound(std::string name);
    void AddMethod(HTNMethod* htnMethod);
    HTNMethodList& GetMethods(IHTNWorldState const& iHTNWorldState);
    virtual ~HTNCompound() override = default;
};

//list of either primitive or compound tasks
class HTN_PLANNER_API HTNMethod : public HTNNode
{
private:
    bool m_alreadyCreatedTasks;
protected:
    virtual void CreateTasks(IHTNWorldState const& iHTNWorldState) = 0; //constructs tasks
public:
    HTNNodeList m_nodeList; //To complete this HTNCompound task, all the tasks in a method must be completed. All in this list are Primitive Tasks or Compound Tasks.
    HTNMethod(std::string name);
    virtual bool Preconditions(IHTNWorldState const& iHTNWorldState); //must be true before this task can occur in the plan.
    HTNNodeList& GetTasks(IHTNWorldState const& iHTNWorldState); //returns tasks
    void AddTask(HTNPrimitive* htnPrimitive);
    void AddTask(HTNCompound* htnCompound);
    virtual ~HTNMethod() override = default;
};

// Convenience functions wrapping up an casting method that works in both in standard C++ and Unreal C++
HTNPrimitivePtr HTN_PLANNER_API CastNodeToPrimitive(HTNNodePtr htnNodePtr);
HTNCompoundPtr HTN_PLANNER_API CastNodeToCompound(HTNNodePtr htnNodePtr);
HTNMethodPtr HTN_PLANNER_API CastNodeToMethod(HTNNodePtr htnNodePtr);

HTNNodePtr HTN_PLANNER_API MakeShareableCompound(HTNCompound& htnCompound);
