Alola2_MapScripts::
	.byte 0

Alola1_EventScript_Boy1::
	lock
	faceplayer
	msgbox Alola1_Text_Boy1, MSGBOX_AUTOCLOSE
	release
	end

Alola1_Text_Boy1:
	.string "This isn't the Alola I remember…$"