EeveeFarm_MapScripts::
	.byte 0

EeveeFarm_EventScript_Woman1::
	lock
	faceplayer
	msgbox EeveeFarm_Text_Woman1, MSGBOX_DEFAULT
	release
	end

EeveeFarm_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EeveeFarm_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EeveeFarm_Text_Woman1:
	.string "We raise Eevee at the Eevee Farm.\p"
	.string "Once they're old enough, they\n"
	.string "can be caught by adventurous Trainers.$"

EeveeFarm_Text_Eevee:
	.string "Eevee: Boy!$"