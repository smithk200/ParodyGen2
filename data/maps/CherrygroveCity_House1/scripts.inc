CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "You're trying to see how good\n"
	.string "you are as a Pokémon Trainer?\p"
	.string "You better git gud.\p"
	.string "Though Bugs aren't very powerful in\n"
	.string "this region!\p"
	.string "They're weak to many things, just like\n"
	.string "real bugs!$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "When I get older, I'm going to\n"
	.string "be a Gym Leader!\p"
	.string "And I'll use Bug types, of course!\p"
	.string "I make my Pokémon battle with\n"
	.string "my friend's to make them\l"
	.string "tougher!$"
