// Priyanshu Shukla All Rights Reserved


#include "Characters/EnemyCharacterBase.h"

#include "WarriorDebugHelper.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "DataAssets/StartupData/DA_StartupEnemyData.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyCharacterBase::AEnemyCharacterBase()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,180.f,0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>("EnemyCombatComponent");
}

void AEnemyCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// if (WarriorAttributeSet && WarriorAbilitySystemComponent)
	// {
	// }
		InitEnemyStartupData();
}

void AEnemyCharacterBase::InitEnemyStartupData() const
{
	if (!CharacterStartupData.IsNull())
	{
		UAssetManager::GetStreamableManager().RequestAsyncLoad(
			CharacterStartupData.ToSoftObjectPath(),
			FStreamableDelegate::CreateLambda(
				[this]()
				{
						if (UDA_StartupEnemyData* LoadedData = Cast<UDA_StartupEnemyData>(CharacterStartupData.Get()))
						{
							LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
							Debug::Print("Enemy startup data Loaded", FColor::Green);
						}
						else
						{ne
							Debug::Print("Failed to load Enemy startup data", FColor::Green);
						}
				})
		);
	}
}
