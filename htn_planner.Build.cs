// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class htn_planner : ModuleRules
{
	public htn_planner(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "Engine" });

		bUseRTTI = true;

		PublicIncludePaths.Add("C:/Users/triha/OneDrive/Documents/Unreal Projects/HardTime2 4.26/Source/htn_planner/Public");
		PublicIncludePaths.Add("C:/Users/triha/OneDrive/Documents/Unreal Projects/HardTime2 4.26/Source/htn_planner/Private");
		PrivateIncludePaths.Add("C:/Users/triha/OneDrive/Documents/Unreal Projects/HardTime2 4.26/Source/htn_planner/Public");
		PrivateIncludePaths.Add("C:/Users/triha/OneDrive/Documents/Unreal Projects/HardTime2 4.26/Source/htn_planner/Private");
	}
}
