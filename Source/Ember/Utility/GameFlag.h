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