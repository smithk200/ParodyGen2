EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	setflag FLAG_HIDE_PETER_GRIFFIN_EVER_GRANDE
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
	setobjectxyperm LOCALID_LEAGUE_GUARD_1, 9, 2
	setobjectxyperm LOCALID_LEAGUE_GUARD_2, 10, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LEAGUE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	pokemartlistend

EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard1::
	setvar VAR_TEMP_2, 1
	goto EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard
	end

EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard2::
	setvar VAR_TEMP_2, 2
	goto EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard
	end

@ The door guards only check for FLAG_GARBAGEFLAG because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE17_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	goto_if_unset FLAG_BADGE18_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	goto_if_unset FLAG_BADGE19_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	goto_if_unset FLAG_BADGE20_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	goto_if_unset FLAG_BADGE21_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	goto_if_unset FLAG_BADGE22_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	goto_if_unset FLAG_BADGE23_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	goto_if_unset FLAG_BADGE24_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement LOCALID_LEAGUE_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement LOCALID_LEAGUE_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_OBTAIN_BADGE
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	playbgm MUS_FAMILY_GUY_THEME, FALSE
	clearflag FLAG_HIDE_PETER_GRIFFIN_EVER_GRANDE
	addobject LOCALID_PETER_GRIFFIN_EVER_GRANDE
	call_if_eq VAR_TEMP_2, 1, EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_EnterLeft
	call_if_eq VAR_TEMP_2, 2, EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_EnterRight
	delay 30
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_Battle
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_Battle::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_PeterGriffin_Intro, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_PETER_GRIFFIN_EVER_GRANDE, EverGrandeCity_PokemonLeague_1F_Text_PeterGriffin_Defeat
	goto EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_Defeated
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_Defeated::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_PeterGriffin_Defeated, MSGBOX_AUTOCLOSE
	call EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_Exit
	setflag FLAG_HIDE_PETER_GRIFFIN_EVER_GRANDE
	setflag FLAG_ENTERED_ELITE_FOUR
	removeobject LOCALID_PETER_GRIFFIN_EVER_GRANDE
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_1
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_2
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_EnterRight::
	applymovement LOCALID_PETER_GRIFFIN_EVER_GRANDE, EverGrandeCity_PokemonLeague_1F_Movement_PeterGriffin_Enter_Right
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_EnterLeft::
	applymovement LOCALID_PETER_GRIFFIN_EVER_GRANDE, EverGrandeCity_PokemonLeague_1F_Movement_PeterGriffin_Enter_Left
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PeterGriffin_Exit::
	applymovement LOCALID_PETER_GRIFFIN_EVER_GRANDE, EverGrandeCity_PokemonLeague_1F_Movement_PeterGriffin_Exit
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_TurnGuard_Left::
	turnobject LOCALID_LEAGUE_GUARD_1, DIR_SOUTH
	return

EverGrandeCity_PokemonLeague_1F_EventScript_TurnGuard_Right::
	turnobject LOCALID_LEAGUE_GUARD_2, DIR_SOUTH
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
	playse SE_FAILURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_left
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
	walk_right
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_PeterGriffin_Enter_Right:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_PeterGriffin_Enter_Left:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_PeterGriffin_Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
	.string "Beyond this point, only those Trainers\n"
	.string "who have collected all the Gym Badges\l"
	.string "are permitted to enter.\p"
	.string "Trainer, let us confirm that you have\n"
	.string "all the Gym Badges.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
	.string "You haven't obtained all the Badges.\p"
	.string "If you're bound for the Pokémon\n"
	.string "League, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth:
	.string "Trainer! Believe in yourself and your\n"
	.string "Pokémon, and go forth!$"

EverGrandeCity_PokemonLeague_1F_Text_PeterGriffin_Intro:
	.string "Wow, you're at the Elite Four already?\n"
	.string "HAHAHAHA!\p"
	.string "Listen, I gotta battle you real quick,\n"
	.string "otherwise I'll lose my bet to Joe!$"
 
EverGrandeCity_PokemonLeague_1F_Text_PeterGriffin_Defeat:
	.string "Aw, crap!\n"
	.string "There goes my fifty dollars!$"

EverGrandeCity_PokemonLeague_1F_Text_PeterGriffin_Defeated:
	.string "Crap, I gotta pay out my fifty dollars.\p"
	.string "I can't believe I lost to somebody who\n"
	.string "still has to walk everywhere.\p"
	.string "I'd beat the Champion, but he's from\n"
	.string "another show, and you know how I feel\l"
	.string "about that.\p"
	.string "Let's just call this a tie.$"