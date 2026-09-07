GrindhausRanch_EvTrainingRooms_MapScripts::
	.byte 0

EVTrainingRooms_Sign1::
	msgbox EVTrainingRooms_Sign1_Text, MSGBOX_DEFAULT
	releaseall
	end

EVTrainingRooms_Sign2::
	msgbox EVTrainingRooms_Sign2_Text, MSGBOX_DEFAULT
	releaseall
	end

EVTrainingRooms_Sign3::
	msgbox EVTrainingRooms_Sign3_Text, MSGBOX_DEFAULT
	releaseall
	end

EVTrainingRooms_Sign4::
	msgbox EVTrainingRooms_Sign4_Text, MSGBOX_DEFAULT
	releaseall
	end

EVTrainingRooms_Sign5::
	msgbox EVTrainingRooms_Sign5_Text, MSGBOX_DEFAULT
	releaseall
	end

EVTrainingRooms_Sign6::
	msgbox EVTrainingRooms_Sign6_Text, MSGBOX_DEFAULT
	releaseall
	end

EVTrainingRooms_Sign7::
	msgbox EVTrainingRooms_Sign7_Text, MSGBOX_DEFAULT
	releaseall
	end

EVTrainingRooms_Sign1_Text:
	.string "{LEFT_ARROW} HP\n"
	.string "{RIGHT_ARROW} Attack$"

EVTrainingRooms_Sign2_Text:
	.string "{LEFT_ARROW} Attack\n"
	.string "{RIGHT_ARROW} Defense$"

EVTrainingRooms_Sign3_Text:
	.string "{LEFT_ARROW} Defense\n"
	.string "{RIGHT_ARROW} Sp. Attack$"

EVTrainingRooms_Sign4_Text:
	.string "{LEFT_ARROW} Sp. Attack\n"
	.string "{RIGHT_ARROW} Sp. Defense$"

EVTrainingRooms_Sign5_Text:
	.string "{LEFT_ARROW} Sp. Defense\n"
	.string "{RIGHT_ARROW} Speed$"

EVTrainingRooms_Sign6_Text:
	.string "{LEFT_ARROW} Speed\n"
	.string "{RIGHT_ARROW} EXP$"

EVTrainingRooms_Sign7_Text:
	.string "{LEFT_ARROW} EXP\n"
	.string "{RIGHT_ARROW} Money$"
