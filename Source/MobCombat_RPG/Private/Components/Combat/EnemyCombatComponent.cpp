// Priyanshu Shukla All Rights Reserved


#include "Components/Combat/EnemyCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorGamePlayTags.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) return;

	OverlappedActors.AddUnique(HitActor);

	//TODO:: Implement block check
    bool bIsValidBlock = false;
    
    const bool bIsPlayerBlocking = false;
    const bool bIsMyAttackUnblockable = false;

	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
    {
    	//TODO::check if the block is valid
    }

	FGameplayEventData EventDataPayload;
	EventDataPayload.Instigator = GetOwningPawn();
	EventDataPayload.Target = HitActor;

	if (bIsValidBlock)
	{
		//TODO::Handle successful block
	} else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			GetOwningPawn(),
			WarriorGamePlayTags::Shared_Event_MeleeHit,
			EventDataPayload
		);
	}
}
