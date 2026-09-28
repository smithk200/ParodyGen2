FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_LOAD, FuchsiaCity_OnLoad
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 VAR_FUCHSIA_CITY_STATE, 0,  FuchsiaCity_EventScript_BaobaCall
	.2byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_OnLoad::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_Trigger_PeterGriffin_Left::
	setvar VAR_TEMP_1, 0
	end

FuchsiaCity_Trigger_PeterGriffin_Right::
	setvar VAR_TEMP_1, 1
	end

FuchsiaCity_EventScript_Peter_Griffin::
	trainerbattle_single TRAINER_PETER_GRIFFIN_FUCHSIA, FuchsiaCity_Text_Peter_Griffin_Intro, FuchsiaCity_Text_Peter_Griffin_Defeat, FuchsiaCity_EventScript_Peter_Griffin_Defeated
	end

FuchsiaCity_EventScript_Peter_Griffin_Defeated::
	msgbox FuchsiaCity_Text_Peter_Griffin_PostBattle, MSGBOX_AUTOCLOSE
	call_if_eq VAR_TEMP_1, 0, FuchsiaCity_EventScript_Peter_Griffin_ExitLeft
	call_if_eq VAR_TEMP_1, 1, FuchsiaCity_EventScript_Peter_Griffin_ExitRight
	removeobject LOCALID_PETER_GRIFFIN_FUCHSIA
	setflag FLAG_HIDE_PETER_GRIFFIN_FUCHSIA
	end

FuchsiaCity_EventScript_Peter_Griffin_ExitLeft::
	applymovement LOCALID_PETER_GRIFFIN_FUCHSIA, FuchsiaCity_Movement_Peter_Griffin_ExitLeft
	waitmovement 0
	return

FuchsiaCity_EventScript_Peter_Griffin_ExitRight::
	applymovement LOCALID_PETER_GRIFFIN_FUCHSIA, FuchsiaCity_Movement_Peter_Griffin_ExitRight
	waitmovement 0
	return

FuchsiaCity_EventScript_BaobaCall::
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	end

FuchsiaCity_Text_Baoba:
	.string "Warden Baoba: {PLAYER}!\p"
	.string "This is Warden Baoba.\p"
	.string "Something awful has happened!\n"
	.string "My old Safari Zone in Fuchsia City\l"
	.string "was bought out and reopened!\p"
	.string "And apparently it has exotic new\n"
	.string "Pokémon!\p"
	.string "It's hurting my business!\p"
	.string "{PLAYER}, you must venture into the\n"
	.string "new Safari Zone and catch a Pokémon\l"
	.string "to show me. I must know about these\l"
	.string "'exotic' Pokémon.\p"
	.string "Please {PLAYER}, my business depends\n"
	.string "on you!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Movement_Peter_Griffin_ExitLeft:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FuchsiaCity_Movement_Peter_Griffin_ExitRight:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FuchsiaCity_Text_Youngster:
	.string "One of the Elite Four used to be\n"
	.string "the Leader of Fortree's Gym.\p"
	.string "I wonder how it is doing…$"

FuchsiaCity_Text_PokefanM:
	.string "Koga's daughter succeeded him as\n"
	.string "the Gym Leader after he joined the\l"
	.string "Elite Four many years ago…\p"
	.string "Koga's been replaced since!$"

FuchsiaCity_Text_Teacher:
	.string "The Safari Zone is under new\n"
	.string "management.\p"
	.string "And it has tons of new Pokémon!$"

FuchsiaCity_Text_Sign:
	.string "Fuchsia City\p"
	.string "The town where the Safari Zone is.$"

FuchsiaCity_Text_GymSign:
	.string "Fuchsia City Pokémon Gym\n"
	.string "Leader: Janine\p"
	.string "The Poisonous Ninja Master$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "There's a notice here…\p"
	.string "Safari Zone Office is closed until\n"
	.string "further notice.$"

FuchsiaCity_Text_SafariZone:
	.string "Safari Zone\n"
	.string "Now Owned By McDonald's.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "The Warden is traveling abroad.\p"
	.string "Therefore, the Safari Zone is\n"
	.string "closed.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "No littering.\p"
	.string "Please take your waste with you.\n"
	.string "You fucking chump.$"

FuchsiaCity_Text_Peter_Griffin_Intro:
	.string "Hey, you!\n"
	.string "I swear I keep seeing you again!\p"
	.string "God, why are my eyes playing tricks\n"
	.string "on me?\p"
	.string "Oh, this must be one of those walking\n"
	.string "bicyle ads or something.\p"
	.string "I see.\p"
	.string "Well, you know the drill. Here goes.$"

FuchsiaCity_Text_Peter_Griffin_Defeat:
	.string "Ya know, I don't have time for this.$"

FuchsiaCity_Text_Peter_Griffin_PostBattle:
	.string "Well, that was some battle.\p"
	.string "I should get back to Quahog again.\p"
	.string "Even though these battles look like\n"
	.string "home…\p"
	.string "Nah, must be the weather.\n"
	.string "The Pokémon world has got some\l"
	.string "wacky weather.\p"
	.string "Well, gotta go!$"