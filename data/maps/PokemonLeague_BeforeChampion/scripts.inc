PokemonLeague_BeforeChampion_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_BeforeChampion_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_BeforeChampion_OnWarp
	.byte 0

PokemonLeague_BeforeChampion_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_BeforeChampion_EventScript_EnterRoom
	.2byte 0

PokemonLeague_BeforeChampion_OnWarp:
	map_script_2 VAR_TEMP_2, 0, PokemonLeague_BeforeChampion_EventScript_PlayerTurnNorth
	.2byte 0

PokemonLeague_BeforeChampion_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_BeforeChampion_EventScript_EnterRoom::
	goto_if_set FLAG_HIDE_FRY_POKEMON_LEAGUE, Gate_EcruteakCity_Route38_PhilipJFryIsNotThere
	goto_if_set FLAG_DEFEATED_FRY_POKEMON_LEAGUE, PokemonLeague_Fry_PhilipJFryExit
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject LOCALID_FRY
	applymovement LOCALID_FRY, PokemonLeague_BeforeChampion_Movement_PhilipJFry
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto PokemonLeague_BeforeChampion_EventScript_PhilipJFryIntro
	releaseall
	end

PokemonLeague_BeforeChampion_EventScript_PhilipJFryIntro:
	@goto_if_set FLAG_DEFEATED_FRY_ECRUTEAK, PokemonLeague_Fry_PhilipJFryExit
	msgbox PokemonLeague_BeforeChampion_TextPhilipJFryIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_STARTER_MON, 0, PokemonLeague_BeforeChampion_Fry_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, PokemonLeague_BeforeChampion_Fry_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, PokemonLeague_BeforeChampion_Fry_Battle_Chikorita
	end

PokemonLeague_BeforeChampion_Fry_AfterBattle::
	msgbox Pokemon_League_TextPhilipJFryPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_Player_Movement_PlayerLetsFryWalkPastThem
	waitmovement 0
	applymovement LOCALID_FRY, Pokemon_League_Fry_Movement_Exit
	waitmovement 0
	setflag FLAG_HIDE_FRY_POKEMON_LEAGUE
	removeobject LOCALID_FRY
	releaseall
	end

PokemonLeague_Fry_PhilipJFryExit::
	goto_if_set FLAG_HIDE_FRY_POKEMON_LEAGUE, Gate_EcruteakCity_Route38_PhilipJFryIsNotThere
	msgbox Pokemon_League_TextPhilipJFryPostBattle, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_Player_Movement_PlayerLetsFryWalkPastThem
	waitmovement 0
	delay 30
	applymovement LOCALID_FRY, Pokemon_League_Fry_Movement_Exit
	waitmovement 0
	setflag FLAG_HIDE_FRY_POKEMON_LEAGUE
	removeobject LOCALID_FRY
	releaseall
	end

PokemonLeague_BeforeChampion_Movement_PhilipJFry::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonLeague_Player_Movement_PlayerLetsFryWalkPastThem::
	walk_left
	face_right
	step_end

Pokemon_League_Fry_Movement_Exit::
	walk_down
	step_end

PokemonLeague_BeforeChampion_Fry_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_FRY_CYNDAQUIL_POKEMON_LEAGUE, PokemonLeague_BeforeChampion_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_POKEMON_LEAGUE
	goto PokemonLeague_BeforeChampion_Fry_AfterBattle

PokemonLeague_BeforeChampion_Fry_Battle_Totodile::
	trainerbattle_no_intro TRAINER_FRY_TOTODILE_POKEMON_LEAGUE, PokemonLeague_BeforeChampion_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_POKEMON_LEAGUE
	goto PokemonLeague_BeforeChampion_Fry_AfterBattle

PokemonLeague_BeforeChampion_Fry_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_FRY_CHIKORITA_POKEMON_LEAGUE, PokemonLeague_BeforeChampion_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_POKEMON_LEAGUE
	goto PokemonLeague_BeforeChampion_Fry_AfterBattle

PokemonLeague_BeforeChampion_TextPhilipJFryIntro:
	.string "Hi there, {PLAYER}!\p"
	.string "I just got done trying\n"
	.string "to beat the Champion.\l"
	.string "His dragons were too much for me!\p"
	.string "I've got to see whether I can go\n"
	.string "back and try again!\p"
	.string "So how about it, {PLAYER}!\n"
	.string "Let's have one final battle!$"

PokemonLeague_BeforeChampion_TextPhilipJFryDefeat:
	.string "Well, that's that!\n"
	.string "I guess I'm not as strong as you!$"

Pokemon_League_TextPhilipJFryPostBattle:
	.string "Well, {PLAYER},\n"
	.string "should I just give up now?\p"
	.string "…\p"
	.string "No! I never give up!\n"
	.string "I've just got to rework my team!\p"
	.string "I'll be back to defeat the\n"
	.string "Champion, after I train my Pokémon\l"
	.string "to be their very best!\p"
	.string "Goodbye for now, {PLAYER}!$"