// Priyanshu Shukla All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AWarriorHeroWeapon;
class AWarriorWeaponBase;
/**
 * 
 */
UCLASS()
class MOBCOMBAT_RPG_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCurrentEquippedWeapon() const;
	
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	float GetHeroCurrentEquippedWeaponDamageAtLevel(int32 InLevel) const;

	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor) override;
};
