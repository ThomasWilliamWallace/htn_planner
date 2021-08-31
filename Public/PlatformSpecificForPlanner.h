#pragma once

#include <memory>
#include <string>
#include "HTNNode.h"

#ifdef TEXT_ONLY_HTN

#define check(X) assert(X)

#else

#define assert(X) check(X)

#endif

// Encapsulated because Unreal Engine uses a different exception system
[[noreturn ]] HTN_PLANNER_API void ThrowException(const std::string& errorMessage);
