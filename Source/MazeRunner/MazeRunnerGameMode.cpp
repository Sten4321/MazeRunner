// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MazeRunnerGameMode.h"
#include "MazeRunnerHUD.h"
#include "MazeRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMazeRunnerGameMode::AMazeRunnerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/Player_BP"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMazeRunnerHUD::StaticClass();
}
