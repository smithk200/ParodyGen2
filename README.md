# About `Pokémon Dark Gold Version`

I (smithk200) wanted to modify Pokémon HeartGold and SoulSilver, but am unfamiliar with Gen 4 decomp and don't want to make a binary hack of HGSS because *binary sucks*... I mean, binary is prone to crashes and requires a lot of tools to modify a ton of parameters. Plus, I want to make a challenge hack based around Johto that had features from later Pokémon games, such as Gen 6 EXP share (because grinding for EXP is no fun). Also, I wanted to add some other features to this game but simply do not have the time.

DISCLAIMER: This is not an official port of Pokémon Heart and Soul to pokeemerald-expansion; this is a fan-based project. This is not the 2.0 update, but if you don't want to wait for the official 2.0 update then this might be a good fit for you.
SECOND DISCLAIMER: This actually isn't the Hoenn in HnS hack that I'm working on! That's right here: https://github.com/smithk200/Gold-And-Silver-Gen-3-Decomp
Though this hack will have Hoenn in it.
This hack has a MATURE RATING! Explicit language is involved! Also some of the humor in this hack is mature! This is meant as a dark-humor take on Pokémon Gold and Silver!

## STORY CHANGES:
- It's a tradition of mine to include Philip J. Fry as a rival in every ROM hack I make. He's present in this hack as well! His role is basically to give you useful TMs, and he doesn't have much of a character arc.
- All the new Gym Leaders match their old counterpart's type specialty, except the first two Gym Leaders. Damian specializes in Food-themed Pokémon, which was based off an idea given to me by an IRL friend. The second Gym Leader, Brie, specializes in Fairy-type Pokémon because Fairy types need more representation and Bug type is pretty weak anyways. I am not a fan of the Bug type. Sorry, Bug-type lovers! (Side note: Aaron's pretty cool though)
- You have to defeat Clair a second time in Dragon's Den in order to get your badge. You pair up with Fry for this fight. Also, Clair seems to have matured more in this hack than her original character arc.

## LIST OF FEATURES:

Implemented

### MUSIC
- Music choices from Johto, Sinnoh, and custom Gym Leader music. The custom music option is enabled by default. 
- The Gym Leader theme is "Nonphysical" by Moon Hooch because of a YouTube comment saying that Nonphysical would be a good boss battle theme. You can listen to the song here: https://www.youtube.com/watch?v=jhyBa7lQNkI 
- Also each Elite Four member (currently limited to Johto) has their own battle music if you have the "Custom" option enabled.
- Kanto Gym Leaders use the Gym Leader theme from Pokémon X and Y.
- Hoenn Gym Leaders use the Typing Boss theme from Pokémon Typing Adventure. This theme is also used as a Gym Leader theme in Pokémon Wack.

### EVERYTHING ELSE
- Generation 6 EXP Share from the menu.
- Ability to toggle between the backgrounds used for HnS or the default ones from Hoenn.
- Auto-HMs from Pokémon Clover, where you don't need a prompt in order to use a field move.
- Difficulty mode. Easy gives double the EXP, Normal is normal EXP, and Hard mode is having a level cap which the highest level you can reach is the Gym Leader's ace Pokémon. Defeat the Gym Leaders to lift the cap.
- Battle Frontier! (After defeating Red, you gain the option of traveling to the Battle Frontier. You can leave from either Olivine or Vermilion. However, leaving the Battle Frontier takes you to Vermilion.)
- Bug catching contest (albeit with a few bugs)
- Optional Nuzlocke Mode. Note that this will use a no overleveling rule. If you use ANY item during combat, the only thing that will be different is that it will show a "Nuzlocke Complete!" at the Hall of Fame screen rather than "Hardcore Nuzlocked!"
- Options to run: Button Combo (L+A), (B), or Default. The reason why it's (L+A) is because of expansion's new feature where you select a Pokeball with the (R) button.
- The ability to Terrastallize after the 4th gym. Mega Stones will be added as well.
- Silly Scope (from my original HnS port) is not in this game. That's because it takes up too much ROM space and I don't think it's worth it here.
- This hack has the Galar and Paldean Stones, an item that evolves Pokémon to their regional forms. Though this only works for Ponyta/Rapidash currently.

Note: this uses 93.40% of ROM space, last I checked.

## CREDITS
- HnS Dev Team for their amazing work!
- RHH and pokeemerald expansion dev team, of course!
- NecroDingo- Nuzlocke mode (initial codebase)
- The Team Aqua Hideout discord for any bugs/problems that I had in this hack!


![Gif that shows debugging functionality that is unique to pokeemerald-expansion such as rerolling Trainer ID, Cheat Start, PC from Debug Menu, Debug PC Fill, Pokémon Sprite Visualizer, Debug Warp to Map, and Battle Debug Menu](https://github.com/user-attachments/assets/cf9dfbee-4c6b-4bca-8e0a-07f116ef891c) ![Gif that shows overworld functionality that is unique to pokeemerald-expansion such as indoor running, BW2 style map popups, overworld followers, DNA Splicers, Gen 1 style fishing, OW Item descriptions, Quick Run from Battle, Use Last Ball, Wild Double Battles, and Catch from EXP](https://github.com/user-attachments/assets/383af243-0904-4d41-bced-721492fbc48e) ![Gif that shows off a number of modern Pokémon battle mechanics happening in the pokeemerald-expansion engine: 2 vs 1 battles, modern Pokémon, items, moves, abilities, fully customizable opponents and partners, Trainer Slides, and generational gimmicks](https://github.com/user-attachments/assets/50c576bc-415e-4d66-a38f-ad712f3316be)

<!-- If you want to re-record or change these gifs, here are some notes that I used: https://files.catbox.moe/05001g.md -->

This is based off pokeemerald-expansion, which is documented below.

**`pokeemerald-expansion`** is a GBA ROM hack base that equips developers with a comprehensive toolkit for creating Pokémon ROM hacks. **`pokeemerald-expansion`** is built on top of [pret's `pokeemerald`](https://github.com/pret/pokeemerald) decompilation project. **It is not a playable Pokémon game on its own.** 

# [Features](FEATURES.md)

**`pokeemerald-expansion`** offers hundreds of features from various [core series Pokémon games](https://bulbapedia.bulbagarden.net/wiki/Core_series), along with popular quality-of-life enhancements designed to streamline development and improve the player experience. A full list of those features can be found in [`FEATURES.md`](FEATURES.md).

# [Credits](CREDITS.md)

 [![](https://img.shields.io/github/all-contributors/rh-hideout/pokeemerald-expansion/upcoming)](CREDITS.md)

If you use **`pokeemerald-expansion`**, please credit **RHH (Rom Hacking Hideout)**. Optionally, include the version number for clarity.
Also please credit the makers of Pokémon Heart and Soul because their assets are used too!
https://github.com/PokemonHnS-Development/pokemonHnS

```
Based off RHH's pokeemerald-expansion 1.13.3 https://github.com/rh-hideout/pokeemerald-expansion/
```

Please consider [crediting all contributors](CREDITS.md) involved in the project!

# Choosing `pokeemerald` or **`pokeemerald-expansion`**

- **`pokeemerald-expansion`** supports multiplayer functionality with other games built on **`pokeemerald-expansion`**. It is not compatible with official Pokémon games.
- If compatibility with official games is important, use [`pokeemerald`](https://github.com/pret/pokeemerald). Otherwise, we recommend using **`pokeemerald-expansion`**.
- **`pokeemerald-expansion`** incorporates regular updates from `pokeemerald`, including bug fixes and documentation improvements.

# [Getting Started](INSTALL.md)

❗❗ **Important**: Do not use GitHub's "Download Zip" option as it will not include commit history. This is necessary if you want to update or merge other feature branches. 

If you're new to git and GitHub, [Team Aqua's Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/) has a [guide to forking and cloning the repository](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/The-Basics-of-GitHub). Then you can follow one of the following guides:

## 📥 [Installing **`pokeemerald-expansion`**](INSTALL.md)
## 🏗️ [Building **`pokeemerald-expansion`**](INSTALL.md#Building-pokeemerald-expansion)
## 🚚 [Migrating from **`pokeemerald`**](INSTALL.md#Migrating-from-pokeemerald)
## 🚀 [Updating **`pokeemerald-expansion`**](INSTALL.md#Updating-pokeemerald-expansion)

# [Documentation](https://rh-hideout.github.io/pokeemerald-expansion/)

For detailed documentation, visit the [pokeemerald-expansion documentation page](https://rh-hideout.github.io/pokeemerald-expansion/).

# [Contributions](CONTRIBUTING.md)
If you are looking to [report a bug](CONTRIBUTING.md#Bug-Report), [open a pull request](CONTRIBUTING.md#Pull-Requests), or [request a feature](CONTRIBUTING.md#Feature-Request), our [`CONTRIBUTING.md`](CONTRIBUTING.md) has guides for each.

# [Community](https://discord.gg/6CzjAG6GZk)

[![](https://dcbadge.limes.pink/api/server/6CzjAG6GZk)](https://discord.gg/6CzjAG6GZk)

Our community uses the [ROM Hacking Hideout (RHH) Discord server](https://discord.gg/6CzjAG6GZk) to communicate and organize. Most of our discussions take place there, and we welcome anybody to join us!
