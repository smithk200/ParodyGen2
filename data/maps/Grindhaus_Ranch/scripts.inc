Grindhaus_Ranch_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Grindhaus_Ranch_OnTransition
	.byte 0

Grindhaus_Ranch_OnTransition::
	setflag FLAG_SYS_NO_CATCHING
	end

Grindhaus_Ranch_OnFrame_ClearCatchingFlag::
	clearflag FLAG_SYS_NO_CATCHING
	end

GrindhausRanch_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EVReducingBerries
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GrindhausRanch_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GraindhausRanch_BattleItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GrindhausRanch_Mart_EventScript_Clerk3::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GraindhausRanch_MintsandAbilityPatches
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GrindhausRanch_Mart_EventScript_Clerk4::
	lock
	faceplayer
	msgbox GrindhausRanch_Mart_Text_Clerk4, MSGBOX_AUTOCLOSE
	release
	end

.align 2
EVReducingBerries:
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_NONE
	release
	end

.align 2
GraindhausRanch_BattleItems:
	.2byte ITEM_BRIGHT_POWDER
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_SOOTHE_BELL
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_AMULET_COIN
	.2byte ITEM_CLEANSE_TAG
	.2byte ITEM_SMOKE_BALL
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_LUCKY_EGG
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_SHELL_BELL
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_MUSCLE_BAND
	.2byte ITEM_WISE_GLASSES
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_POWER_HERB
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_METRONOME
	.2byte ITEM_IRON_BALL
	.2byte ITEM_LAGGING_TAIL
	.2byte ITEM_DESTINY_KNOT
	.2byte ITEM_BLACK_SLUDGE
	.2byte ITEM_GRIP_CLAW
	.2byte ITEM_STICKY_BARB
	.2byte ITEM_SHED_SHELL
	.2byte ITEM_BIG_ROOT
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_EVIOLITE
	.2byte ITEM_FLOAT_STONE
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_AIR_BALLOON
	.2byte ITEM_RED_CARD
	.2byte ITEM_RING_TARGET
	.2byte ITEM_BINDING_BAND
	.2byte ITEM_EJECT_BUTTON
	.2byte ITEM_WEAKNESS_POLICY
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_SAFETY_GOGGLES
	.2byte ITEM_ADRENALINE_ORB
	.2byte ITEM_TERRAIN_EXTENDER
	.2byte ITEM_PROTECTIVE_PADS
	.2byte ITEM_THROAT_SPRAY
	.2byte ITEM_EJECT_PACK
	.2byte ITEM_HEAVY_DUTY_BOOTS
	.2byte ITEM_BLUNDER_POLICY
	.2byte ITEM_ROOM_SERVICE
	.2byte ITEM_UTILITY_UMBRELLA
	.2byte ITEM_EVERSTONE
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_MAGNET
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_POISON_BARB
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_TWISTED_SPOON
	.2byte ITEM_SILVER_POWDER
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_DRAGON_FANG
	.2byte ITEM_BLACK_GLASSES
	.2byte ITEM_METAL_COAT
	.2byte ITEM_NONE
	release
	end

.align 2
GraindhausRanch_MintsandAbilityPatches:
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_NONE
	release
	end

GrindhausRanch_Mart_Text_Clerk4:
	.string "Hey, you can't get here yet!\p"
	.string "You have to prove your worth\n"
	.string "against Red first!$"