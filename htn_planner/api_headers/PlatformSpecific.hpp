#pragma once
#include <memory>

class HTNNode;
class HTNPrimitive;
class HTNCompound;
class HTNMethod;
struct StackNode;
class AbstractItem;
class SimItem;
class AbstractPlayerData;
class Relationship;

typedef std::shared_ptr<HTNPrimitive> HTNPrimitivePtr;
typedef std::shared_ptr<HTNCompound> HTNCompoundPtr;
typedef std::shared_ptr<HTNNode> HTNNodePtr;
typedef std::shared_ptr<HTNMethod> HTNMethodPtr;
typedef std::shared_ptr<StackNode> StackNodePtr;

#include <map>

typedef std::shared_ptr<AbstractItem> AbstractItemPtr;
typedef std::shared_ptr<SimItem> SimItemPtr;

typedef uint8_t uint8;

typedef std::map<int, AbstractPlayerData*> PlayerMap;
typedef std::pair<int, AbstractPlayerData*> IntPlayerPair;
typedef std::map<int, Relationship*> RelMap;
typedef std::pair<int, Relationship*> IntRelPair;

template <typename Iterator>
int GetKey(Iterator &iterator)
{
	return iterator.first;
};

template <typename Iterator>
AbstractPlayerData* GetPlayer(Iterator &iterator)
{
	return iterator.second;
};

template <typename Iterator>
Relationship* GetRel(Iterator &iterator)
{
	return iterator.second;
};

template <typename Container>
bool Contains(Container &container, int key)
{
	return container.find(key) != container.end();
};

template <typename Container, typename Element>
void Add(Container &container, int addKey, Element addElem)
{
	container.insert(typename Container::value_type(addKey, addElem));
};

template <typename Container>
void Remove(Container &container, int removeKey)
{
	container.erase(removeKey);
};

template <typename Container, typename Iterator>
void RemoveCurrent(Container &container, Iterator iter)
{
	iter = container.erase(iter);
};

enum class EItemType : uint8;
enum class ELocations : uint8;

HTNPrimitive* GetRaw(HTNPrimitivePtr ptr);
HTNCompound* GetRaw(HTNCompoundPtr ptr);
HTNNode* GetRaw(HTNNodePtr ptr);
HTNMethod* GetRaw(HTNMethodPtr ptr);
AbstractItem* GetRaw(AbstractItemPtr ptr);
SimItem* GetRaw(SimItemPtr ptr);

HTNPrimitivePtr CastNodeToPrimitive(HTNNodePtr htnNodePtr);
HTNCompoundPtr CastNodeToCompound(HTNNodePtr htnNodePtr);
HTNMethodPtr CastNodeToMethod(HTNNodePtr htnNodePtr);

StackNodePtr MakeSharedStackNodePtr(HTNNodePtr htnNodePtr, bool isOr);
HTNNodePtr MakeShareableCompound(HTNCompound &htnCompound);
AbstractItemPtr MakeSharedAbstractItemPtr(EItemType itemType, ELocations location, AbstractPlayerData* carryingPlayer);

