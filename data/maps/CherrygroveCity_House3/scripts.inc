CherrygroveCity_House3_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "Pokémon gain experience in\n"
	.string "battle and change their form.\p"
	.string "Some can even Mega Evolve!$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "Pokémon evolve?\p"
	.string "I would be shocked if one did that!\p"
	.string "For as we know, the earth is 6,000\n"
	.string "years old, created by God himself!\p"
	.string "EVOLUTION'S A LIE!!!$"
