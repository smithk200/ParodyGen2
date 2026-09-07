AlolaCave_1F_MapScripts::
	.byte 0

AlolaCave_1F_EventScript_Hiker::
	lock
	faceplayer
	waitse
	msgbox AlolaCave_1F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

AlolaCave_1F_Text_Hiker:
	.string "Hey, kid!\p"
	.string "These Pokémon on the second floor\n"
	.string "are quite strong!\p"
	.string "You'll need to have eight Gym Badges,\n"
	.string "to pass through here, I reckon!$"