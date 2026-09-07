SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA_2, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_2, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_2, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "I'll show you the cool techniques\n"
	.string "I learned from our Leader Damian!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Please forgive me, Damian…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Watch what happens if you crack all\n"
	.string "the floor tiles.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "You came all the way here, but you won't\n"
	.string "get to see Damian.\p"
	.string "Not if you lose to me, you won't!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "You're strong!\n"
	.string "I was fooled by your cute looks!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "You might be good enough to avoid\n"
	.string "being wiped out in one hit by Damian.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "The sight of Damian conducting\n"
	.string "a battle…\p"
	.string "The very beauty of it compelled me to\n"
	.string "become a Trainer.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "You battled with more beauty than\n"
	.string "I could muster…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "The grace you bring to battle is\n"
	.string "fabulous.\p"
	.string "Oh… I'm so fortunate to have found\n"
	.string "Pokémon.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "I should teach you how harsh battles\n"
	.string "can be.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Oh.\n"
	.string "You're strong.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "I'll tell you something good.\p"
	.string "If you want to reach Damian, you\n"
	.string "need to walk on each floor tile once.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "Hey! I'm Damian's manager!\n"
	.string "At his restaurant, that is.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "Oh, hey!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Damian works his ass off, but\n"
	.string "some other members don't pull\l"
	.string "their weight.\p"
	.string "Like that one trainer on Route\n"
	.string "107.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "I train my Pokémon together with\n"
	.string "Damian.\p"
	.string "Don't think I'm a pushover.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "I was beaten…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "I think you have potential.\n"
	.string "Why don't you stay and train with us?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "A graceful glide across the ice while\n"
	.string "crossing no lines…\p"
	.string "A Trainer putting on that performance\n"
	.string "would be elegantly beautiful!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Well, excuse me?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "This is really obvious, but how strong\n"
	.string "you are as a Trainer has nothing to do\l"
	.string "with how young or old you are.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "When I'm with my Pokémon, the time\n"
	.string "flies by before you can say, “Oops!”$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Oops!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "I wish I could forget about lost causes\n"
	.string "before I can manage an “Oops!”$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "I can battle with really rare Pokémon\n"
	.string "if you'd like.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Oh, there now! Did you have a good look\n"
	.string "at my Pokémon?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "I came to this Gym because I pay\n"
	.string "Damian to do things to me…\p"
	.string "Oops, I said too much.$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Giggle…\n"
	.string "Your grim look is so charming.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Oh, dear.\n"
	.string "I went much too easy on you.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "You couldn't lay a finger on Damian,\n"
	.string "I'm sure. Giggle…$"

