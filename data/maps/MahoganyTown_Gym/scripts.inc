MahoganyTown_Gym_MapScripts::
	.byte 0

MahoganyTown_Gym_EventScript_Machine::
    lock
    goto_if_set FLAG_SOLVED_MAHOGANY_PUZZLE, MahoganyTown_Gym_EventScript_MachineWantToWarp
    setflag FLAG_SOLVED_MAHOGANY_PUZZLE
    clearflag FLAG_HIDE_MAHOGANY_MACHINE
    msgbox Common_Text_PlayerClearedPuzzle, MSGBOX_DEFAULT
	closemessage
    goto MahoganyTown_Gym_EventScript_MachineWantToWarp
    release
    end

MahoganyTown_Gym_EventScript_MachineWantToWarp::
	lock
	faceplayer
	msgbox MahoganyTown_Machine_AskToWarp, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_Machine_No
	warp MAP_MAHOGANY_TOWN_GYM2, 2, 5
	release
	end

Common_EventScript_Machine_No::
	msgbox Common_Text_Machine_NoWarp, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "Mahogany Town Pokémon Gym$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "Mahogany Town Pokémon Gym\p"
	.string "Clay'sCertified Trainers:\n"
	.string "{RIVAL}, Fry, {PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clay::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Clay_Defeated
	msgbox MahoganyTown_Gym_Text_ClayIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Clay_Battle1

MahoganyTown_Gym_EventScript_ClayVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANYTOWN
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Clay_Battle3
	goto MahoganyTown_Gym_EventScript_Clay_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Clay_Battle3
	goto MahoganyTown_Gym_EventScript_Clay_Battle2
	
MahoganyTown_Gym_EventScript_Clay_Battle1::
	trainerbattle_no_intro TRAINER_CLAY_1, MahoganyTown_Gym_Text_ClayImpressed
    setflag FLAG_RECEIVED_BADGE_5
	goto MahoganyTown_Gym_EventScript_ClayVictory

MahoganyTown_Gym_EventScript_Clay_Battle2::
	trainerbattle_no_intro TRAINER_CLAY_1_2, MahoganyTown_Gym_Text_ClayImpressed
    setflag FLAG_RECEIVED_BADGE_6
	goto MahoganyTown_Gym_EventScript_ClayVictory

MahoganyTown_Gym_EventScript_Clay_Battle3::
	trainerbattle_no_intro TRAINER_CLAY_1_3, MahoganyTown_Gym_Text_ClayImpressed
    setflag FLAG_RECEIVED_BADGE_7
	goto MahoganyTown_Gym_EventScript_ClayVictory

MahoganyTown_Gym_EventScript_Clay_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_ClayIntro:
    .string "You think you’re ready\n"
    .string "for this, punk?\p"
    .string "You think you can handle the cold?\p"
    .string "Hah.\p"
    .string "You’re about as prepared for this\n"
    .string "as my son Orel is for… well, anything.\p"
    .string "Life’s not about comfort,\n"
    .string "it’s about enduring things…\l"
    .string "…like my stinkin' dead-end job!\p"
    .string "Life is harsh.\p"
    .string "It doesn’t care about your feelings,\n"
    .string "your ambitions, or your little dreams.\p"
    .string "You either survive it, or you don’t.\p"
    .string "Now, let's get this over with.$"

MahoganyTown_Gym_Text_ClayImpressed:
    .string "Well then…\n"
    .string "you little punk.\p"
    .string "I'll give you this badge, I guess.$"

MahoganyTown_Gym_Text_ReceivedBadge:
    .string "{PLAYER} received Moralbadge.$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
    .string "That Badge will allow your Pokémon\n"
    .string "use Whirlpool to get across\l"
    .string "real whirlpools.\p"
    .string "And take this too, I guess…$"

MahoganyTown_Gym_Text_HailSpeech:
    .string "That TM contains Hail.\p"
    .string "It inflicts damage every\n"
    .string "turn for 5 turns.\p"
    .string "It demonstrates the harshness\n"
    .string "of winter.$"

MahoganyTown_Gym_Text_CherishPokemon:
    .string "Ugh, just get out of here already!\p"
    .string "You were just a mistake anyway.\p"
    .string "Oh, wait, that's my son Shapey…$"

MahoganyTown_Gym_Text_ClayRematch:
    .string "Okay, little punk.\p"
    .string "You were only so lucky\n"
    .string "last time.\p"
    .string "But I- the great Clay Puppington-\n"
    .string "will stive to do my very best.\p"
    .string "Ready? Let's do this.\p"

MahoganyTown_Gym_Text_ClayRematchDefeat:
    .string "Well then…\n"
    .string "Stinkin' dead-end job!\p"
    .string "Aagh!\n"
    .string "I Can'T Take It Anymore!$"

MahoganyTown_Gym_Text_Guide:
    .string "Clay is a veteran who has\n"
    .string "quite strong, solid Pokémon.\p"
    .string "He's got a solid lineup of\n"
    .string "Pokémon to cover whatever\l"
    .string "you bring his way.\p"
    .string "Make sure you know your\n"
    .string "matchups before taking him on!$"

MahoganyTown_Gym_Text_GuideWin:
    .string "Clay is something, but you're\n"
    .string "something else!\p"
    .string "That was a hot battle that\n"
    .string "bridged the generation gap!$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
    .string "My tough Pokémon\n"
    .string "will steamroll you through!$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
    .string "Damn. I couldn't do a thing.$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
    .string "I think there's a move a\n"
    .string "Pokémon can use while it's\l"
    .string "frozen.$"

MahoganyTown_Gym_Text_BoarderBradSeen:
    .string "This Gym has a rock-solid floor.\p"
    .string "It's fun, isn't it?\p"
    .string "But hey--we're not playing\n"
    .string "games here!$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
    .string "Do you see how serious we are?$"

MahoganyTown_Gym_Text_BoarderBradAfter:
    .string "Wait, this gym's floor is Icy?\p"
    .string "Who knew?$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
    .string "I know Clay's secret.$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
    .string "Ok. I'll tell you Clay's secret.$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
    .string "The secret…\p"
    .string "He hasn't had sex with his wife\n"
    .string "in over eleven years!\p"
    .string "Wait, did I say too much?$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
    .string "I'm in the mood for a bacon cheeseburger!\n"
    .string "How much should my bacon be cooked?\l"
    .string "Who should cook my bacon?$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
    .string "I want the bacon on my cheeseburger\n"
    .string "burnt by Josh.$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
    .string "Josh is the way.\p"
    .string "Josh is love.\p"
    .string "Josh is life.$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
    .string "Clay is a strong Leader.\n"
    .string "He traveled away from a faraway\l"
    .string "land just to get here.$" 

MahoganyTown_Gym_Text_SkierClarissaBeaten:
    .string "Yowch! You're really something else!$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
    .string "Did you bring the right Pokémon\n"
    .string "to take Clay on?$"

Common_Text_PlayerClearedPuzzle:
    .string "{PLAYER} solved the Gym puzzle!$"

Common_Text_Machine_NoWarp:
    .string "{PLAYER} did not warp.$"

MahoganyTown_Machine_AskToWarp:
    .string "Do you want to warp to\n"
    .string "Gym Leader Clay?$"