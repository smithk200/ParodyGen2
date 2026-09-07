Route133_MapScripts::
	.byte 0

Route133_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_2, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Debra::
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Linda::
	trainerbattle_single TRAINER_LINDA_2, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Warren::
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Beck::
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Mollie::
	trainerbattle_single TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Conor::
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
	end

