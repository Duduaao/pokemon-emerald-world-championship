// ============================================================
// PEWC — Dados de Treinadores Competitivos (IDs corrigidos)
// ============================================================
#include "global.h"
#include "data.h"
#include "constants/spreads.h"
#include "constants/items.h"
#include "constants/natures.h"
#include "generated/constants/species.h"
#include "generated/constants/moves.h"

// Macro de treinador com spread + moves + EVs + nature + ability
#define TRAINERMON(s, lvl, held, abil, spread, m1, m2, m3, m4, nat, ea) \
  { lvl, s, held, abil, spread, {{ m1, m2, m3, m4 }}, 0, { 252,252,4,0,0,0 }, nat, FALSE, ea }

#define TERM { 0, SPECIES_NONE, ITEM_NONE, 0, 0, {{ MOVE_NONE,MOVE_NONE,MOVE_NONE,MOVE_NONE }}, 0, {0,0,0,0,0,0}, NATURE_HARDY, FALSE, FALSE }

// ABILITY IDs (0=primeira, 1=segunda, 2=hidden) — não temos enum explícito,
// mas o campo é u8 e o código usa 0=primeira habilidade, 1=segunda, 2=hidden.
// Por segurança, usamos.capacity=0 (primeira habilidade do Pokémon) ou 1 (segunda)
// conforme o caso. Para fakemon/POKÉMON não-existentes, não incluir.

// ============================================================
// ROXANNE — Ginásio 1
// Pidgeot4 (x2), Mankey(x2), Quagsire, Gyarados
// ============================================================
static const TrainerMonItemCustomMoves pewc_roxanne_party[] = {
    // Pidgeot — spread atk/spd adamant
    TRAINERMON(SPECIES_PIDGEOT, 17, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_WING_ATTACK, MOVE_ROOST, MOVE_RETURN, MOVE_FURY_ATTACK, NATURE_ADAMANT, FALSE),
    // Mankey — spread atk/spd adamant
    TRAINERMON(SPECIES_MANKEY, 16, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_KARATE_CHOP, MOVE_RETURN, MOVE_RETURN, MOVE_FLARMS, NATURE_ADAMANT, FALSE),
    // Quagsire — spread hp/def bold
    TRAINERMON(SPECIES_QUAGSIRE, 15, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_EARTHPOWER, MOVE_HEAD_SMASH, MOVE_BODY_SLAM, MOVE_RETURN, NATURE_BOLD, FALSE),
    // Gyarados — spread atk/spd adamant
    TRAINERMON(SPECIES_GYARADOS, 17, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_ICEFANG, MOVE_EARTHPOWER, MOVE_RETURN, MOVE_MEGA_KICK, NATURE_ADAMANT, FALSE),
    // Sneasel — spread atk/spd adamant
    TRAINERMON(SPECIES_SNEASEL, 16, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_KNOCK_OFF, MOVE_QUICK_ATTACK, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Zubat — spread atk/spd adamant
    TRAINERMON(SPECIES_ZUBAT, 15, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// BRAWLY — Ginásio 2
// Typhlosion, Hitmonlee, Onix, Golem, Rhyhorn, Rhydon
// ============================================================
static const TrainerMonItemCustomMoves pewc_brawly_party[] = {
    // Typhlosion — spread atk/spd jolly
    TRAINERMON(SPECIES_TYPHLOSION, 19, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_FLAMETHROWER, MOVE_CROSS_CHOP, MOVE_QUICK_ATTACK, MOVE_FIRE_SPIN, NATURE_JOLLY, FALSE),
    // Hitmonlee — spread atk/spd adamant
    TRAINERMON(SPECIES_HITMONLEE, 18, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_DIVING_PUNCH, MOVE_RETURN, MOVE_KNOCK_OFF, MOVE_COUNTER, NATURE_ADAMANT, FALSE),
    // Onix — spread hp/def bald
    TRAINERMON(SPECIES_ONIX, 18, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_ROCK_SLIDE, MOVE_EARTHPOWER, MOVE_HYPER_BEAM, MOVE_ENDURE, NATURE_BALD, FALSE),
    // Golem — spread hp/def bald
    TRAINERMON(SPECIES_GOLEM, 19, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_ROCK_BLAST, MOVE_EARTHPOWER, MOVE_ROCK_SLIDE, MOVE_SELF_DESTRUCT, NATURE_BALD, FALSE),
    // Rhyhorn — spread atk/spd adamant
    TRAINERMON(SPECIES_RHYHORN, 17, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_EARTHPOWER, MOVE_FIRE_BLAST, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Rhydon — spread atk/spd adamant
    TRAINERMON(SPECIES_RHYDON, 18, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_POLTERGEIST, MOVE_HYPER_BEAM, MOVE_RETURN, MOVE_EARTHPOWER, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// WATSON — Ginásio 3
// Raichu, Skarmory, Jolteon, Electabuzz, Magnemite, Flaaffy
// ============================================================
static const TrainerMonItemCustomMoves pewc_watson_party[] = {
    // Raichu — spread atk/spd adamant
    TRAINERMON(SPECIES_RAICHU, 22, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_THUNDER, MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Skarmory — spread atk/spd adamant
    TRAINERMON(SPECIES_SKARMORY, 22, ITEM_EVIOLITE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_AERIAL_ACE, MOVE_RETURN, MOVE_ROCK_SLIDE, MOVE_CALM_MIND, NATURE_ADAMANT, FALSE),
    // Jolteon — spread atk/spd jolly
    TRAINERMON(SPECIES_JOLTEON, 21, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_THUNDER, MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_RETURN, NATURE_JOLLY, FALSE),
    // Electabuzz — spread atk/spd jolly
    TRAINERMON(SPECIES_ELECTABUZZ, 21, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_THUNDER, MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_RETURN, NATURE_JOLLY, FALSE),
    // Magnemite — spread hp/def bald
    TRAINERMON(SPECIES_MAGNETONE, 20, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_DISCHARGE, MOVE_RETURN, MOVE_RETURN, MOVE_STEEL_WING, NATURE_BALD, FALSE),
    // Flaaffy — spread atk/spd jolly
    TRAINERMON(SPECIES_FLAFFY, 20, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_THUNDER, MOVE_RETURN, NATURE_JOLLY, FALSE),
    TERM
};

// ============================================================
// FLANNERY — Ginásio 4
// Typhlosion, Magmar, Crobat, Goldeen, Ninetales, Arcanine
// ============================================================
static const TrainerMonItemCustomMoves pewc_flannery_party[] = {
    // Typhlosion — spread atk/spd jolly
    TRAINERMON(SPECIES_TYPHLOSION, 24, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_FLAMETHROWER, MOVE_CROSS_CHOP, MOVE_QUICK_ATTACK, MOVE_FIRE_SPIN, NATURE_JOLLY, FALSE),
    // Magmar — spread atk/spd adamant
    TRAINERMON(SPECIES_MAGMAR, 23, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_FIRE_BLAST, MOVE_RETURN, MOVE_EARTHPOWER, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Crobat — spread atk/spd adamant
    TRAINERMON(SPECIES_CROBAT, 23, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Goldeen — spread hp/spdef calm
    TRAINERMON(SPECIES_GOLDEEN, 23, ITEM_NONE, 0, SPREAD_31_IV_HP_SPDEF_CALM,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_SURF, NATURE_CALM, FALSE),
    // Ninetales — spread spatk/spd modest
    TRAINERMON(SPECIES_NINETALES, 23, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_FIRE_BLAST, MOVE_RETURN, MOVE_RETURN, MOVE_AURORA_BEAM, NATURE_MODEST, FALSE),
    // Arcanine — spread atk/spd adamant
    TRAINERMON(SPECIES_ARCANINE, 24, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_FIRE_BLAST, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// NORMAN — Ginásio 5
// Tyrogue, Hitmonchan, Donphan, Quagsire, Dugtrio, Rhydon
// ============================================================
static const TrainerMonItemCustomMoves pewc_norman_party[] = {
    // Tyrogue — spread atk/spd adamant
    TRAINERMON(SPECIES_TYROGUE, 23, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_KARATE_CHOP, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Hitmonchan — spread atk/spd bald
    TRAINERMON(SPECIES_HITMONCHAN, 22, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_REVERSAL, MOVE_KARATE_CHOP, MOVE_RETURN, MOVE_RETURN, NATURE_BALD, FALSE),
    // Donphan — spread hp/def bold
    TRAINERMON(SPECIES_DONPHAN, 23, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_ROCK_SLIDE, MOVE_RETURN, MOVE_CROSSLY, MOVE_RETURN, NATURE_BALD, FALSE),
    // Quagsire — spread hp/def bold
    TRAINERMON(SPECIES_QUAGSIRE, 23, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_EARTHPOWER, MOVE_BODY_SLAM, MOVE_HEAD_SMASH, MOVE_RETURN, NATURE_BALD, FALSE),
    // Dugtrio — spread atk/spd jolly
    TRAINERMON(SPECIES_DUGTRIO, 22, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_JOLLY, FALSE),
    // Rhydon — spread atk/spd adamant
    TRAINERMON(SPECIES_RHYDON, 23, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_POLTERGEIST, MOVE_HYPER_BEAM, MOVE_RETURN, MOVE_EARTHPOWER, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// WALLACE — Ginásio 6
// Stantler, Ampharos, Quagsire, Gyarados, Lanturn, Gorebyss
// ============================================================
static const TrainerMonItemCustomMoves pewc_wallace_party[] = {
    // Stantler — spread atk/spd adamant
    TRAINERMON(SPECIES_STANTLER, 39, ITEM_CHOICE_BAND, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Ampharos — spread spatk/spd modest
    TRAINERMON(SPECIES_AMPHAROS, 40, ITEM_CHOICE_SPECS, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_THUNDERTACK, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Quagsire — spread hp/def bold
    TRAINERMON(SPECIES_QUAGSIRE, 39, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_EARTHPOWER, MOVE_HEAD_SMASH, MOVE_BODY_SLAM, MOVE_RETURN, NATURE_BALD, FALSE),
    // Gyarados — spread atk/spd adamant
    TRAINERMON(SPECIES_GYARADOS, 40, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_ICEFANG, MOVE_EARTHPOWER, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Lanturn — spread spatk/spd modest
    TRAINERMON(SPECIES_LANTURN, 40, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Gorebyss — spread atk/spd adamant? (usamos atk/spd adamant)
    TRAINERMON(SPECIES_GOREBYSS, 39, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// TATE & LIZA — Ginásio 7
// Tyranitar, Larvitar, Pupitar, Tyrogue, Hitmontop, Hitmonchan
// ============================================================
static const TrainerMonItemCustomMoves pewc_tate_liza_party[] = {
    // Tyranitar — spread atk/spd adamant
    TRAINERMON(SPECIES_TYRANITAR, 29, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Larvitar — spread atk/spd adamant
    TRAINERMON(SPECIES_LARVITAR, 28, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Pupitar — spread atk/spd adamant
    TRAINERMON(SPECIES_PUPITAR, 29, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Tyrogue — spread atk/spd brave (trick room physical attacker)
    TRAINERMON(SPECIES_TYROGUE, 30, ITEM_NONE, 0, SPREAD_31_IV_HP_ATK_BRAVE,
              MOVE_KARATE_CHOP, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_BRAVE, FALSE),
    // Hitmontop — spread atk/spd brave
    TRAINERMON(SPECIES_HITMONTOP, 30, ITEM_NONE, 0, SPREAD_31_IV_HP_ATK_BRAVE,
              MOVE_KARATE_CHOP, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_BRAVE, FALSE),
    // Hitmonchan — spread atk/spd brave
    TRAINERMON(SPECIES_HITMONCHAN, 29, ITEM_NONE, 0, SPREAD_31_IV_HP_ATK_BRAVE,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_BRAVE, FALSE),
    TERM
};

// ============================================================
// JUAN — Ginásio 8
// Sneasel, Skarmory, Crobat, Starmie, Lanturn, Electabuzz
// ============================================================
static const TrainerMonItemCustomMoves pewc_juan_party[] = {
    // Sneasel — spread atk/spd adamant
    TRAINERMON(SPECIES_SNEASEL, 31, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_KNOCK_OFF, MOVE_QUICK_ATTACK, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Skarmory — spread atk/spd adamant
    TRAINERMON(SPECIES_SKARMORY, 32, ITEM_EVIOLITE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_AERIAL_ACE, MOVE_RETURN, MOVE_ROCK_SLIDE, MOVE_CALM_MIND, NATURE_ADAMANT, FALSE),
    // Crobat — spread atk/spd jolly (com quick claw)
    TRAINERMON(SPECIES_CROBAT, 31, ITEM_QUICK_CLAW, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_RETURN, NATURE_JOLLY, FALSE),
    // Starmie — spread hp/spdef calm
    TRAINERMON(SPECIES_STARMIE, 31, ITEM_NONE, 0, SPREAD_31_IV_HP_SPDEF_CALM,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_CALM, FALSE),
    // Lanturn — spread spatk/spd modest
    TRAINERMON(SPECIES_LANTURN, 32, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Electabuzz — spread atk/spd jolly
    TRAINERMON(SPECIES_ELECTABUZZ, 31, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_THUNDER, MOVE_RETURN, MOVE_QUICK_ATTACK, MOVE_RETURN, NATURE_JOLLY, FALSE),
    TERM
};

// ============================================================
// SIDNEY — Elite Four #1 (Luta)
// Hitmontop, Hitmonchan, Hitmonlee, Rhyperior, Donphan, Rhydon
// ============================================================
static const TrainerMonItemCustomMoves pewc_sidney_party[] = {
    // Hitmontop — spread atk/spd adamant
    TRAINERMON(SPECIES_HITMONTOP, 38, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_KARATE_CHOP, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Hitmonchan — spread atk/spd bald
    TRAINERMON(SPECIES_HITMONCHAN, 37, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_REVERSAL, MOVE_KARATE_CHOP, MOVE_RETURN, MOVE_RETURN, NATURE_BALD, FALSE),
    // Hitmonlee — spread atk/spd adamant
    TRAINERMON(SPECIES_HITMONLEE, 38, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_DIVING_PUNCH, MOVE_RETURN, MOVE_KNOCK_OFF, MOVE_COUNTER, NATURE_ADAMANT, FALSE),
    // Rhydon — spread atk/spd adamant
    TRAINERMON(SPECIES_RHYDON, 39, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_POLTERGEIST, MOVE_HYPER_BEAM, MOVE_RETURN, MOVE_EARTHPOWER, NATURE_ADAMANT, FALSE),
    // Donphan — spread atk/spd adamant
    TRAINERMON(SPECIES_DONPHAN, 37, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_CROSSLY, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Rhydon — spread atk/spd adamant
    TRAINERMON(SPECIES_RHYDON, 38, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_POLTERGEIST, MOVE_HYPER_BEAM, MOVE_RETURN, MOVE_EARTHPOWER, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// PHOEBE — Elite Four #2 (Veneno)
// Venomoth(x2), Cloyster, Seadra, Seaking
// ============================================================
static const TrainerMonItemCustomMoves pewc_phoebe_party[] = {
    // Venomoth — spread spatk/spd modest
    TRAINERMON(SPECIES_VENOMOTH, 34, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_SLUDGE_BOMB, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Cloyster — spread hp/spdef calm
    TRAINERMON(SPECIES_CLOYSTER, 35, ITEM_NONE, 0, SPREAD_31_IV_HP_SPDEF_CALM,
              MOVE_ICICLE_SPEAR, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_CALM, FALSE),
    // Seadra — spread spatk/spd modest
    TRAINERMON(SPECIES_SEADRA, 35, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Seaking — spread spatk/spd modest
    TRAINERMON(SPECIES_SEAKING, 34, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Venomoth (segundo) — spread spatk/spd modest
    TRAINERMON(SPECIES_VENOMOTH, 35, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Venomoth (terceiro) — spread spatk/spd modest
    TRAINERMON(SPECIES_VENOMOTH, 34, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    TERM
};

// ============================================================
// GLACIA (GLORIA) — Elite Four #3 (Gelo)
// Cloyster, Sneasel, Piloswine, Lickitung, Lapras
// ============================================================
static const TrainerMonItemCustomMoves pewc_gloria_party[] = {
    // Cloyster — spread hp/def bold
    TRAINERMON(SPECIES_CLOYSTER, 36, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_ICICLE_SPEAR, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_BALD, FALSE),
    // Sneasel — spread atk/spd adamant
    TRAINERMON(SPECIES_SNEASEL, 35, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_KNOCK_OFF, MOVE_QUICK_ATTACK, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Piloswine — spread atk/spd adamant
    TRAINERMON(SPECIES_PILOSWINE, 35, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Lickitung — spread hp/def bold
    TRAINERMON(SPECIES_LICKTUNG, 34, ITEM_NONE, 0, SPREAD_31_IV_HP_DEF_BOLD,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_BALD, FALSE),
    // Lapras — spread spatk/spd modest
    TRAINERMON(SPECIES_LAPRAS, 35, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Sneasel (segundo) — spread atk/spd adamant
    TRAINERMON(SPECIES_SNEASEL, 34, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_KNOCK_OFF, MOVE_QUICK_ATTACK, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// DRAKE — Elite Four #4 (Dragão)
// Salamence, Dragonite(x2), Dragonair, Onix, Rhydon, Arcanine
// ============================================================
static const TrainerMonItemCustomMoves pewc_drake_party[] = {
    // Salamence — spread spatk/spd modest (especialista)
    TRAINERMON(SPECIES_SALAME, 39, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_DRAGON_PULSE, MOVE_DRAGON_DANCE, MOVE_EARTHPOWER, MOVE_HYPER_BEAM, NATURE_MODEST, FALSE),
    // Dragonite — spread atk/spd adamant
    TRAINERMON(SPECIES_DRAGONITE, 40, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_HYPER_BEAM, NATURE_ADAMANT, FALSE),
    // Dragonair — spread spatk/spd modest
    TRAINERMON(SPECIES_DRAGONAIR, 39, ITEM_NONE, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_MODEST, FALSE),
    // Onix — spread atk/spd adamant
    TRAINERMON(SPECIES_ONIX, 38, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_ROCK_SLIDE, MOVE_EARTHPOWER, MOVE_HYPER_BEAM, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Rhydon — spread atk/spd adamant
    TRAINERMON(SPECIES_RHYDON, 39, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_POLTERGEIST, MOVE_HYPER_BEAM, MOVE_RETURN, MOVE_EARTHPOWER, NATURE_ADAMANT, FALSE),
    // Arcanine — spread atk/spd adamant
    TRAINERMON(SPECIES_ARCANINE, 38, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// STEVEN — Campeão
// Metagross, Salamence, Empoleon, Lucario, Gyarados, Gengar
// ============================================================
static const TrainerMonItemCustomMoves pewc_steven_party[] = {
    // Metagross (ground?) — spread atk/spd adamant
    TRAINERMON(SPECIES_METAGROSS, 50, ITEM_CHOICE_BAND, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_IRON_HEAD, MOVE_RETURN, MOVE_RETURN, MOVE_PAY_DAY, NATURE_ADAMANT, FALSE),
    // Salamence — spread spatk/spd modest
    TRAINERMON(SPECIES_SALAME, 51, ITEM_CHOICE_SPECS, 0, SPREAD_31_IV_SPATK_SPEED_MODEST,
              MOVE_DRAGON_PULSE, MOVE_DRAGON_DANCE, MOVE_EARTHPOWER, MOVE_HYPER_BEAM, NATURE_MODEST, FALSE),
    // Empoleon — spread atk/spd adamant
    TRAINERMON(SPECIES_EMPOLEON, 50, ITEM_CHOICE_BAND, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_HYDRO_PUMP, MOVE_METAL_CLAW, MOVE_RETURN, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Lucario — spread atk/spd adamant
    TRAINERMON(SPECIES_LUCARIO, 51, ITEM_CHOICE_SPECS, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_CLOSE_FIGHT, MOVE_DARK_PULSE, MOVE_EARTHQUAKE, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    // Gyarados — spread atk/spd adamant
    TRAINERMON(SPECIES_GYARADOS, 50, ITEM_RAIN_DISH, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_EARTHPOWER, MOVE_POLTERGEIST, MOVE_RETURN, MOVE_HYPER_BEAM, NATURE_ADAMANT, FALSE),
    // Gengar — spread atk/spd adamant
    TRAINERMON(SPECIES_GENGAR, 52, ITEM_NONE, 0, SPREAD_31_IV_ATK_SPEED_ADAMANT,
              MOVE_HYPER_BEAM, MOVE_RETURN, MOVE_GIGA_DISCHARGE, MOVE_RETURN, NATURE_ADAMANT, FALSE),
    TERM
};

// ============================================================
// Mapa de treinadores PEWC
// ============================================================
// Índices:
// 0: Roxanne, 1: Brawly, 2: Watson, 3: Flannery,
// 4: Norman,  5: Wallace, 6: Tate&Liza, 7: Juan,
// 8: Sidney,  9: Phoebe, 10: Glacia, 11: Drake, 12: Steven

extern const struct {
    u8 trainerId;
    const TrainerMonItemCustomMoves *party;
    u8 partySize;
    bool8 alwaysFull;
    bool8 doubleAfter4Gym;
} gPewcTrainerMap[] = {
    // Roxanne: Ginásio 1 — 6 mons, sempre cheio, semis duplas após 4º
    { TRAINER_LOCATION01_ROXANNE, pewc_roxanne_party, 6, TRUE, TRUE },
    // Brawly: Ginásio 2 — 6 mons, sempre cheio, semis duplas após 4º
    { TRAINER_LOCATION02_BRAWLY, pewc_brawly_party, 6, TRUE, TRUE },
    // Watson: Ginásio 3 — 6 mons, sempre cheio, semis duplas após 4º
    { TRAINER_LOCATION03_WATSON, pewc_watson_party, 6, TRUE, TRUE },
    // Flannery: Ginásio 4 — 6 mons, sempre cheio, semis duplas após 4º
    { TRAINER_LOCATION04_FLANNERY, pewc_flannery_party, 6, TRUE, TRUE },
    // Norman: Ginásio 5 — 6 mons, sempre cheio, semis duplas após 4º
    { TRAINER_LOCATION05_NORMAN, pewc_norman_party, 6, TRUE, TRUE },
    // Wallace: Ginásio 6 — 6 mons, sempre cheio, ALWAYS FULL
    { TRAINER_LOCATION06_WALLACE, pewc_wallace_party, 6, TRUE, FALSE },
    // Tate & Liza: Ginásio 7 — 6 mons, sempre cheio, semis duplas após 4º
    { TRAINER_LOCATION07_TATE_LIZA, pewc_tate_liza_party, 6, TRUE, TRUE },
    // Juan: Ginásio 8 — 6 mons, sempre cheio, ALWAYS FULL
    { TRAINER_LOCATION08_JUAN, pewc_juan_party, 6, TRUE, FALSE },
    // Sidney: Elite Four #1 — 6 mons, sempre cheio, empresa
    { TRAINER_ELITE_FOUR_SIDNEY, pewc_sidney_party, 6, TRUE, FALSE },
    // Phoebe: Elite Four #2 — 6 mons, sempre cheio
    { TRAINER_ELITE_FOUR_PHOEBE, pewc_phoebe_party, 6, TRUE, FALSE },
    // Glacia: Elite Four #3 — 6 mons, sempre cheio
    { TRAINER_ELITE_FOUR_GLORIA, pewc_gloria_party, 6, TRUE, FALSE },
    // Drake: Elite Four #4 — 6 mons, sempre cheio
    { TRAINER_ELITE_FOUR_DRAKE, pewc_drake_party, 6, TRUE, FALSE },
    // Steven: Campeão — 6 mons, sempre cheio
    { TRAINER_CAMPION_STEVEN, pewc_steven_party, 6, TRUE, FALSE },
};

extern const u8 gPewcNumTrainers = 13;

// ============================================================
// Inicialização
// ============================================================
void PEWC_InitTrainerData(void);
