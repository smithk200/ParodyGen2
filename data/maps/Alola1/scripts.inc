Alola1_MapScripts::
	.byte 0

Alola1_EventScript_Sailor::
	lock
	faceplayer
	msgbox Alola1_Text_Sailor_AskToWarp, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Alola1_Text_Sailor_No
	msgbox Alola1_Text_Sailor_Alolalolalol, MSGBOX_AUTOCLOSE
	warp MAP_GOLDENROD_CITY, 9, 23
	release
	end

Alola1_EventScript_PeterGriffin::
	lock
	faceplayer
	msgbox Alola1_Text_PeterGriffin, MSGBOX_AUTOCLOSE
	release
	end

Alola1_EventScript_Man1::
	lock
	faceplayer
	msgbox Alola1_Text_Sailor_Alolalolalol, MSGBOX_AUTOCLOSE
	release
	end

Alola1_EventScript_Man2::
	lock
	faceplayer
	msgbox Alola1_Text_Man2, MSGBOX_AUTOCLOSE
	release
	end

Alola1_Text_Sailor_AskToWarp:
	.string "Do you want to go back to\n"
	.string "Goldenrod City?$"

Alola1_Text_Sailor_No:
	.string "Alrighty then!$"

Alola1_Text_Sailor_Alolalolalol:
	.string "Alola lola lol!$"

Alola1_Text_PeterGriffin:
	.string "Hey Lois!\n"
	.string "Look, I'm in Alola!\p"
	.string "Alola lola lol!$"

Alola1_Text_Man2:
	.string "They say you can find Pokémon\n"
	.string "in Alola that you can't find\l"
	.string "anywhere else.\p"
	.string "I hope I find an Alolan\n"
	.string "Raichu here!$"