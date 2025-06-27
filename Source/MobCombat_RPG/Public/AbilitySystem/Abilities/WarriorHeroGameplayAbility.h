// Priyanshu Shukla All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class AWarriorHeroController;
class AWarriorCharacter;
/**
 * 
 */
UCLASS()
class MOBCOMBAT_RPG_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorCharacter* GetWarriorCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroController* GetWarriorHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetWarriorCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(const TSubclassOf<UGameplayEffect>& EffectClass,float InWeaponBaseDamage,FGameplayTag InCurrentAttackTypeTag,int32 InCachedComboCount);

private:
	TWeakObjectPtr<AWarriorCharacter> CachedWarriorCharacter;
	TWeakObjectPtr<AWarriorHeroController> CachedWarriorHeroController;
};
