Route130_Cave2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_Cave2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route130_Cave2_OnResume
	.byte 0

Route130_Cave2_OnResume:
	call_if_set FLAG_HIDE_ZACIAN, Route130_Cave2_EventScript_TryRemoveZacian
	call_if_set FLAG_HIDE_ZAMAZENTA, Route130_Cave2_EventScript_TryRemoveZacian
	end

Route130_Cave2_OnTransition:
	call_if_set FLAG_HIDE_ZACIAN, Route130_Cave2_EventScript_HideZacian
	call_if_unset FLAG_HIDE_ZACIAN, Route130_Cave2_EventScript_TryShowZacian
	call_if_set FLAG_HIDE_ZAMAZENTA, Route130_Cave2_EventScript_HideZamazenta
	call_if_unset FLAG_HIDE_ZAMAZENTA, Route130_Cave2_EventScript_TryShowZamazenta
	end

Route130_Cave2_EventScript_HideZacian::
	setflag FLAG_HIDE_ZACIAN
	return

Route130_Cave2_EventScript_TryShowZacian::
	goto_if_set FLAG_HIDE_ZACIAN, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ZACIAN
	return

Route130_Cave2_EventScript_HideZamazenta::
	setflag FLAG_HIDE_ZAMAZENTA
	return

Route130_Cave2_EventScript_TryShowZamazenta::
	goto_if_set FLAG_HIDE_ZAMAZENTA, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ZAMAZENTA
	return

Route130_Cave2_EventScript_TryRemoveZacian::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ROUTE130_ZACIAN
	return

Route130_Cave2_EventScript_TryRemoveZamazenta::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ROUTE130_ZAMAZENTA
	return

Route130_Cave2_EventScript_Zacian::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_ZACIAN, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ZACIAN, 70
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route130_Cave2_EventScript_DefeatedZacian
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route130_Cave2_EventScript_RanFromZacian
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route130_Cave2_EventScript_RanFromZacian
	setflag FLAG_HIDE_ZACIAN
	release
	end

Route130_Cave2_EventScript_DefeatedZacian::
	setflag FLAG_HIDE_ZACIAN
	setvar VAR_0x8004, SPECIES_ZACIAN
	goto Common_EventScript_LegendaryFlewAway
	end

Route130_Cave2_EventScript_RanFromZacian::
	setvar VAR_0x8004, SPECIES_ZACIAN
	goto Common_EventScript_LegendaryFlewAway
	end

Route130_Cave2_EventScript_Zamazenta::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_ZAMAZENTA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ZAMAZENTA, 70
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route130_Cave2_EventScript_DefeatedZamazenta
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route130_Cave2_EventScript_RanFromZamazenta
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route130_Cave2_EventScript_RanFromZamazenta
	setflag FLAG_HIDE_ZAMAZENTA
	release
	end

Route130_Cave2_EventScript_DefeatedZamazenta::
	setflag FLAG_HIDE_ZAMAZENTA
	setvar VAR_0x8004, SPECIES_ZAMAZENTA
	goto Common_EventScript_LegendaryFlewAway
	end

Route130_Cave2_EventScript_RanFromZamazenta::
	setvar VAR_0x8004, SPECIES_ZAMAZENTA
	goto Common_EventScript_LegendaryFlewAway
	end
