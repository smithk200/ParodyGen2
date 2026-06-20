Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_EventScript_Trainer_Ben::
	trainerbattle_single TRAINER_BEN_1, Route33_Text_BenSeen, Route33_Text_BenBeaten
	msgbox Route33_Text_BenAfter, MSGBOX_AUTOCLOSE
	end

Route33_Text_HikerAnthony2Seen:
	.string "I came through the tunnel,\n"
	.string "but I still have plenty\l"
	.string "of energy left.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Whoa! You've got more zip\n"
	.string "than me!$"

Route33_Text_HikerAnthony2After:
	.string "We Hikers are at our best\n"
	.string "in the mountains.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hey, did you get a Dunsparce?\p"
	.string "I caught one too.\p"
	.string "Take a look at it in the light.\n"
	.string "It's got a funny face!$"

Route33_Text_Lass:
	.string "Pant, pant…\p"
	.string "That cave was bigger than\n"
	.string "I'd expected.\p"
	.string "I got too tired exploring\n"
	.string "for Marill, so I came outside.$"

Route33_Text_BenSeen:
	.string "You're not out of the woods yet!\n"
	.string "Ledian! Attack!$"

Route33_Text_BenBeaten:
	.string "I guess it wasn't enough…$"

Route33_Text_BenAfter:
	.string "Some Pokémon became better in the\n"
	.string "Johto region.\p"
	.string "Perhaps it's due to the air-\p"
	.string "… or maybe a creator preference.$"


