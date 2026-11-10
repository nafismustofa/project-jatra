// Copyright 2026 nafismustofa. All Rights Reserved. SPDX-License-Identifier: MIT

#include "BlueprintFunctionLibrary/Jatra_AimOffsetBlendSpaceFunctionLibrary.h"
#include "UObject/Package.h"

UAimOffsetBlendSpace* UJatra_AimOffsetBlendSpaceFunctionLibrary::CreateRuntimeAimOffsetBlendSpace(UAimOffsetBlendSpace* Source)
{
	if (!Source) return nullptr;
	
	UAimOffsetBlendSpace* Copy = DuplicateObject<UAimOffsetBlendSpace>(Source, GetTransientPackage());

	if (Copy) Copy->SetFlags(RF_Transient);

	return Copy;
}

bool UJatra_AimOffsetBlendSpaceFunctionLibrary::GetAimOffsetBlendSpaceInterpolationTime(const UAimOffsetBlendSpace* AimOffsetBlendSpace, FAimOffsetBlendSpaceInterpolationTimeSettings& OutSettings)
{
	if (!AimOffsetBlendSpace) return false;

	const FInterpolationParameter& HorizontalParam = AimOffsetBlendSpace->InterpolationParam[0];
	const FInterpolationParameter& VerticalParam = AimOffsetBlendSpace->InterpolationParam[1];
	
	OutSettings.HorizontalAxisInterpolationTime = HorizontalParam.InterpolationTime;
	OutSettings.VerticalAxisInterpolationTime = VerticalParam.InterpolationTime;
	
	return true;

}

bool UJatra_AimOffsetBlendSpaceFunctionLibrary::SetAimOffsetBlendSpaceInterpolationTime(UAimOffsetBlendSpace* AimOffsetBlendSpace, const FAimOffsetBlendSpaceInterpolationTimeSettings& NewSettings)
{
	if (!AimOffsetBlendSpace) return false;

	FInterpolationParameter& HorizontalParam = AimOffsetBlendSpace->InterpolationParam[0];
	FInterpolationParameter& VerticalParam = AimOffsetBlendSpace->InterpolationParam[1];
	
	HorizontalParam.InterpolationTime = NewSettings.HorizontalAxisInterpolationTime;
	VerticalParam.InterpolationTime = NewSettings.VerticalAxisInterpolationTime;
	
	return true;
}
