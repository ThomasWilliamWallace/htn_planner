#pragma once

#include <iostream>
#include <sstream>

constexpr bool c_debug = true;

HTN_PLANNER_API void pLog(std::string logText, bool forcePrint = false);
HTN_PLANNER_API void pLog(std::string logText, std::string logText2, bool forcePrint = false);
HTN_PLANNER_API void pLog(std::stringstream& logStream, bool forcePrint = false);