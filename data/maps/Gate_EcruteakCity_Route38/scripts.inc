Gate_EcruteakCity_Route38_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Gate_EcruteakCity_Route38_OnFrame
	.byte 0

Gate_EcruteakCity_Route38_OnFrame::
	map_script_2 VAR_TEMP_1, 0, Gate_EcruteakCity_Route38_EventScript_EnterRoom
	.2byte 0

Gate_EcruteakCity_Route38_EventScript_EnterRoom::
	goto_if_unset FLAG_DEFEATED_ECRUTEAK_CITY_GYM, Gate_EcruteakCity_Route38_PhilipJFryIsNotThere
	goto_if_set FLAG_DEFEATED_FRY_ECRUTEAK, Gate_EcruteakCity_Route38_EventScript_PhilipJFryIntro
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject LOCALID_FRY
	applymovement LOCALID_FRY, Gate_EcruteakCity_Route38_Movement_PhilipJFry
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto Gate_EcruteakCity_Route38_EventScript_PhilipJFryIntro
	releaseall
	end

Gate_EcruteakCity_Route38_EventScript_PhilipJFryIntro::
	goto_if_set FLAG_DEFEATED_FRY_ECRUTEAK, Gate_EcruteakCity_Route38_PhilipJFryExit
	msgbox Gate_EcruteakCity_Route38_TextPhilipJFryIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_STARTER_MON, 0, EcruteakCity_Fry_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, EcruteakCity_Fry_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, EcruteakCity_Fry_Battle_Chikorita
	end

EcruteakCity_Fry_AfterBattle::
	msgbox Gate_EcruteakCity_Route38_TextPhilipJFryPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TERA_ORB
	setflag FLAG_TERA_ORB
	setflag FLAG_TERA_ORB_NO_COST	
	msgbox Gate_EcruteakCity_Route38_TextExplainTeraOrb, MSGBOX_DEFAULT
	waitmovement 0
	msgbox Gate_EcruteakCity_Route38_TextFryLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRY, Gate_EcruteakCity_Route38_FryLeavesForOlivine
	waitmovement 0
	setflag FLAG_HIDE_FRY_ECRUTEAK
	removeobject LOCALID_FRY
	releaseall
	end

Gate_EcruteakCity_Route38_PhilipJFryExit::
	goto_if_set FLAG_HIDE_FRY_ECRUTEAK, Gate_EcruteakCity_Route38_PhilipJFryIsNotThere
	msgbox Gate_EcruteakCity_Route38_TextPhilipJFryPostBattle, MSGBOX_DEFAULT
	applymovement LOCALID_FRY, Gate_EcruteakCity_Route38_FryLeavesForOlivine
	waitmovement 0
	setflag FLAG_HIDE_FRY_ECRUTEAK
	removeobject LOCALID_FRY
	releaseall
	end

EcruteakCity_Fry_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_FRY_CYNDAQUIL_ECRUTEAK, Gate_EcruteakCity_Route38_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_ECRUTEAK
	goto EcruteakCity_Fry_AfterBattle

EcruteakCity_Fry_Battle_Totodile::
	trainerbattle_no_intro TRAINER_FRY_TOTODILE_ECRUTEAK, Gate_EcruteakCity_Route38_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_ECRUTEAK
	goto EcruteakCity_Fry_AfterBattle

EcruteakCity_Fry_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_FRY_CHIKORITA_ECRUTEAK, Gate_EcruteakCity_Route38_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_ECRUTEAK
	goto EcruteakCity_Fry_AfterBattle

Gate_EcruteakCity_Route38_PhilipJFryIsNotThere::
	end

CommonScript_End::
	end

Gate_EcruteakCity_Route38_Movement_PhilipJFry:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Gate_EcruteakCity_Route38_FryLeavesForOlivine:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "Where did you say you're from?\p"
	.string "New Bark Town?\p"
	.string "Prof. Elm lives over there,\n"
	.string "right?\p"
	.string "You've come a long way to get\n"
	.string "here.$"

Gate_EcruteakCity_Route38_TextPhilipJFryIntro:
	.string "Hi, {PLAYER}!\n"
	.string "Hope you're doing well!\p"
	.string "I got done with facing Rick and Morty\n"
	.string "a while ago. I'm just doing some training\l"
	.string "before I reach Olivine City.\p"
	.string "Rick and Morty were tough, though!\n"
	.string "I was not expecting that Skeledirge!\p"
	.string "But I'm still ready to battle!\p"
	.string "Ready?\p"
	.string "Here we GOOO!$"

Gate_EcruteakCity_Route38_TextExplainTeraOrb:
	.string "This here is the Tera Orb.\p"
	.string "It allows your Pokémon to Teras-\n"
	.string "Terasala- Terrastall-\p"
	.string "I can't pronounce that word for the\n"
	.string "life of me!\p"
	.string "It allows you to change your Pokémon's\n"
	.string "type in battle to its Tera Type.\p"
	.string "It could come in handy\n"
	.string "in certain situations.\p"
	.string "Oh, and don't worry about recharging it\n"
	.string "at a Pokécenter- it will charge\l"
	.string "automatically after you use it.\p"
	.string "It's solar-powered!$"

Gate_EcruteakCity_Route38_TextFryLeaves:
	.string "Bye, {PLAYER}!\p"
	.string "I'm going to Olivine to challenge the Gym\n"
	.string "Leader there.\p"
	.string "After you beat him, let me know how\n"
	.string "your fight against him goes, alright?\p"
	.string "I hope we see each other again!$"

Gate_EcruteakCity_Route38_TextPhilipJFryDefeat:
	.string "Wow…\p"
	.string "You're getting stronger every time\n"
	.string "we battle!$"

Gate_EcruteakCity_Route38_TextPhilipJFryPostBattle:
	.string "Well, that battle was something else!\p"
	.string "Here you go. You've earned it.$"