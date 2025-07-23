#pragma once

#include "CoreMinimal.h"

enum class EWeatherType
{
	Clear UMETA(DisplayName = "CLEAR"),
	Snow UMETA(DisplayName = "SNOW"),
	Storm UMETA(DisplayName = "STORM"),
};

enum class EWorldTimeState
{
	Morning UMETA(DisplayName = "MORNING"),
	Afternoon UMETA(DisplayName = "AFTERNOON"),
	Evening UMETA(DisplayName = "EVENING"),
	Night UMETA(DisplayName = "NIGHT"),
};

enum class ESpeedType
{
	Walk UMETA(DisplayName = "Walk"),
	Run UMETA(DisplayName = "Run"),
	Sprint UMETA(DisplayName = "Sprint"),
	Max UMETA(DisplayName = "Max")
};