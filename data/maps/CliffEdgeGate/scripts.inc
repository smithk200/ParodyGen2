CliffEdgeGate_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "Did you know? There's a Safari Zone\n"
	.string "just around the corner.\p"
	.string "It's really fun!\n"
	.string "You will see many different kinds of\l"
	.string "Pokémon, and it's all you can catch!\p"
	.string "There is no reason not to go, right?\n"
	.string "Just around the corner.$"

CliffEdgeGate_Text_Expectations:
	.string "I don't know why I decided to come\n"
	.string "to that lame Safari Zone ayway.\p"
	.string "The Safari Zone's just plain awful,\n"
	.string "am I right or am I right?$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "Everything Is Thrilling!\n"
	.string "Explore to Find Wild Pokémon!\l"
	.string "Warden Baoba's Safari Zone\l"
	.string "Up and Running!$"

