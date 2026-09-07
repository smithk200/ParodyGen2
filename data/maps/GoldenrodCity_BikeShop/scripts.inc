GoldenrodCity_BikeShop_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "Riding the bike is as simple as\n"
	.string "pressing a button if you\l"
	.string "register it from the bag.$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "Bikes are so fuckin' cheap,\n"
    .string "I'll give you one for free.$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "Really? Great!\p"
    .string "Give me your name and phone number,\n"
    .string "and I'll loan you a bicycle.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER} borrowed a bicycle.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "The main shop is at Cerulean back\n"
	.string "in Kanto.\p"
	.string "Say hello to the shop manager if\n"
	.string "if you happen to go there!\p"
	.string "There's also a guy in Hoenn who\n"
	.string "runs a bike shop as well.$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "Well, fuck you!$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "Just released!\p"
    .string "First-rate compact bicycles!$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "It's a shiny new bicycle!$"
