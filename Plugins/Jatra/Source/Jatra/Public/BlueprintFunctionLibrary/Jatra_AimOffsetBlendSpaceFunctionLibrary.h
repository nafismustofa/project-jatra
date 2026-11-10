// Copyright 2026 nafismustofa. All Rights Reserved. SPDX-License-Identifier: MIT

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Animation/AimOffsetBlendSpace.h"
#include "Jatra_AimOffsetBlendSpaceFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FAimOffsetBlendSpaceInterpolationTimeSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AimOffsetBlendSpace")
	float HorizontalAxisInterpolationTime = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AimOffsetBlendSpace")
	float VerticalAxisInterpolationTime = 0.0f;
};

UCLASS()
class JATRA_API UJatra_AimOffsetBlendSpaceFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

#pragma region Functions
	
public:
	UFUNCTION(BlueprintCallable, Category = "Animation|AimOffsetBlendSpace")
	static UAimOffsetBlendSpace* CreateRuntimeAimOffsetBlendSpace(UAimOffsetBlendSpace* Source);
	
	UFUNCTION(BlueprintPure, Category = "Animation|AimOffsetBlendSpace")
	static bool GetAimOffsetBlendSpaceInterpolationTime(const UAimOffsetBlendSpace* AimOffsetBlendSpace, FAimOffsetBlendSpaceInterpolationTimeSettings& OutSettings);

	UFUNCTION(BlueprintCallable, Category = "Animation|AimOffsetBlendSpace")
	static bool SetAimOffsetBlendSpaceInterpolationTime(UAimOffsetBlendSpace* AimOffsetBlendSpace, const FAimOffsetBlendSpaceInterpolationTimeSettings& NewSettings);

#pragma endregion
	
};
