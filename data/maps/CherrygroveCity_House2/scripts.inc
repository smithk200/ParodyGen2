CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "When I was a youg man, I was a\n"
	.string "hot trainer!\p"
	.string "Here's a word of advice:\n"
	.string "Catch lots of Pokémon!\p"
	.string "Battle them to the death!!!\p"
	.string "Actually only until they “faint”.\p"
	.string "They really just die and come back\n"
	.string "to life!$"
