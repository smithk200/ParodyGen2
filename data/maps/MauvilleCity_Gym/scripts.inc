MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_GARBAGEFLAG, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_GARBAGEVAR
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Ella::
	goto_if_set FLAG_BADGE18_GET, MauvilleCity_Gym_EventScript_EllaRematch
	trainerbattle_single TRAINER_ELLA_1, MauvilleCity_Gym_Text_EllaIntro, MauvilleCity_Gym_Text_EllaDefeat, MauvilleCity_Gym_EventScript_EllaDefeated
	msgbox MauvilleCity_Gym_Text_EllaPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_EllaRematch::
	msgbox MauvilleCity_Gym_Text_EllaPreRematch, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELLA_2, MauvilleCity_Gym_Text_EllaRematchDefeat
	goto MauvilleCity_Gym_EventScript_EllaDefeated2

MauvilleCity_Gym_EventScript_EllaDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	setflag FLAG_BADGE18_GET
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_EllaPostBattle, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

MauvilleCity_Gym_EventScript_EllaDefeated2::
	msgbox MauvilleCity_Gym_Text_EllaDefeated2, MSGBOX_DEFAULT
	closemessage
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_EllaGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_NONE, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_BADGE18_GET, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE18_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE18_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Ella, the Leader of Mauville\n"
	.string "Gym, uses Electric-type Pokémon.\p"
	.string "If you challenge her with Water-type\n"
	.string "Pokémon, she'll zap them! Bzzt!\p"
	.string "Flying-type Pokémon will get their\n"
	.string "wings zapped in there!\p"
	.string "That's all I can tell you!\p"
	.string "Hey, go for it!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa, you're electrifying!\n"
	.string "You've powered the door open!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "My electric soul, it'll shatter your\n"
	.string "dreams whole, whoa-yeahah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "That was plugged in, amped up,\n"
	.string "over-driven electric, man!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "Pokémon and rock, it's all about heart,\n"
	.string "whoa-yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "I trained under Ella!\n"
	.string "There ain't no way I'll lose easily!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Unplugged and turned off…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "Ella, our Gym Leader, has been\n"
	.string "around for a short time.\p"
	.string "He was battling even before your\n"
	.string "daddy was born, that tough coot.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "This Gym's got puzzles!\n"
	.string "Isn't it fun?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "It's no fun to lose…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "Ella says he likes setting up\n"
	.string "little traps with switches.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "With my charm and my Pokémon's moves,\n"
	.string "you'll be shocked!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "I'm shocked by your power!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "I've heard that Mauville was founded\n"
	.string "by Ella.\p"
	.string "He was a Trainer long before we\n"
	.string "became Trainers.\l"
	.string "He must know all sorts of things!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "I love shiny things!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "My eyes are frazzled…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "Mauville Gym's Ella has a shiny\n"
	.string "forehead. It makes me happy!$"

MauvilleCity_Gym_Text_EllaIntro:
	.string "I'm Ella!\p"
	.string "I really love Electric type Pokémon!\p"
	.string "I will shock you…\n"
	.string "That's a funny joke, right?$"

MauvilleCity_Gym_Text_EllaDefeat:
	.string "I lost?\n"
	.string "Huh…\p"
	.string "I guess I'll give you this Badge then.$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} received the Electric Badge\n"
	.string "from Ella.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "This is a cool and shiny badge!\n"
	.string "You can show it to others!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "That TM34 there contains Shock Wave.\p"
	.string "I can't read yet, but it never misses!$"

MauvilleCity_Gym_Text_RegisteredElla:
	.string "Registered Gym Leader Ella\n"
	.string "in the PokéNav.$"

MauvilleCity_Gym_Text_EllaPostBattle:
	.string "I can't wait to be as strong as you!$"

MauvilleCity_Gym_Text_EllaGoForthAndEndeavor:
	.string "Wahahahah!\n"
	.string "Go forth and endeavor, youngster!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "Mauville City Pokémon Gym$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "Mauville City Pokémon Gym\p"
	.string "Ella's Certified Trainers:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_EllaPreRematch:
	.string "You're going to battle me again?\n"
	.string "I'm even stronger now!\p"
	.string "Don't say I didn't warn you!$$"

MauvilleCity_Gym_Text_EllaRematchDefeat:
	.string "You beat me again!\n"
	.string "How silly!$"

MauvilleCity_Gym_Text_EllaPostRematch:
	.string "Will you come back again to rematch\n"
	.string "me?$"

MauvilleCity_Gym_Text_EllaRematchNeedTwoMons:
	.string "Ella: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my Pokémon!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait!\n"
	.string "You've only one Pokémon with you!\p"
	.string "Come see me with two or more\n"
	.string "Pokémon, all right?$"

MauvilleCity_Gym_Text_EllaDefeated2:
	.string "You beat me again!\p"
	.string "I won't cry about it, though.$"