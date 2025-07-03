// Priyanshu Shukla All Rights Reserved


#include "AbilitySystem/WarriorAbilitySystemComponent.h"

#include "WarriorDebugHelper.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
		TryActivateAbility(AbilitySpec.Handle);// calls the activate ability event in Blueprints
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

void  UWarriorAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel,
		TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
	if (InDefaultWeaponAbilities.IsEmpty()) return;

	for (const FWarriorHeroAbilitySet& AbilitySet: InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		
		OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UWarriorAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(
	TArray<FGameplayAbilitySpecHandle>& InSpecHandleToRemove)
{
	if (InSpecHandleToRemove.IsEmpty()) return;

	for (const FGameplayAbilitySpecHandle& AbilitySpecHandle : InSpecHandleToRemove)
	{
		if (AbilitySpecHandle.IsValid())
		{
			ClearAbility(AbilitySpecHandle);
		}
	}
	InSpecHandleToRemove.Empty();// Empties the array:
}

bool UWarriorAbilitySystemComponent::TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate)
{
	check(AbilityTagToActivate.IsValid());

	TArray<FGameplayAbilitySpec*> FoundAbilitySpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(AbilityTagToActivate.GetSingleTagContainer(), FoundAbilitySpecs);

	if (!FoundAbilitySpecs.IsEmpty())
	{
		const int32 RandomAbilityIndex = FMath::RandRange(0, FoundAbilitySpecs.Num() - 1);
		FGameplayAbilitySpec* SpecToActivate = FoundAbilitySpecs[RandomAbilityIndex];

		check(SpecToActivate);

		if (!SpecToActivate->IsActive())
		{
			return TryActivateAbility(SpecToActivate->Handle);
		}
	}
	return false;
}
