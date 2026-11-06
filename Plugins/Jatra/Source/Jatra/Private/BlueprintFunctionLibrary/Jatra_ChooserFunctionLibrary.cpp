// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFunctionLibrary/Jatra_ChooserFunctionLibrary.h"
#include "Chooser.h"
#include "ChooserFunctionLibrary.h"

TArray<UObject*> UJatra_ChooserFunctionLibrary::EvaluateChooserDynamic(UObject* ContextObject, UChooserTable* ChooserTable)
{
	if (!ContextObject || !ChooserTable)
	{
		return {};
	}
	
	return UChooserFunctionLibrary::EvaluateChooserMulti(ContextObject, ChooserTable, UObject::StaticClass());
}

