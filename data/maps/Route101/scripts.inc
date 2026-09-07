Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0


Route101_EventScript_HideMapNamePopup::
	end

Route101_EventScript_StartBirchRescue::
	end

Route101_EventScript_PreventExitSouth::
	end

Route101_EventScript_PreventExitWest::
	end

Route101_EventScript_PreventExitNorth::
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	step_end

Route101_Movement_ZigzagoonChase1:
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	step_end

Route101_Movement_EnterScene:
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:

	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route110_EventScript_WhatAreYouDoing::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	msgbox Route110_Text_WhatAreYouDoing, MSGBOX_AUTOCLOSE
	end

Route101_EventScript_Boy::
	goto_if_set FLAG_RECEIVED_UNOVA_STARTER, Route101_Text_PchalPreEliteFour
	trainerbattle_single TRAINER_PCHAL, Route101_Text_PchalIntro, Route101_Text_PchalDefeat
	msgbox Route101_Text_PchalPostBattle, MSGBOX_AUTOCLOSE
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
	.string "H-help me!$"

Route101_Text_PleaseHelp:
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my Bag!\n"
	.string "There's a Poké Ball!$"

Route101_Text_DontLeaveMe:
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
	.string "Okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "Just in case you don't know…\p"
	.string "If your Pokémon are running low\n"
	.string "on health, take them to\n"
	.string "a Pokémon Center.\p"
	.string "If you didn't know, there's a Pokémon\n"
	.string "Center in Oldale Town to the north.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wild Pokémon will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch Pokémon, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "Route 101\n"
	.string "{UP_ARROW} Oldale Town$"

Route101_Text_PchalIntro:
	.string "I have made it up my mountain.\p"
	.string "Will you make it up yours?$"

Route101_Text_PchalDefeat:
	.string "Pokémon Dark Gold? Merely a cakewalk.\p"
	.string "The real challenge is in Pokémon\n"
	.string "Run and Bun.$"

Route101_Text_PchalPostBattle:
	.string "Go on.\p"
	.string "Birch is waiting.$"

Common_Text_NotEnoughMons:
	.string "You don't have enough Pokémon.$"

Route110_Text_WhatAreYouDoing:
	.string "What the hell do you think\n"
	.string "you're doing, nimrod?$"

Route101_Text_PchalPreEliteFour:
	.string "I wish you the best of luck\n"
	.string "at the Elite Four.$"
