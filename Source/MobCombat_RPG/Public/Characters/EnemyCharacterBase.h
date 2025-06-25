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

protected:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;
#pragma endregion

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const {return EnemyCombatComponent;}
};
