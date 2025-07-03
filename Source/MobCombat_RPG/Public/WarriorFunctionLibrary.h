// Priyanshu Shukla All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorTypes/WarriorEnumsType.h"
#include "WarriorFunctionLibrary.generated.h"

class UPawnCombatComponent;
struct FGameplayTag;
class UWarriorAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class MOBCOMBAT_RPG_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveGameplayTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName="Does Actor Have Gameplay Tag", ExpandEnumAsExecs="OutConfirmType"))
	static void BP_DoesActorHaveGameplayTag(AActor* InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName="Get Pawn Combat Component From Actor", ExpandEnumAsExecs="OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor,EWarriorValidType& OutValidType);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static bool IsTargetPawnHostile(APawn* QueryPawn,APawn* TargetPawn);
	
};
