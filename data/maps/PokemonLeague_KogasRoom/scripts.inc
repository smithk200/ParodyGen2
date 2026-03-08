PokemonLeague_KogasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	@special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_NED_1, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_NED_2, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "Koga: Fwahahahaha!\p"
    .string "You return, brave challenger.\p"
    .string "My ninja skills have sharpened.\p"
    .string "New sinister traps await you.\p"
    .string "Poison, sleep, and more...\n"
    .string "Be ready!\p"
    .string "Fwahahahaha!\p"
    .string "Show me how you've grown!$"

PokemonLeague_KogasRoom_Text_Before:
    .string "Hidey-ho, neighbor!\p"
    .string "I am Ned of the Elite Four.\p"
    .string "I live in the shadow of\n"
	.string "God himself.\p"
    .string "I was once a Gym Leader of New\n"
    .string "Hoenn, but now times have changed.\p"
    .string "God has put me on a different path.\p"
    .string "So…\p"
    .string "Are you ready to face my defensive\n"
    .string "Steel type strategy?\p"
    .string "God, I pray for the strength to\n"
    .string "defeat {PLAYER} in battle!$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "God, why have you forsaken me?\n"
	.string "Well, neighbor, you really\l"
    .string "know your stuff!$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "Even God couldn't stop me from\n"
    .string "defeating you…\p"
    .string "Well, this is a sign from the Lord\n"
    .string "that I need to train harder!\p"
    .string "Diddly-diddly…\n"
    .string "Diddly, diddly…$"
