VioletCity_Gym_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_TODD_2 VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DAMIAN_1, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedBurgerbadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_DOUBLE_TEAM
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "Woo-Wee!\p"
	.string "I'm Damian, the Gym Leader\n"
	.string "of this hick town.\p"
	.string "I've been in kitchens ever since\n"
	.string "I was ten years old.\p"
	.string "Now I bring the skills I learned\n"
	.string "in the kitchen to Pokémon battling.\p"
	.string "It won't be fuckin' easy!\p"
	.string "You better prepare yo' ass\n"
	.string "if you want to defeat me!\p"
	.string "Fuck yeah!\p"
	.string "Bring it on!$"

VioletGym_Text_Falkner_WinLoss:
	.string "Fuck! These Pokémon suck!\p"
	.string "Nah, I'm just fuckin' with you.\n"
	.string "You know I like to do that!\p"
	.string "All right. Take this.\p"
	.string "It's the official Pokémon League\n"
	.string "Burgerbadge.$"

VioletGym_Text_ReceivedBurgerbadge:
	.string "{PLAYER} received Burgerbadge.$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "Burgerbadge raises the Attack\n"
	.string "power of Pokémon.\p"
	.string "Kind of like how I smoke my weed!\p"
	.string "It also enables Pokémon to use\n"
	.string "Flash, if they can learn it,\l"
	.string "anytime.\p"
	.string "Here, take this too.$"

VioletGym_Text_Falkner_TMExplain:
	.string "By using a Tm, a Pokémon will\n"
	.string "instantly learn a new move.\p"
	.string "Tm32 contains Double Team.\p"
	.string "It increase a Pokémon's evasion.\p"
	.string "In other words, your Pokémon\n"
	.string "will be shit to hit.$"

VioletGym_Text_Falkner_AfterFight:
	.string "There are Pokémon Gyms in cities\n"
	.string "and towns ahead, okay?\p"
	.string "You need test your skills at\n"
	.string "these Gyms to get badges, okay?\p"
	.string "Gah, you can be so fuckin'\n"
	.string "stupid sometimes.\p"
	.string "Eh, I'm just fuckin' with you.\p"
	.string "I'm going to train harder to\n"
	.string "become the greatest grill master!$"

VioletGym_Text_Falkner_Rematch:
	.string "Congratulations on defeating\n"
	.string "the Elite 4!\p"
	.string "I've been training my\n"
	.string "Food Pokémon even harder.\p"
	.string "Think you can take on the power\n"
	.string "of the kitchen again?$"

VioletGym_Text_Falkner_RematchLoss:
	.string "Fuck, you beat me again!\p"
	.string "I'm going to train harder to\n"
	.string "become the greatest grill master!$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "The keyword is guts!\p"
	.string "Those here are training night and\n"
	.string "day to become food Pokémon masters.\p"
	.string "Come on!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "Gaaah!$"

VioletGym_Text_BirdKeeperRod_After:
	.string "Damian's skills are for real!\p"
	.string "Don't get cocky just because\n"
	.string "you beat me!$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "Let me see if you are good\n"
	.string "enough to face Damian!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "This can't be true!$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "This is pathetic, losing to some\n"
	.string "rookie trainer…$"

VioletGym_Text_GymGuide_Intro:
	.string "Hey! What's up? I'm no trainer,\n"
	.string "but I can give some advice!\p"
	.string "Believe me! If you believe, a\n"
	.string "championship dream can come true.\p"
	.string "You believe? Then listen.\p"
	.string "Damian doesn't have a specific\n"
	.string "type, but he specializes in Pokémon\n"
	.string "that resemble food.\p"
	.string "Also, Damian's ace has the ability\n"
	.string "to Dynamax, so watch out!\p"
	.string "Yes, I said Dynamax!\n"
	.string "We have that now!\p"
	.string "If you want more help, go visit the\n"
	.string "Pokémon Academy.\p"
	.string "The students there really know\n"
	.string "their stuff!$"

VioletGym_Text_GymGuide_Win:
	.string "Nice battle! Keep it up,\n"
	.string "and you'll be the Champ in no\l"
	.string "time at all!$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "Violet City Pokémon Gym$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "Violet City Pokémon Gym\p"
	.string "Damian's Certified Trainers:\n"
	.string "{PLAYER}$"