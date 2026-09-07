.set LOCALID_CELADON_FALKNER, 5

CeladonCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "Wassup, {PLAYER}! I didn't expect to\n"
	.string "see yo' ass here!\p"
	.string "I was looking for the vapes, but\n"
	.string "I guess they don't sell any at this\l"
	.string "joint.\p"
	.string "If you want to face me again, I'll\n"
	.string "be at the Dojo in Saffron City\p"
	.string "FUCK yeah!$"

CeladonDeptStore5F_Text_Gentleman:
	.string "I want to buy some items that\n"
	.string "raise Pokémon stats, but I don't\l"
	.string "have enough money…$"

CeladonDeptStore5F_Text_Sailor:
	.string "I want PP Up, so I can get my\n"
	.string "PP up.\p"
	.string "Wait? That's not what it's for?$"

CeladonDeptStore5F_Text_Teacher:
	.string "Using items on them makes Pokémon\n"
	.string "happy.\p"
	.string "They hate certain items, though…$"

CeladonDeptStore5F_Text_Directory:
	.string "5F: Drug Store$"
