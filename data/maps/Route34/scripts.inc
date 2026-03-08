.set LOCALID_ROUTE34_DAYCAREMAN, 12

Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Fry::
	goto_if_eq VAR_STARTER_MON, 0, Route34_Fry_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, Route34_Fry_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, Route34_Fry_Battle_Chikorita
	end

Route34_Fry_Battle_Cyndaquil::
	trainerbattle_single TRAINER_FRY_CYNDAQUIL_ROUTE_34, Route34_Text_PhilipJFryIntro, Route34_Text_PhilipJFryDefeat, Route34_PhilipJFryGiveTM
	goto_if_set FLAG_FRY_GIVE_TM_ROUTE_34, Route34_PhilipJFry_EndingSpeech
	goto Route34_PhilipJFryGiveTM

Route34_Fry_Battle_Totodile::
	trainerbattle_single TRAINER_FRY_TOTODILE_ROUTE_34, Route34_Text_PhilipJFryIntro, Route34_Text_PhilipJFryDefeat, Route34_PhilipJFryGiveTM
	goto_if_set FLAG_FRY_GIVE_TM_ROUTE_34, Route34_PhilipJFry_EndingSpeech
	goto Route34_PhilipJFryGiveTM

Route34_Fry_Battle_Chikorita::
	trainerbattle_single TRAINER_FRY_CHIKORITA_ROUTE_34, Route34_Text_PhilipJFryIntro, Route34_Text_PhilipJFryDefeat, Route34_PhilipJFryGiveTM
	goto_if_set FLAG_FRY_GIVE_TM_ROUTE_34, Route34_PhilipJFry_EndingSpeech
	goto Route34_PhilipJFryGiveTM

Route34_PhilipJFryGiveTM::
	goto_if_set FLAG_FRY_GIVE_TM_ROUTE_34, Route34_PhilipJFry_EndingSpeech
	giveitem ITEM_TM_ICE_BEAM
	setflag FLAG_FRY_GIVE_TM_ROUTE_34
	msgbox Route34_Text_PhilipJFry_ExplainIceBeam, MSGBOX_DEFAULT
	closemessage
	goto Route34_PhilipJFry_EndingSpeech

Route34_PhilipJFry_EndingSpeech::
	msgbox Route34_Text_PhilipJFry_EndingSpeech, MSGBOX_DEFAULT
	closemessage
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

Route34_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end


Route34_Text_YoungsterSamuel_Seen:
	.string "Hey! I'm looking for Mankey!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Beaten by a passing stranger!$"

Route34_Text_YoungsterSamuel_After:
	.string "I'm going to train even harder.\p"
	.string "After all, I'm trying to become\n"
	.string "a Gym Leader.$"

Route34_Text_YoungsterIan_Seen:
	.string "I'm the best in my class at\n"
	.string "Pokémon.$"

Route34_Text_YoungsterIan_Beaten:
	.string "No! There are better trainers…$"

Route34_Text_YoungsterIan_After:
	.string "I'm trying hard so I can be the\n"
	.string "star in my class.$"

Route34_Text_CamperTodd_Seen:
	.string "I'm confident in my ability to\n"
	.string "raise Pokémon.\p"
	.string "Want to see?$"

Route34_Text_CamperTodd_Beaten:
	.string "Did I screw up my training?$"

Route34_Text_CamperTodd_After:
	.string "Maybe I should take one to Day-Care,\n"
	.string "or maybe use some items…$"

Route34_Text_PicnickerGina_Seen:
	.string "Are you a trainer?\p"
	.string "Let's have a practice battle.$"

Route34_Text_PicnickerGina_Beaten:
	.string "Oh, no! I just can't win…$"

Route34_Text_PicnickerGina_After:
	.string "You're too strong to be a\n"
	.string "practice partner.$"

Route34_Text_OfficerKeith_Seen:
	.string "Who goes there?\n"
	.string "What are you up to?$"

Route34_Text_OfficerKeith_Win:
	.string "You're a tough little kid.$"

Route34_Text_OfficerKeith_After:
	.string "Yep, nothing wrong today.\p"
	.string "Be good and stay out of trouble.$"

Route34_Text_OfficerKeith_Daytime:
	.string "I'm on patrol for suspicious\n"
	.string "individuals.$"

Route34_Text_PokefanBrandon_Seen:
	.string "I just got my Pokémon back from\n"
	.string "Day-Care.\p"
	.string "Let's see how much stronger it got!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "Why does it end this way?$"

Route34_Text_PokefanBrandon_After:
	.string "My Pokémon came back with new moves.\p"
	.string "That confounded me to no end!$"

Route34_Text_Sign_IlexForest:
	.string "Ilex Forest\n"
	.string "Through the Gate$"

Route34_Text_Sign_Route34:
	.string "Route 34\n"
	.string "No Rule 34 on these premises!\p"
	.string "Goldenrod City - Azalea Town\p"
	.string "Ilex Forest somewhere between$"

Route34_Text_TrainerTips:
	.string "Trainer Tips!\p"
	.string "When working a job, be sure\n"
	.string "to find out if there's a union\l"
	.string "you can join.\p"
	.string "Sure, union dues can be around\n"
	.string "thirty to fifty dollars, but they\l"
	.string "will cover your back in case you get\l"
	.string "in trouble.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "Irene: Kyaaah! Someone found us!$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "Irene: Ohhh! You're too strong!$"

Route34_Text_CooltrainerIrene_After1:
	.string "Irene: My sister Kate will get you\n"
	.string "for this!$"

Route34_Text_CooltrainerIrene_After2:
	.string "Irene: Isn't this beach great?\p"
	.string "It's our secret little getaway!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "Jenn: You can't beat Irene and go\n"
	.string "unpunished!$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "Jenn: So sorry, Irene! Dear Sis!$"

Route34_Text_CooltrainerJenn_After1:
	.string "Jenn: Don't get cocky! My sister\n"
	.string "Kate is tough!$"

Route34_Text_CooltrainerJenn_After2:
	.string "Jenn: Sunlight makes your body\n"
	.string "stronger.$"

Route34_Text_CooltrainerKate_Seen:
	.string "Kate: You sure were mean to my\n"
	.string "little sisters!$"

Route34_Text_CooltrainerKate_Beaten:
	.string "Kate: No! I can't believe I lost.$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "Kate: You're too strong. I didn't\n"
	.string "stand a chance. Here, you deserve\n"
	.string "this.$"

Route34_Text_CooltrainerKate_After:
	.string "Kate: I'm sorry we jumped you.\p"
	.string "We never expected anyone to find\n"
	.string "us here. You sure startled us.$"


Route34_Text_Sign_DayCare:
	.string "Pokémon Day Care\p"
	.string "Gain Exp just by simply walking!$"

Route34_Text_PhilipJFryIntro:
	.string "Philip J. Fry: Hi there!\p"
	.string "I'm going to face the Gym Leader\n"
	.string "of Goldenrod City pretty soon.\p"
	.string "I've heard he's pretty tough!\n"
	.string "…And he's from Hoenn?\p"
	.string "Why, oh why did they have to\n"
	.string "recruit a leader from Hoenn, the\l"
	.string "most boring region ever to exist?\p"
	.string "Oh well.\p"
	.string "I'm here to test my strength against you\n"
	.string "before I face him.$"

Route34_Text_PhilipJFryDefeat:
	.string "I need to train my Pokémon\n"
	.string "up some more!$"
	
Route34_Text_PhilipJFry_ExplainIceBeam:
	.string "This Tm is Ice Beam.\p"
	.string "It will shoot a ray of ice at\n"
	.string "your foes.\p"
	.string "There's also a chance it\n"
	.string "can freeze them solid!$"
	
Route34_Text_PhilipJFry_EndingSpeech:
	.string "Well, I'm going to train here\n"
	.string "on Route 34 some more before\l"
	.string "fighting Norman.\p"
	.string "If he's anything like he was back\n"
	.string "in New Hoenn, he's going to be\l"
	.string "one tough cookie!\p"
	.string "Good luck!$"
	