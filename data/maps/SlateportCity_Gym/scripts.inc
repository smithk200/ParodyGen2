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