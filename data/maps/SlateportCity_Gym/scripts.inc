SlateportCity_Gym_MapScripts::
	.byte 0

SlateportCity_Gym_EventScript_BlackBelt::
	lock
	faceplayer
	msgbox SlateportCity_Gym_Text_WantToWarp, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Gym_Event_Script_WarpDude_No
	warp MAP_SLATEPORT_CITY, 16, 20
	release
	end

SlateportCity_Gym_Event_Script_WarpDude_No::
	msgbox SlateportCity_Gym_Text_WarpDude_No, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_Gym_Text_WantToWarp:
	.string "Do you want to exit the Gym?$"

SlateportCity_Gym_Text_WarpDude_No:
	.string "Okay then!$"

SlateportCity_Gym_Event_Script_Marnie::
	trainerbattle_single TRAINER_MARNIE_1, SlateportCity_Gym_Text_MarnieIntro, SlateportCity_Gym_Text_MarnieDefeat, SlateportCity_Gym_EventScript_MarnieDefeated
	msgbox SlateportCity_Gym_Text_MarniePostBattle, MSGBOX_DEFAULT
	end

SlateportCity_Gym_EventScript_MarnieDefeated::
	setflag FLAG_BADGE17_GET
	message Slateport_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	waitfanfare
	closemessage
	delay 30
	release
	end

Slateport_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received Dark Badge from Marnie.$"

SlateportCity_Gym_Text_MarnieIntro:
	.string "Hey {PLAYER}…\p"
	.string "I just wanted to say…\n"
	.string "Thanks.\p"
	.string "Oh, I heard about your exploits\n"
	.string "regarding Team Rocket.\p"
	.string "Magnificent, they were.\p"
	.string "But now I got a Gym of my own.\p"
	.string "Piers… well…\n"
	.string "That's all I'll say.\p"
	.string "Let's battle, huh?$"

SlateportCity_Gym_Text_MarnieDefeat:
	.string "Oh.n"
	.string "Hey…\p"
	.string "Good fight.$"

SlateportCity_Gym_Text_MarniePostBattle:
	.string "Hey, that was a good fight.\n"
	.string "I'm sure that you can accomplish many great\l"
	.string "things on your own.$"