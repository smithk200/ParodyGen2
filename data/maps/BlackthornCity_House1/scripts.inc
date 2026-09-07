BlackthornCity_House1_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "There was a group of young lads and\n"
	.string "lasses who taught their town not to\l"
	.string "fear the dragons…\p"
	.string "And it all started with a young man\n"
	.string "named Hiccup!\p"
	.string "Pretty cool, right?$"

BlackthornCity_House1_Text_Dratini:
	.string "Dratini: Draa!$"
