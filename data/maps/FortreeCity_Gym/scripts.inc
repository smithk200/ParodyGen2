FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_GARBAGEFLAG @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_NED_3, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE19_GET
	settrainerflag TRAINER_ROD_2
	settrainerflag TRAINER_TODD_3
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_AUTOCLOSE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_NED_3, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_2, FortreeCity_Gym_Text_RodIntro, FortreeCity_Gym_Text_RodDefeat
	msgbox FortreeCity_Gym_Text_RodPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Todd::
	trainerbattle_single TRAINER_TODD_3, FortreeCity_Gym_Text_ToddIntro, FortreeCity_Gym_Text_ToddDefeat
	msgbox FortreeCity_Gym_Text_ToddPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GARBAGEFLAG, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Fortree Gym Leader Winona is\n"
	.string "a master of Flying-type Pokémon.\p"
	.string "She's waiting at the back of this Gym,\n"
	.string "behind the rotating doors.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take wing!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "You did it!\n"
	.string "You've achieved liftoff!$"

FortreeCity_Gym_Text_RodIntro:
	.string "My daddy's a Flying-type master!\n"
	.string "He's very strong!$"

FortreeCity_Gym_Text_RodDefeat:
	.string "You…\n"
	.string "You're stronger than him…$"

FortreeCity_Gym_Text_RodPostBattle:
	.string "Uh, my daddy's more powerful!\n"
	.string "More powerful than me!$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "The lovers of Bird Pokémon aspire\n"
	.string "to join this Gym.\p"
	.string "As a member of the Fortree Gym,\n"
	.string "I'm not allowed to lose!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "It was too much of a load for me\n"
	.string "to bear…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "The world is huge, and there are\n"
	.string "countless tough Trainers.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "There's no need for Winona, our Gym\n"
	.string "Leader, to deal with you!\p"
	.string "I'm plenty good enough for you!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "Winona, I…\n"
	.string "I lost!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "Winona is cute and she's strong.\n"
	.string "She's the ultimate Leader!\p"
	.string "Blush…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "Winona taught me personally!\n"
	.string "You can't beat me easily!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "I was beaten…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Thanks to Winona, the people of\n"
	.string "Fortree can live without fear.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "When Winona takes to battle, her face\n"
	.string "shines with beautiful determination…\p"
	.string "I'm not letting you witness that\n"
	.string "lovely sight!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk!\n"
	.string "I couldn't stop you.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "You'd better watch it!\n"
	.string "Don't get distracted staring at Winona\l"
	.string "or you'll go crashing down in a heap!$"

FortreeCity_Gym_Text_ToddIntro:
	.string "Hey!\p"
	.string "I remember you from Violet City!$"

FortreeCity_Gym_Text_ToddDefeat:
	.string "Wow, you've improved!$"

FortreeCity_Gym_Text_ToddPostBattle:
	.string "Did you know?\p"
	.string "I was in Damian's gym, training to\n"
	.string "beat him and his food Pokémon.\p"
	.string "I hear Damian's a Gym Leader in\n"
	.string "Hoenn, too.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Hidey-ho, neighbor!\p"
	.string "I'm the leader of Fortree Gym!\p"
	.string "God has allowed me to return\n"
	.string "back to my beloved Flying Gym\l"
	.string "in Hoenn.\p"
	.string "I use Ground and Steel-type\n"
	.string "Pokémon in the Pokémon League in\l"
	.string "Kanto, but here in Fortree, I can\l"
	.string "use my beloved Flying-type Pokémon!\p"
	.string "I pray to the almighty God that I\n"
	.string "defeat you!\p"
	.string "God, give me the strength!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Well, neighbor, you have defeated me.\p"
	.string "My beloved Flying types couldn't do it…\p"
	.string "In recognition of your strength in\n"
	.string "battle, this Gym Badge should do it.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} received the Cross Badge\n"
	.string "from Ned.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "With the Feather Badge, all Pokémon up\n"
	.string "to Lv 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move Fly outside of battle.\p"
	.string "And this…\n"
	.string "This is a gift from the LORD.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 contains Aerial Ace.\p"
	.string "It's an accurate attack that hits\n"
	.string "without fail.\p"
	.string "Just like the LORD!$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registered Gym Leader Winona\n"
	.string "in the PokéNav.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Though I fell to you, I will remain\n"
	.string "devoted to my LORD God.$"

FortreeCity_Gym_Text_GymStatue:
	.string "Fortree City Pokémon Gym$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "Fortree City Pokémon Gym\p"
	.string "Ned's Certified Trainers:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "Winona: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "I failed to reach your height again…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "Winona: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "Winona: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "Pokémon with you?\p"
	.string "Please return with two Pokémon\n"
	.string "at the very least.$"
