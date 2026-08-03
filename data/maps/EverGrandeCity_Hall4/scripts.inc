EverGrandeCity_Hall4_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall4_OnWarp
	.byte 0

EverGrandeCity_Hall4_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall4_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall4_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_Hall4_EventScript_Silver::
	goto_if_eq VAR_STARTER_MON, 0, EverGrandeCity_Hall4_Silver_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, EverGrandeCity_Hall4_Silver_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, EverGrandeCity_Hall4_Silver_Battle_Chikorita
	end

EverGrandeCity_Hall4_Silver_Battle_Cyndaquil::
	trainerbattle_single TRAINER_SILVER_CYNDAQUIL_HOENN_LEAGUE, EverGrandeCity_Hall4_Text_Silver_Intro, EverGrandeCity_Hall4_Text_Silver_Defeat, EventScriptEverGrandeCitySilverDefeated
	msgbox EverGrandeCity_Hall4_Text_Silver_Post_Battle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Hall4_Silver_Battle_Totodile::
	trainerbattle_single TRAINER_SILVER_TOTODILE_HOENN_LEAGUE, EverGrandeCity_Hall4_Text_Silver_Intro, EverGrandeCity_Hall4_Text_Silver_Defeat, EventScriptEverGrandeCitySilverDefeated
	msgbox EverGrandeCity_Hall4_Text_Silver_Post_Battle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Hall4_Silver_Battle_Chikorita::
	trainerbattle_single TRAINER_SILVER_CHIKORITA_HOENN_LEAGUE, EverGrandeCity_Hall4_Text_Silver_Intro, EverGrandeCity_Hall4_Text_Silver_Defeat, EventScriptEverGrandeCitySilverDefeated
	msgbox EverGrandeCity_Hall4_Text_Silver_Post_Battle, MSGBOX_DEFAULT
	release
	end

EventScriptEverGrandeCitySilverDefeated::
	msgbox EverGrandeCity_Hall4_Text_Silver_Post_Battle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_Hall4_Text_Silver_Intro:
	.string "Hmph, {PLAYER}.\n"
	.string "It's you.\p"
	.string "I've tried to beat the Champion.\p"
	.string "He's tough, for sure. But I know that I'll be\n"
	.string "better than him next time.\p"
	.string "I suppose you haven't improved much, huh?\p"
	.string "I'll be the judge of that.\p"
	.string "{PLAYER}, show me what you're made of.$"
	
EverGrandeCity_Hall4_Text_Silver_Defeat:
	.string "Hmph! Even better than me!"

EverGrandeCity_Hall4_Text_Silver_Post_Battle:
	.string "I'm telling you, the Champion…\n"
	.string "He's not holding back.\p"
	.string "He may be immature, but he's wicked\n"
	.string "powerful.\p"
	.string "I suppose you've met him before, huh?\p"
	.string "He mentioned battling you time and\n"
	.string "time again.\p"
	.string "You must be really something if he\n"
	.string "thinks you're that powerful.$"