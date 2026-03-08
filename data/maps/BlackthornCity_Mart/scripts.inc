BlackthornCity_Mart_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "You can't buy Max Revive, but it\n"
	.string "fully restores a fainted Pokémon.\p"
	.string "Beware--it won't restore Pp, the\n"
	.string "Power Points needed for moves.$"

BlackthornMart_Text_BlackBelt:
	.string "Max Repel keeps weak Pokémon away\n"
	.string "from you.\p"
	.string "It's the longest lasting of the\n"
	.string "Repel sprays.$"
