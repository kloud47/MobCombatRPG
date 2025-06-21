// Priyanshu Shukla All Rights Reserved

#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGamePlayTags
{
	/** Input Tags **/
	MOBCOMBAT_RPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	MOBCOMBAT_RPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	MOBCOMBAT_RPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	MOBCOMBAT_RPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	/** Player Tags **/
	MOBCOMBAT_RPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	MOBCOMBAT_RPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	MOBCOMBAT_RPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
}