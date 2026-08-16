RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Nate::
	goto_if_set FLAG_BADGE23_GET, RustboroCity_Gym_EventScript_NateRematch
	trainerbattle_single TRAINER_NATE_1, RustboroCity_Gym_Text_NateIntro, RustboroCity_Gym_Text_NateDefeat, RustboroCity_Gym_EventScript_NateDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_NatePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_NateDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_NateRematch::
	trainerbattle_rematch_double TRAINER_NATE_1, RustboroCity_Gym_Text_NatePreRematch, RustboroCity_Gym_Text_NateRematchDefeat, RustboroCity_Gym_Text_NateRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_NatePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_BADGE23_GET, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE23_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE23_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Nate, the Gym Leader, is a user\n"
	.string "of many types of Pokémon.\p"
	.string "Legend has it he nicknamed his Pokémon\n"
	.string "after a certain sketch comedy.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the Gym Leader.\p"
	.string "Well, go for it!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "You're going places!\n"
	.string "That's got to feel awesome!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Don't take us Gym Trainers lightly!\n"
	.string "I'll show you why we're better!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "You were too good for me…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "You haven't seen anything of the Rock\n"
	.string "type's terrifying power!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against Nate!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! You've got some potential!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "Nate is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "We might be in the middle of town,\n"
	.string "but so what?\p"
	.string "My Rock Pokémon need room to\n"
	.string "do their thing!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty mother\n"
	.string "shucker!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "I have to hand it to our Leader.\n"
	.string "He doesn't just use one particular type!\p"
	.string "That's a glaring weakness that many\n"
	.string "Leaders have, wouldn't you say?$"

RustboroCity_Gym_Text_NateIntro:
	.string "Yo, wassup!\n"
	.string "I'm Nate!\p"
	.string "I was born in Dewford, but when the\n"
	.string "League forced Brawly's gym to shut down,\l"
	.string "I decided to become a leader here!\p"
	.string "My team will absolutely bowl you over!$"

RustboroCity_Gym_Text_NateDefeat:
	.string "That was an unforgettable luncheon!$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} received the Steamed Hams Badge\n"
	.string "from Nate.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "The Steamed Hams Badge is a nifty\n"
	.string "little badge.\p"
	.string "It looks cool, but you can't sell it!\p"
	.string "Here, I'll give you this TM too.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "That Technical Machine, TM39,\n"
	.string "contains Rock Tomb.\p"
	.string "It slows down your opponents by trapping\n"
	.string "them beneath rocks!\p"
	.string "Is that cool or what?"

RustboroCity_Gym_Text_NatePostBattle:
	.string "Since you are so strong, you should\n"
	.string "challenge other Gym Leaders.\p"
	.string "By battling many Trainers, you should\n"
	.string "learn many things.$"

RustboroCity_Gym_Text_GymStatue:
	.string "Rustboro City Pokémon Gym$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "Rustboro City Pokémon Gym\p"
	.string "Nate's Certified Trainers:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_NateRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Nate: Oh, hello, {PLAYER}?\n"
	.string "This is Nate of Rustboro City.\p"
	.string "I heard from Brawly that you're\n"
	.string "moving up through the ranks of\l"
	.string "Trainers at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my Gym\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredNate:
	.string "Registered Gym Leader Nate\n"
	.string "in the PokéNav.$"

RustboroCity_Gym_Text_NatePreRematch:
	.string "Far out, man!\n"
	.string "It's great to see you again!\p"
	.string "Are you as stoked as I am to battle?\p"
	.string "Let's go!$"

RustboroCity_Gym_Text_NateRematchDefeat:
	.string "Whoa, little dude.\n"
	.string "You're hot stuff!$"

RustboroCity_Gym_Text_NatePostRematch:
	.string "Come back again so that we can\n"
	.string "battle some more!$"

RustboroCity_Gym_Text_NateRematchNeedTwoMons:
	.string "Nate: I'm so glad to see you again.\n"
	.string "I'm Nate, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one Pokémon with you?\p"
	.string "Please return with at least one more\n"
	.string "Pokémon.$"
