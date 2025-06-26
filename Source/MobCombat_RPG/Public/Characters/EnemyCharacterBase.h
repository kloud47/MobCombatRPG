// Priyanshu Shukla All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "EnemyCharacterBase.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class MOBCOMBAT_RPG_API AEnemyCharacterBase : public ABaseCharacter
{
	GENERATED_BODY()
public:
	AEnemyCharacterBase();

	//~ Begin PawnCombatInterface Interface.Add commentMore actions
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End PawnCombatInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;
#pragma endregion

private:
	void InitEnemyStartupData() const;
public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const {return EnemyCombatComponent;}
};
