PokemonLeague_KarensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	@special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_SANS_1, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_SANS_2, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "Sans: Oh, it's you again.\p"
    .string "Guess you couldn't get enough of\n"
    .string "the ol' Sans, huh?\p"
    .string "Well, I've got nothing to lose.\p"
    .string "Except my money, that is.\p"
    .string "heh heh heh heh…$"

PokemonLeague_KarensRoom_Text_Before:
    .string "heh heh heh heh…\p"
	.string "I'm Sans.\p"
	.string "You might have thought you’d be\n"
	.string "breezing through, but you’re in for a\l"
	.string "little surprise.\p"
	.string "See, I'm not just your average\n"
	.string "Elite Four member.\p"
	.string "I’ve got a bone to pick with you.\p"
	.string "I use Dark-type Pokémon, like\n"
	.string "Karen did before me.\p"
	.string "Unlike hers, though, mine are\n"
	.string "nightmarishly good at getting\l"
	.string "under your skin.\p"
	.string "Alright.\n"
	.string "It's too late now, kid.\p"
	.string "Do you wanna have a bad time?$"

PokemonLeague_KarensRoom_Text_Beaten:
    .string "Well, kid!\n"
    .string "You're really something else!$"

PokemonLeague_KarensRoom_Text_Defeat:
    .string "heh heh heh heh…\p"
    .string "You just don't give up, huh?\p"
    .string "So I advise you…\n"
    .string "Lance is tough. Like really tough.\p"
    .string "Heal up reall well before\n"
    .string "going to Lance's room.\p"
	.string "No, I mean it.\p"
	.string "Otherwise you'll be in for a bad time.$"

