Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_MagmaGrunts::
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	end

Route112_EventScript_Gil::
	trainerbattle_single TRAINER_GIL, Route112_Text_GilIntro, Route112_Text_GilDefeat,
	release
	end

Route112_EventScript_RegisterGil::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_GilRegister, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RematchGil::
	end

Route112_EventScript_Larry::
	goto_if_set FLAG_DEFEATED_LARRY_1, Route112_EventScript_Larry2
	trainerbattle_single TRAINER_LARRY_2, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry2::
	trainerbattle_single TRAINER_LARRY_2, Route112_Text_LarryIntro2, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing:
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"

Route112_Text_YeahWeNeedMeteorite:
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a Meteorite to do it.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.string "Oh, I get it now. That's why the rest\n"
	.string "of the crew went out to Fallarbor.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.string "You got it. And until they come back,\n"
	.string "we're not to let anyone pass, right.$"

Route112_Text_NotEasyToGetBackToLavaridge:
	.string "It's super easy to get to Lavaridge now.\n"
	.string "All you have to do is walk west!$"

Route112_Text_MtChimneyCableCarSign:
	.string "Mt. Chimney Cable Car\n"
	.string "“A short walk {UP_ARROW} way!”$"

Route112_Text_MtChimneySign:
	.string "Mt. Chimney\p"
	.string "“For Lavaridge or the summit,\n"
	.string "please take the Cable Car.”\p"
	.string "Though you can also go to Lavaridge\n"
	.string "by going west.$"

Route112_Text_RouteSignLavaridge:
	.string "Route 112\n"
	.string "{LEFT_ARROW} Lavaridge Town$"

Route112_Text_LarryIntro:
	.string "Hey there, {PLAYER}.\n"
	.string "It's me, Larry.\p"
	.string "I suppose we haven't gotten the chance\n"
	.string "to meet yet.\p"
	.string "Anyways, I'm an Elite Four member here,\n"
	.string "but you caught me on my off day.\p"
	.string "Ready?\p"
	.string "Let's get this over with.$"

Route112_Text_LarryIntro2:
	.string "Hey there, {PLAYER}.\n"
	.string "Do you remember me?$"
	.string "It's me, Larry.\p"
	.string "As you may know, I'm an Elite Four\n"
	.string "member here, but you caught me on\l"
	.string "my off day again.\p"
	.string "You never let me get a break, do you?\p"
	.string "Ready?\p"
	.string "Let's get this over with.$"

Route112_Text_LarryDefeat:
	.string "Well then.$"

Route112_Text_LarryPostBattle:
	.string "If I were on duty, I'd give you a\n"
	.string "Gym Badge, but I'm off duty.\p"
	.string "Anyways, hope to see you in\n"
	.string "the Elite Four!$"

Route112_Text_Ellpisis:
	.string "…$"