// Priyanshu Shukla All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UDataAsset_StartupDataBase;
class UMyAttributeSet;
class UWarriorAbilitySystemComponent;

UCLASS()
class MOBCOMBAT_RPG_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface Interface.

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UMyAttributeSet* WarriorAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartupDataBase> CharacterStartupData;
	
public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const {return WarriorAbilitySystemComponent;}
	FORCEINLINE UMyAttributeSet* GetWarriorAttributeSet() const {return WarriorAttributeSet;}
};
