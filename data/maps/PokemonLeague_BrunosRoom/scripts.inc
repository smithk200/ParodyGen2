PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	@special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_JOY_1, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_JOY_2, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	@waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "Joy: Hi! Welcome back!\p"
    .string "My Pokémon have gotten stronger last\n"
    .string "time since we met.\p"
    .string "Ready to see the power of\n"
    .string "my new and improved cute Pokémon?\p"
    .string "Let's go!$"

PokemonLeague_BrunosRoom_Text_Before:
    .string "Hi! I'm Joy!\n"
    .string "I'm a member of the Elite Four!\p"
    .string "I've been part of the Elite Four for\n"
    .string "four years running!\p"
	.string "You know why?\p"
	.string "It's because I use Electric\n"
	.string "type Pokémon!\p"
	.string "Also, I asked the Pokémon League\n"
	.string "to install permanent rain in my room!\p"
    .string "You wanna see the skills I've had\n"
    .string "that kept me up here for the\l"
	.string "past four years?\p"
    .string "I bet you do!\p"
    .string "Ready, {PLAYER}? My Jolteon\n"
    .string "and my other cute Pokémon will take\l"
	.string "you down!$"

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "I lost? Oh, okay.$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "Go on to the next room!\p"
    .string "Though there's a spooky scary\n"
	.string "skeleton in there…$"
