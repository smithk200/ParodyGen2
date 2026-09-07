AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "Are you able to buy a Great Ball?\n"
	.string "All I can buy are Poké Balls.\p"
	.string "I heard that more items become\n"
	.string "available to buy when you earn\l"
	.string "Gym Badges!\p"
	.string "I wish Kurt would make me some\n"
	.string "of his custom Balls.\p"
	.string "“Make my balls”, she said.$"

AzaleaMart_Text_BugCatcher:
	.string "A Great Ball is better for catching\n"
	.string "Pokémon than a Poké Ball.\p"
	.string "Great balls, great balls of fire!$"

