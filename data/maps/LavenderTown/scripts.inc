LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, LavenderTown_OnLoad
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_OnLoad::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "Did you know you can file your taxes\n"
	.string "with TurboTax?\p"
	.string "They can con you out of your money\n"
	.string "though!$"

LavenderTown_Text_Teacher:
	.string "Oh, go fuck yourself, will you?\p"
	.string "I'm trying to play Super Mario 3D World\n"
	.string "on my Nintendo Switch!$"

LavenderTown_Text_Gramps:
	.string "People come from all over to pay\n"
	.string "their respects to the departed\l"
	.string "souls of Pokémon.\p"
	.string "Though it mostly seems to be hardcore\n"
	.string "Nuzlockers who make their journeys here…$"

LavenderTown_Text_Youngster:
	.string "You need an air horn to wake\n"
	.string "sleeping Pokémon.\p"
	.string "Every trainer has to know that,\n"
	.string "otherwise you are a dumbass who\l"
	.string "shouldn't even pass kindergarten.$"

LavenderTown_Text_Sign:
	.string "Lavender Town\p"
	.string "The town of pathetic sickly flowers.$"

LavenderTown_Text_KantoRadioStationSign:
	.string "Kanto Radio Station\p"
	.string "I don't know why we even make radio shows,\n"
	.string "thanks to YouTube Shorts and TikTok!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "Lavender Volunteer Pokémon\n"
	.string "House$"

LavenderTown_Text_SoulHouseSign:
	.string "Heart and Soul House\p"
	.string "Where the original game still lives on.$"
