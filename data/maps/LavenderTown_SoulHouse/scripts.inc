LavenderTown_SoulHouse_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_PeterGriffin::
	msgbox SoulHouse_Text_PeterGriffin, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "Aw yeah!\n"
	.string "I just love playing Pokémon Heart\n"
	.string "and Soul right here in this spacious\l"
	.string "room!\p"
	.string "It's the PERFECT Johto romhack, don't you\n"
	.string "agree?$"

SoulHouse_Text_Teacher:
	.string "There are other hacks of Johto here,\n"
	.string "I think.\p"
	.string "Dark Gold, Soul Gold, Liquid Crystal,\n"
	.string "and Scorched Silver come to mind.\p"
	.string "What?\p"
	.string "You don't like Dark Gold?\p"
	.string "Shame on you!$"

SoulHouse_Text_Lass:
	.string "These graves are boring, let me find\n"
	.string "something else to do!$"

SoulHouse_Text_PeterGriffin:
	.string "Peter Griffin: Hey, {PLAYER}!\n"
	.string "I'm reading all these gravestones!\p"
	.string "Isn't that funny?\p"
	.string "This reminds me of the one time where\n"
	.string "I ate a cheeseburger on an airplane!$"
