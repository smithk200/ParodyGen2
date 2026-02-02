.set LOCALID_BLACKTHORN_SAGE, 7
.set LOCALID_BLACKTHORN_BOY, 2
.set LOCALID_FRY_BLACKTHORN, 17

BlackthornCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_set FLAG_FRY_GIVE_TM_BLACKTHORN, BlackThornCity_EventScript_RemoveFry
	clearflag FLAG_FRY_BLACKTHORN
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackThornCity_EventScript_RemoveFry::
	setflag FLAG_FRY_BLACKTHORN
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_BaobaCall:
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "I'm calling to tell you that\n"
	.string "the SAFARI ZONE has expanded!\p"
	.string "Please come visit!$"

BlackthornCity_Text_ElmCall:
	.string "PROF. ELM: Hello, {PLAYER}?\p"
	.string "I have something here for you.\n"
	.string "Could you swing by my LAB?\p"
	.string "See you later!$"

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end

Blackthorn_City_EventScript_Fry::
	goto_if_eq VAR_STARTER_MON, 0, Blackthorn_City_Fry_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, Blackthorn_City_Fry_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, Blackthorn_City_Fry_Battle_Chikorita
	end

Blackthorn_City_Fry_Battle_Cyndaquil::
	trainerbattle_single TRAINER_FRY_CYNDAQUIL_BLACKTHORN, Blackthorn_City_Text_PhilipJFryIntro, Blackthorn_City_Text_PhilipJFryDefeat, Blackthorn_City_PhilipJFryGiveTM
	goto_if_set FLAG_FRY_GIVE_TM_BLACKTHORN, Blackthorn_City_PhilipJFry_EndingSpeech
	goto Blackthorn_City_PhilipJFryGiveTM

Blackthorn_City_Fry_Battle_Totodile::
	trainerbattle_single TRAINER_FRY_TOTODILE_BLACKTHORN, Blackthorn_City_Text_PhilipJFryIntro, Blackthorn_City_Text_PhilipJFryDefeat, Blackthorn_City_PhilipJFryGiveTM
	goto_if_set FLAG_FRY_GIVE_TM_BLACKTHORN, Blackthorn_City_PhilipJFry_EndingSpeech
	goto Blackthorn_City_PhilipJFryGiveTM

Blackthorn_City_Fry_Battle_Chikorita::
	trainerbattle_single TRAINER_FRY_CHIKORITA_BLACKTHORN, Blackthorn_City_Text_PhilipJFryIntro, Blackthorn_City_Text_PhilipJFryDefeat, Blackthorn_City_PhilipJFryGiveTM
	goto_if_set FLAG_FRY_GIVE_TM_BLACKTHORN, Blackthorn_City_PhilipJFry_EndingSpeech
	goto Blackthorn_City_PhilipJFryGiveTM

Blackthorn_City_PhilipJFryGiveTM::
	goto_if_set FLAG_FRY_GIVE_TM_BLACKTHORN, Blackthorn_City_PhilipJFry_EndingSpeech
	giveitem ITEM_TM_STOMPING_TANTRUM
	setflag FLAG_FRY_GIVE_TM_BLACKTHORN
	msgbox Blackthorn_City_Text_PhilipJFry_ExplainTM, MSGBOX_DEFAULT
	closemessage
	goto Blackthorn_City_PhilipJFry_EndingSpeech

Blackthorn_City_PhilipJFry_EndingSpeech::
	msgbox Blackthorn_City_Text_PhilipJFry_EndingSpeech, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, BlackthornCity_EventScript_FryExitEast
	call_if_eq VAR_FACING, DIR_NORTH, BlackthornCity_EventScript_FryExitOther
	call_if_eq VAR_FACING, DIR_WEST, BlackthornCity_EventScript_FryExitOther
	end

BlackthornCity_EventScript_FryExitEast::
	applymovement LOCALID_FRY_BLACKTHORN, BlackthornCity_Movement_Fry_Exit3
	waitmovement 0
	removeobject LOCALID_FRY_BLACKTHORN
	setflag FLAG_FRY_BLACKTHORN
	end

BlackthornCity_EventScript_FryExitOther::
	applymovement LOCALID_FRY_BLACKTHORN, BlackthornCity_Movement_Fry_Exit
	waitmovement 0
	removeobject LOCALID_FRY_BLACKTHORN
	setflag FLAG_FRY_BLACKTHORN
	end

BlackthornCity_Movement_Fry_Exit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BlackthornCity_Movement_Fry_Exit2::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BlackthornCity_Movement_Fry_Exit3::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BlackthornCity_Text_ClairNotReady:
	.string "You don't have seven badges?\n"
	.string "You can't fight Clair, dumbass!$"

BlackthornCity_Text_ClairIsIn:
	.string "Clair, our Gym Leader, is waiting\n"
	.string "for you, dumbass.\p"
	.string "However, it would be impossible for\n"
	.string "a run-of-the-mill trainer to win.$"

BlackthornCity_Text_ClairIsBeaten:
	.string "You defeated Clair?\p"
	.string "That's amazing!\p"
	.string "I've never heard of her losing to\n"
	.string "anyone other than Lance.$"

BlackthornGrampsRefusesEntryText:
	.string "No. Only chosen trainers may train\n"
	.string "here.\p"
	.string "Please leave.$"

BlackthornGrampsGrantsEntryText:
	.string "If Clair allows it, her grand-\n"
	.string "father--our MASTER--will also.\p"
	.string "You may enter.$"

BlackBeltText_VoicesInMyHead:
	.string "Arooo! Voices in my head!\p"
	.string "Huh? I'm listening to my radio!$"

BlackthornCooltrainerF1Text:
	.string "Are you going to make your Pokémon\n"
	.string "remember some moves?$"

BlackthornYoungsterText:
	.string "Dragon masters all come from the city\n"
	.string "of Blackthorn.$"

BlackthornCity_MeetSantosText:
	.string "Santos: …\p"
	.string "I'm SANTOS of the weekday family.\p"
	.string "Take a guess.$"

BlackthornCity_SantosGivesGiftText:
	.string "You can have this…$"

BlackthornCity_SantosGaveGiftText:
	.string "Santos: …\p"
	.string "SPELL TAG…\p"
	.string "GHOST-type moves get stronger…\p"
	.string "It will frighten you…$"

BlackthornCity_SantosSaturdayText:
	.string "Santos: …\p"
	.string "See you again on another Saturday…\p"
	.string "I won't have any more gifts…$"

BlackthornCity_SantosNopeText:
	.string "Santos: No.$"

BlackthornCooltrainerF2Text:
	.string "Wow, you came through the ICE PATH?\p"
	.string "You must be a real hotshot trainer!$"

BlackthornCitySignText:
	.string "Blackthorn City\p"
	.string "The city of black thorns.$"

BlackthornGymSignText:
	.string "Blackthorn City Pokémon Gym\n"
	.string "Leader: Clair\p"
	.string "The User of Dragon Types.$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "MOVE BROS' HOUSE$"

BlackthornCity_Text_DragonDenSign:
	.string "Dragon's Den Ahead$"

Blackthorn_City_Text_PhilipJFryIntro:
	.string "Philip J. Fry: Hey!\n"
	.string "Now it's time to face Clair, huh?\p"
	.string "Finally. Clay was super tough!\n"
	.string "Which order did you face them in?\p"
	.string "For me, it was Matt, then Bea,\n"
	.string "then finally Clay.\p"
	.string "Wonder what gimmick Clair will\n"
	.string "use in her battle.\p"
	.string "But first, I wanted to see if I was\n"
	.string "strong enough to face Clair.\p"
	.string "I've heard she's super tough!\p"
	.string "Let's have at it!$"

Blackthorn_City_Text_PhilipJFryDefeat:
	.string "I'll need more time to train my\n"
	.string "Pokémon before facing Clair!$"
	
Blackthorn_City_Text_PhilipJFry_ExplainTM:
	.string "This TM is Stomping Tantrum.\n"
	.string "It's good for dealing damage.\p"
	.string "If it misses, then on the next\n"
	.string "turn it will deal double damage!\p"
	.string "How about that for a move!$"
	
Blackthorn_City_Text_PhilipJFry_EndingSpeech:
	.string "I've heard there's a place\n"
	.string "called the Dragon's Den.\p"
	.string "It's got lots of Dragon-types\n"
	.string "which are the type of Pokémon\l"
	.string "that Clair would use.\l"
	.string "Let me know how that battle goes, okay?\p"
	.string "Good luck!$"
	