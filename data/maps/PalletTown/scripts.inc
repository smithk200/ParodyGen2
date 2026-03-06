PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, PalletTown_OnLoad
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_OnLoad::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "I'm raising Pokémon too.\p"
	.string "They serve as my private\n"
	.string "guards.$"

PalletTown_Text_Fisher:
	.string "Technology is incredible!\p"
	.string "We now have Wheels to transport\n"
	.string "people from place to place more\l"
	.string "quickly now!$"

PalletTown_Text_Sign:
	.string "Pallet Town\p"
	.string "The Most Boring Place In Kanto$"

PalletTown_Text_RedsHouseSign:
	.string "Red's House$"

PalletTown_Text_OaksLabSign:
	.string "Oak Pokémon\n"
	.string "Research Lab$"

PalletTown_Text_BluesHouseSign:
	.string "Blue's House$"
