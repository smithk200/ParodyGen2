EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call EverGrandeCity_ChampionsRoom_ClearEliteFourFlags
	end

EverGrandeCity_ChampionsRoom_ClearEliteFourFlags:
	clearflag FLAG_DEFEATED_SIDNEY
	clearflag FLAG_DEFEATED_PHOEBE
	clearflag FLAG_DEFEATED_GLACIA
	clearflag FLAG_DEFEATED_DRAKE
	clearflag FLAG_DEFEATED_FRY_EVER_GRANDE
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_PhilipJFryIntro
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_PhilipJFryIntro:
	goto_if_set FLAG_DEFEATED_FRY_ECRUTEAK, PokemonLeague_Fry_PhilipJFryExit
	msgbox EverGrandeCity_ChampionsRoom_TextPhilipJFryIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_STARTER_MON, 0, EverGrandeCity_ChampionsRoom_Fry_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, EverGrandeCity_ChampionsRoom_Fry_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, EverGrandeCity_ChampionsRoom_Fry_Battle_Chikorita
	end

EverGrandeCity_ChampionsRoom_Fry_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_FRY_CYNDAQUIL_EVER_GRANDE, EverGrandeCity_ChampionsRoom_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_EVER_GRANDE
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated

EverGrandeCity_ChampionsRoom_Fry_Battle_Totodile::
	trainerbattle_no_intro TRAINER_FRY_TOTODILE_EVER_GRANDE, EverGrandeCity_ChampionsRoom_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_EVER_GRANDE
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated

EverGrandeCity_ChampionsRoom_Fry_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_FRY_CHIKORITA_EVER_GRANDE, EverGrandeCity_ChampionsRoom_TextPhilipJFryDefeat
	setflag FLAG_DEFEATED_FRY_EVER_GRANDE
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	goto EverGrandeCity_ChampionsRoom_EventScript_ExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	end

EverGrandeCity_ChampionsRoom_EventScript_ExitForHoF::
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "Wallace: Welcome, {PLAYER}{KUN}.\p"
	.string "That incident in Sootopolis City…\n"
	.string "That was superb work, putting an end\l"
	.string "to that crisis all by yourself.\p"
	.string "Oops!\p"
	.string "It wouldn't be fair to say that you\n"
	.string "alone ended the crisis.\p"
	.string "You overcame that difficult situation\n"
	.string "by working as one with your Pokémon.\p"
	.string "We Trainers raise Pokémon by giving\n"
	.string "them items and by teaching them new\l"
	.string "techniques for battle.\p"
	.string "But we ourselves also learn many\n"
	.string "things from Pokémon.\p"
	.string "And this is where your achievements\n"
	.string "are put to the test against what\l"
	.string "others like you have achieved.\p"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their Pokémon in Hoenn?\p"
	.string "Show me right here and now!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "I, the Champion, fall in defeat…\p"
	.string "That was wonderful work.\n"
	.string "You were elegant, infuriatingly so.\l"
	.string "And yet it was utterly glorious!\p"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
	.string "You are a truly noble Pokémon\n"
	.string "Trainer!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "Wallace: The Pokémon you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "It was with light, yet surefooted,\n"
	.string "elegance that you led your Pokémon.\p"
	.string "Even I felt bedazzled by your\n"
	.string "masterful performance!\p"
	.string "You now stand at the glorious peak\n"
	.string "of the Pokémon League.\p"
	.string "I now proclaim you to be the new\n"
	.string "Hoenn region…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "May: {PLAYER}{KUN}!\p"
	.string "Here's some advice before you challenge\n"
	.string "the Champion…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "May: Huh?\n"
	.string "What, what, what?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Could it be that…\l"
	.string "It's already over?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "Brendan: {PLAYER}!\p"
	.string "How would you like some advice before\n"
	.string "you challenge the Champion?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "Brendan: {PLAYER}…\p"
	.string "Are you trying to tell me…\n"
	.string "You've beaten the Champion?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "Prof. Birch: See?\n"
	.string "What did I tell you, {RIVAL}?\p"
	.string "Didn't I tell you that you don't need\n"
	.string "to worry about {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
	.string "When I heard that you defeated your\n"
	.string "own father at the Petalburg Gym,\l"
	.string "I thought perhaps you had a chance…\p"
	.string "But to think you've actually become\n"
	.string "the Champion!\p"
	.string "Ah, yes!\p"
	.string "What became of your Pokédex?\n"
	.string "Here, let me see.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "Prof. Birch: Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "Wallace: {PLAYER}{KUN}…\p"
	.string "No, let me rephrase that properly.\p"
	.string "The new Champion!\p"
	.string "Come with me.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "Wallace: I'm sorry, but…\p"
	.string "From here on, only those Trainers who\n"
	.string "have become Champions may enter.\p"
	.string "You'll have to wait outside with\n"
	.string "Prof. Birch.$"

EverGrandeCity_ChampionsRoom_TextPhilipJFryIntro:
	.string "Hi, {PLAYER}!\n"
	.string "I've beaten all the Gym Leaders of\l"
	.string "Hoenn!\p"
	.string "Pretty neat, huh?\p"
	.string "So, {PLAYER}, you got all the badges too?\n"
	.string "That's great!\p"
	.string "And you got past the Elite Four…\n"
	.string "They weren't easy, let me tell you that.\p"
	.string "But if I can make it, so can you!\p"
	.string "Come on, {PLAYER}!\p"
	.string "It's time for our epic final battle!$"

EverGrandeCity_ChampionsRoom_TextPhilipJFryDefeat:
	.string "Well, that's that!\n"
	.string "Good game, {PLAYER}.$"

EverGrandeCity_ChampionsRoom_TextPhilipJFryPostBattle:
	.string "Wow, {PLAYER}!\n"
	.string "I'm impressed!\p"
	.string "You're way more powerful than I anticipated!\p"
	.string "Well, according to that Professor Birch guy,\n"
	.string "we need to register you in the Hall of Fame…\p"
	.string "(Sigh…)\p"
	.string "I barely got to hold my title as Champion…\p"
	.string "Damn him and his stupid rules!\p"
	.string "Anyway, follow me.$"