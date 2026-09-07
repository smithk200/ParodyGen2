NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Father::
	lock
	faceplayer
	goto_if_unset FLAG_NUZLOCKE, NewBarkTown_House1_EventScript_FatherTalksAboutHisPreciousMachop
	goto_if_unset FLAG_RECEIVED_FIRST_BALLS, NewBarkTown_House1_EventScript_FatherNeedFirstMon
	goto_if_set FLAG_RECEIVED_MACHOP, NewBarkTown_House1_EventScript_FatherTakeGoodCareOfMachop
	msgbox NewBarkTown_House1_Text_Father, MSGBOX_DEFAULT
	givemon SPECIES_MACHOP, 5
	setflag FLAG_RECEIVED_MACHOP
	bufferspeciesname STR_VAR_1, SPECIES_MACHOP
	call Common_EventScript_GiftMon
	closemessage
	release
	end

NewBarkTown_House1_EventScript_FatherTalksAboutHisPreciousMachop::
	msgbox NewBarkTown_House1_Text_FatherTalksAboutHisPreciousMachop, MSGBOX_DEFAULT
	release
	end

NewBarkTown_House1_EventScript_FatherTakeGoodCareOfMachop::
	msgbox NewBarkTown_House1_Text_FatherTakeGoodCareOfMachop, MSGBOX_DEFAULT
	release
	end
	
NewBarkTown_House1_EventScript_FatherNeedFirstMon:
	msgbox NewBarkTown_House1_Text_FatherFatherNeedFirstMon, MSGBOX_DEFAULT
	release
	end

NewBarkTown_House1_Text_Father:
	.string "You heard of Youngster Joey, right?\p"
	.string "Well, his Rattata is in the top percentage\n"
	.string "of Rattatas.\p"
	.string "No, seriously!\n"
	.string "It has Wonder Guard as its ability.\p"
	.string "Don't wanna mess with that, huh?\p"
	.string "I have got just the mon for you!\n"
	.string "Come on, don't be shy about it!\p"
	.string "It's a Machop.$"

NewBarkTown_House1_Text_FatherTakeGoodCareOfMachop:
	.string "Take good care of Machop!$"

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "Pikachu is an evolved Pokémon.\p"
	.string "I was amazed by Prof. Elm's\n"
	.string "findings.\p"
	.string "He's so famous for his research\n"
	.string "on Pokémon evolution.\p"
	.string "…sigh…\p"
	.string "I wish I could be a researcher\n"
	.string "like him…$"

NewBarkTown_House1_Text_FatherFatherNeedFirstMon:
	.string "You need to visit\n"
	.string "Prof. Elm first!$"

NewBarkTown_House1_Text_Neighbor:
	.string "My daughter is adamant about\n"
	.string "becoming Prof. Elm's assistant.\p"
	.string "She really loves Pokémon!\p"
	.string "But then, so do I!$"

NewBarkTown_House1_Text_FatherTalksAboutHisPreciousMachop:
	.string "I just love my Machop.\p"
	.string "He likes to live in the boulders,\n"
	.string "just like some gamer my daughter\l"
	.string "watches on YouTube.\p"
	.string "If only I had a determined Trainer I\n"
	.string "could give him to…\p"
	.string "You don't seem ready for a challenge.$"