.set LOCALID_VIRIDIAN_BUGSY, 16

ViridianForest_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianForest_OnFrame
	.byte 0

ViridianForest_OnFrame::
    cleartrainerflag TRAINER_BUGSY_VIRIDIAN_2
    end

ViridianForest_EventScript_Bugsy::
	lock
	faceplayer
    goto_if_set FLAG_DEFEATED_BUGSY_VIRIDIAN, ViridianForest_EventScript_Bugsy2
	trainerbattle_single TRAINER_BUGSY_VIRIDIAN, ViridianForest_Text_BugsyIntro, ViridianForest_Text_BugsyDefeat, ViridianForest_EventScript_BugsyPostBattle
    end

ViridianForest_EventScript_BugsyPostBattle::
    msgbox ViridianForest_Text_BugsyPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_DEFEATED_BUGSY_VIRIDIAN
	clearflag FLAG_HIDE_DOJO_BUGSY
	release
	end

ViridianForest_Text_BugsyIntro:
	.string "Bugsy: They kicked me out of the\n"
	.string "Gym league because they said the Bug\l"
	.string "type sucks.\p"
	.string "Well, I can't say they're wrong.\p"
    .string "But I still love my precious bugs!\n"
    .string "They'll be ready to take on anything!$"

ViridianForest_Text_BugsyDefeat:
    .string "They were right.\n"
    .string "The Bug type DOES suck.$"

ViridianForest_Text_BugsyPostBattle:
    .string "Well, maybe I'll have the courage to fight\n"
    .string "you another time.\p"
    .string "But I'll let you know.\n"
    .string "You can fight Brie at the Saffron\n"
    .string "Dojo now.\p"
    .string "She's way stronger than me!$"

ViridianForest_EventScript_Bugsy2::
	lock
	faceplayer
	trainerbattle_single TRAINER_BUGSY_VIRIDIAN_2, ViridianForest_Text_BugsyIntro2, ViridianForest_Text_BugsyDefeat2, ViridianForest_EventScript_BugsyPostBattle2
	release
	end

ViridianForest_EventScript_BugsyPostBattle2::
    msgbox ViridianForest_Text_BugsyPostBattle2, MSGBOX_AUTOCLOSE
	release
	end

ViridianForest_EventScript_MaxPotion::
    finditem ITEM_MAX_POTION
    end

ViridianForest_EventScript_DireHit::
    finditem ITEM_DIRE_HIT
    end

ViridianForest_EventScript_Elixir::
    finditem ITEM_ELIXIR
    end

ViridianForest_EventScript_Revive::
    finditem ITEM_REVIVE
    end

ViridianForest_EventScript_FullRestore::
    finditem ITEM_FULL_RESTORE
    end

ViridianForest_EventScript_MaxEther::
    finditem ITEM_MAX_ETHER
    end

ViridianForest_EventScript_FullHeal::
    finditem ITEM_FULL_HEAL
    end

ViridianForest_Text_BugsyIntro2:
    .string "Back so soon?\p"
    .string "Well, then I'll show you what my\n"
    .string "bugs are made of!$"

ViridianForest_Text_BugsyDefeat2:
    .string "Really?\n"
    .string "After all my hard work and research?$"

ViridianForest_Text_BugsyPostBattle2:
    .string "Come back again to fight me another time!$"