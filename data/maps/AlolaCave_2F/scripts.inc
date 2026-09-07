AlolaCave_2F_MapScripts::
	.byte 0

AlolaCave_2F_EventScript_Zacian::
	lock
	faceplayer
	playmoncry SPECIES_ZACIAN, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_ZACIAN, 60
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EmbeddedTower_EventScript_RayquazaRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ALOLA_CAVE_ZACIAN
	setflag FLAG_HIDE_ZACIAN
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

AlolaCave_2F_EventScript_Zamazenta::
	lock
	faceplayer
	playmoncry SPECIES_ZAMAZENTA, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_ZAMAZENTA, 60
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EmbeddedTower_EventScript_RayquazaRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ALOLA_CAVE_ZAMAZENTA
	setflag FLAG_HIDE_ZAMAZENTA
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end