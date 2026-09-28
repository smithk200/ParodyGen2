GoldenrodCity_DepartmentStore_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore3_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Rocker::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FRocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Goldenrod_DepartmentStore_3F_EventScript_ClerkLeft::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, Goldenrod_DepartmentStore_3F_EventScript_ClerkDidntObtain3rdBadge
	message gText_HowMayIServeYou
	waitmessage
	pokemart Goldenrod_DepartmentStore_3F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Goldenrod_DepartmentStore_3F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Goldenrod_DepartmentStore_3F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Goldenrod_DepartmentStore_3F_Pokemart_StatBoosters:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

	.align 2
Goldenrod_DepartmentStore_3F_Pokemart_Evolution_Stones:
	.2byte ITEM_FIRE_STONE
    .2byte ITEM_WATER_STONE
    .2byte ITEM_THUNDER_STONE
    .2byte ITEM_LEAF_STONE 
    .2byte ITEM_ICE_STONE
    .2byte ITEM_SUN_STONE
    .2byte ITEM_MOON_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_DUSK_STONE
    .2byte ITEM_DAWN_STONE
	pokemartlistend

Goldenrod_DepartmentStore_3F_EventScript_ClerkDidntObtain3rdBadge:
	msgbox gText_Goldenrod_DepartmentStore_3F_ClerkDidntObtain3rdBadge, MSGBOX_DEFAULT
	release
	end 

GoldenrodDeptStore_Text_3FSuperNerd:
    .string "I, I, I'm really impatient!\p"
    .string "I use cocaine in battle to speed up\n"
    .string "my Pokémon.$"

GoldenrodDeptStore_Text_3FRocker:
    .string "Hey! When you battle, do you use X\n"
    .string "Special?\p"
    .string "It's awesome. It really jacks up\n"
    .string "Special Attack!$"

GoldenrodDeptStore_Text_3FDirectory:
    .string "For Victory Seekers\p"
    .string "3F Battle Collection$"

gText_Goldenrod_DepartmentStore_3F_ClerkDidntObtain3rdBadge:
	.string "I only sell my items to worthy\n"
	.string "Trainers.\p"
	.string "What do I mean by “worthy”?\p"
	.string "I mean someone who has gained\n"
	.string "Goldenrod City's badge\p"
	.string "Come back later once you've gotten\n"
	.string "the Genericbadge.$"