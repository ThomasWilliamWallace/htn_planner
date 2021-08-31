#include "PlatformSpecificForPlanner.h"
#include "HTNPlanner.h"

#ifdef TEXT_ONLY_HTN
// Default case

[[noreturn]] void ThrowException(const std::string& errorMessage)
{    
    throw errorMessage;
}

#else
// Unreal engine case

#include "Engine/GameEngine.h"

    // TODO split the platform specific code into separate cpp files. The PlatformSpecific.cpp file can then be included from the appropriate location for different builds.
    // The TEXT_ONLY_HTN flag can then be done away with.

[[noreturn ]] void ThrowException(const std::string& errorMessage)
{    
    FString fStringErrorMessage = FString(errorMessage.c_str());
    UE_LOG(LogTemp, Fatal, TEXT("%s"), *fStringErrorMessage);
    //return;
}

#endif
