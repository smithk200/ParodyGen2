PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_GARBAGEFLAG
	end

PacifidlogTown_EventScript_BlackBelt::
	lock
	faceplayer
	msgbox PacifidlogTown_Text_WantToWarp, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Gym_Event_Script_WarpDude_No
	warp MAP_LILYCOVE_CITY, 24, 15
	release
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "The sea between Pacifidlog and\n"
	.string "Slateport has a fast-running tide.\p"
	.string "If you decide to Surf, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "See, isn't it neat?\n"
	.string "Team Magma has created some nice land\l"
	.string "for us!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "The Sky Pillar?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in Pacifidlog,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_TownSign:
	.string "Pacifidlog Town\p"
	.string "“Where Pikasprey loves to softlock\n"
	.string "unfortunate players.”$"

PacifidlogTown_Text_WantToWarp:
	.string "Oh, get me the fuck out of\n"
	.string "Pacifidlog Town,\l"
	.string "Pacifidlog Town,\l"
	.string "Pacifidlog Town,\p"
	.string "Oh, get me the fuck out of\n"
	.string "Pacifidlog Town…\p"
	.string "You want out too?\n"
	.string "I'll take you to Lilycove.$"