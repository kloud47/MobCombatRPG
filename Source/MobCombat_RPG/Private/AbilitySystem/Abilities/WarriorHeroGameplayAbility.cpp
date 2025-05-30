// Priyanshu Shukla All Rights Reserved


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

#include "Characters/WarriorCharacter.h"
#include "Controllers/WarriorHeroController.h"

AWarriorCharacter* UWarriorHeroGameplayAbility::GetWarriorCharacterFromActorInfo()
{
	if (!CachedWarriorCharacter.IsValid())
	{
		CachedWarriorCharacter = Cast<AWarriorCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedWarriorCharacter.IsValid() ? CachedWarriorCharacter.Get() : nullptr;
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetWarriorHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetWarriorCombatComponentFromActorInfo()
{
	return GetWarriorCharacterFromActorInfo()->GetHeroCombatComponent();
}
