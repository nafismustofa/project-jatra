// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Jatra_ChooserFunctionLibrary.generated.h"

class UChooserTable;

UCLASS()
class JATRA_API UJatra_ChooserFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

#pragma region Functions
	
public:
	UFUNCTION(BlueprintCallable, Category = "Animation", meta = (DefaultToSelf = "ContextObject", DeterminesOutputType = "ObjectClass", BlueprintThreadSafe))
	static TArray<UObject*> EvaluateChooserDynamic(UObject* ContextObject, UChooserTable* ChooserTable);
	
#pragma endregion
};
