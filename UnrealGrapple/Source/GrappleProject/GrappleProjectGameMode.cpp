// Copyright Epic Games, Inc. All Rights Reserved.

#include "GrappleProjectGameMode.h"
#include "GrappleProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGrappleProjectGameMode::AGrappleProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
