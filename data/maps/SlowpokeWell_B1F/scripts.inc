.set LOCALID_WELL_KURT, 19

SlowpokeWell_B1F_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	trainerbattle_single TRAINER_PROTON_1, SlowpokeWell_B1F_Text_ProtonSeen, SlowpokeWell_B1F_Text_ProtonBeaten, SlowpokeWell_B1F_EventScript_ProtonDefeated
	end

SlowpokeWell_B1F_EventScript_ProtonDefeated::
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, 15, 4
	release
	end

SlowpokeWell_B1F_EventScript_Proton2::
	lock
	faceplayer
	trainerbattle_single TRAINER_PROTON_1, SlowpokeWell_B1F_Text_ProtonSeen, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, 15, 4
	release
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "Kurt: Hey there, {PLAYER}!\p"
	.string "The guard up top took off when\n"
	.string "I shouted at him.\p"
	.string "But then I took a tumble down\n"
	.string "the Well.\p"
	.string "I slammed down hard on my back,\n"
	.string "so I can't move.\p"
	.string "Rats! If I were fit, my Pokémon\n"
	.string "would've punished them…\p"
	.string "Ah, it can't be helped.\p"
	.string "{PLAYER}, show them how gutsy\n"
	.string "you are in my place!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "Kurt: Way to go, {PLAYER}!\p"
	.string "Team Rocket has taken off.\p"
	.string "My back's better too.\n"
	.string "Let's get out of here.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "Darn! I was standing guard up\n"
	.string "top when some old coot yelled\l"
	.string "at me.\p"
	.string "He startled me so much that\n"
	.string "I fell down here.\p"
	.string "I think I'll vent my anger by\n"
	.string "taking it out on you!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "Arrgh! This is Not my day!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Sure, we've been corrupting the\n"
	.string "Slowpoke to try to turn them into\l"
	.string "the ultimate battle machine…\p"
	.string "But the Slowpoke only seem to be\n"
	.string "divided in quarters.\p"
	.string "Still, people will pay to see it!\p"
	.string "Anything for the profit!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "What do you want?\p"
	.string "If you interrupt our work,\n"
	.string "don't expect any mercy!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "You did OK today,\n"
	.string "but wait till next time!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Yeah, Team Rocket was broken up\n"
	.string "three years ago.\p"
	.string "The boss went into hiding.\p"
	.string "But we continued our activities\n"
	.string "underground!\p"
	.string "A small obstacle like you won't be\n"
	.string "much of a problem for our mission.\p"
	.string "I advise you to be very afraid of\n"
	.string "what is to come!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Hyuck-hyuck-hyuck!\n"
	.string "Stop corrupting the Slowpoke?\p"
	.string "You're nuts!\n"
	.string "If we obeyed you, Team Rocket's\l"
	.string "reputation would be ruined!$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Hyuck…\n"
	.string "Too strong…$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "We want to corrupt Slowpoke into\n"
	.string "their ultimate battle form.\p"
	.string "But it seems like we can just\n"
	.string "as easily assert our power by\l"
	.string "dividing these Slowpoke into quarters.\p"
	.string "Why?\p"
	.string "You wouldn't understand!\p"
	.string "It's tough being a Rocket Grunt!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "Stop corrupting Slowpoke?\p"
	.string "Yeah, just try to defeat all of us!$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "You rotten brat!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "The Slowpoke are at peace in their\n"
	.string "corrupt form!\p"
	.string "What's wrong with that?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "A Slowpoke with its body split\n"
	.string "in quarters…\p"
	.string "Huh? It has Mail.\n"
	.string "Read it?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} read the Mail.\p"
	.string "Be good and look after the\n"
	.string "house with Grandpa and Slowpoke.\p"
	.string "Love, Dad$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "A Slowpoke with its body split\n"
	.string "in quarters…$"
