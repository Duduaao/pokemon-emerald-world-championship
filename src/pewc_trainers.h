// ============================================================
// PEWC — Dados de Treinadores Competitivos
// ============================================================
// src/pewc_trainers.h
//
// Inclui as equipes de:
//   ROXANNE (Ginásio 1/4) — 6 mons
//   BRAWLY (Ginásio 2/4) — 6 mons
//   WATSON (Ginásio 3/4) — 6 mons
//   FLANNERY (Ginásio 4/4) — 6 mons
//   NORMAN (Ginásio 5/4) — 6 mons
//   WALLACE (Ginásio 6/4) — 6 mons
//   TATE & LIZA (Ginásio 7/4) — 6 mons
//   JUAN (Ginásio 8/4) — 6 mons
//   SIDNEY (Elite 4 #1) — 6 mons
//   PHOEBE (Elite 4 #2) — 6 mons
//   GLACIA (Elite 4 #3) — 6 mons
//   DRAKE (Elite 4 #4) — 6 mons
//   STEVEN (Campeão) — 6 mons
//
// ============================================================

#ifndef PEWC_TRAINERS_H
#define PEWC_TRAINERS_H

#include "global.h"
#include "data.h"
#include "constants/spreads.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/natures.h"

// ============================================================
// MACRO TRAINERMON
// ============================================================
// Macro que cria um TrainerMonItemCustomMoves com todos os campos.
// spread: usa SPREAD_31_IV_* de constants/spreads.h
// moves: MOVE_<NAME> de generated/constants/moves.h
// nature: NATURE_<NAME> de generated/constants/natures.h
// heldItem: ITEM_<NAME> de generated/constants/items.h
// ability: 0 = primary, 1 = secondary, 2 = hidden
// isAlpha: FALSE para treinadores normais; TRUE para Pokémon alpha
// zeroSpeedIvs: FALSE (não usamos essa construção)
//
// Estrutura TrainerMonItemCustomMoves:
//   s8 lvl, SpeciesEnum species, u16 heldItem, u8 ability, u8 spread,
//   MoveEnum moves[MAX_MON_MOVES], u8 hpType,
//   u8 evs[NUM_STATS], u8 nature, bool8 zeroSpeedIvs, bool8 isAlpha
//
// NUM_STATS = 6: HP, ATK, DEF, SPA, SPD, SPE
// MAX_MON_MOVES = 4
//
#define TRAINERMON(species, lvl, heldItem, ability, spread,  \
//                   hpType, ev_hp, ev_atk, ev_def, ev_spa, ev_spd, ev_spe,  \
//                   nature, move1, move2, move3, move4, isAlpha)              \
//    { lvl, species, heldItem, ability, spread,                               \
//      { move1, move2, move3, move4 }, hpType,                              \
//      { ev_hp, ev_atk, ev_def, ev_spa, ev_spd, ev_spe }, nature, FALSE, isAlpha }

// ============================================================
// MACRO TERM
// ============================================================
#define TRAINERMON_TERM  { 0, SPECIES_NONE, ITEM_NONE, 0, 0, { 0,0,0,0 }, 0, { 0,0,0,0,0,0 }, 0, FALSE, FALSE }

// ============================================================
// MACRO SHORTHAND PARA EVS (status: HP, ATK, DEF, SPA, SPD, SPE)
// ============================================================
#define EV_NONE  0
#define EV_252   252
#define EV_4     4
#define EV_252_252_4_0_0_0  { 252, 252, 4, 0, 0, 0 }
#define EV_4_252_4_0_0_0   { 4, 252, 4, 0, 0, 0 }
#define EV_0_0_0_252_4_0   { 0, 0, 0, 252, 4, 0 }
#define EV_4_0_0_252_0_0   { 4, 0, 0, 252, 0, 0 }
#define EV_0_252_0_0_0_252 { 0, 252, 0, 0, 0, 252 }
#define EV_0_0_252_0_0_252 { 0, 0, 252, 0, 0, 252 }
#define EV_252_0_252_0_0_0 { 252, 0, 252, 0, 0, 0 }
#define EV_0_0_252_0_252_0 { 0, 0, 252, 0, 252, 0 }

// ============================================================
// SPIRES DE NATURE
// ============================================================
#define NR_ADAMANT  NATURE_ADAMANT
#define NR_BALD     NATURE_BALD
#define NR_MODEST   NATURE_MODEST
#define NR_TIMID    NATURE_TIMID
#define NR_JOLLY    NATURE_JOLLY
#define NR_CALM    NATURE_CALM
#define NR_HASTY    NATURE_HASTY
#define NR_QUIET    NATURE_QUIET
#define NR_CAREFUL  NATURE_CAREFUL
#define NR_IMPISH   NATURE_IMPISH
#define NR_NAIVE    NATURE_NAIVE
#define NR_SASSY    NATURE_SASSY
#define NR_HARDY    NATURE_HARDY
#define NR_LONELY   NATURE_LONELY
#define NR_BOLD     NATURE_BOLD
#define NR_GENTLE   NATURE_GENTLE

// ============================================================
// ITEM SHORTHAND
// ============================================================
#define IT_NONE       ITEM_NONE
#define IT_EXP_SHARE  ITEM_EXP_SHARE
#define IT_FOCUS      ITEM_FOCUS_SASH
#define IT_EVIOLITE   ITEM_EVIOLITE
#define IT_CHOICE_B   ITEM_CHOICE_BAND
#define IT_CHOICE_S   ITEM_CHOICE_SPECS
#define IT_LUCKY_E    ITEM_LUCKY_EGG
#define IT_SCOPE      ITEM_SCOPE_LENS
#define IT_QUICK_C    ITEM_QUICK_CLAW
#define IT_LIFE_ORB   ITEM_LIFE_ORB

// ============================================================
// ROXANNE — Ginásio 1 (Normal) — 6 mons
// ---------------------------------------------------------------
// Species: Pidgeot=18, Mankey=56, Quagsire=195, Gyarados=130,
//          Sneasel=198, Zubat=41
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_DEF_BOLD=18
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_roxanne_party[] = {
    TRAINERMON(  SPECIES_PIDGEOT,  17, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,  MOVE_WING_ATTACK, MOVE_ROOST,           MOVE_RETURN,        MOVE_SHORT_FLIGHT,  FALSE ),
    TRAINERMON(  SPECIES_MANKEY,   16, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,  MOVE_KARATE_CHOP, MOVE_RETURN,          MOVE_RETURN,        MOVE_FLAMETHROWER,  FALSE ),
    TRAINERMON(  SPECIES_QUAGSIRE, 15, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BOLD,      MOVE_EARTHPOWER,  MOVE_HEAD_SMASH,      MOVE_BODY_SLAM,     MOVE_STONE_SURGE,   FALSE ),
    TRAINERMON(  SPECIES_GYARADOS, 17, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,  MOVE_DRAGON_PUNCH,MOVE_ICEFANG,         MOVE_EARTHPOWER,    MOVE_MEGA_KICK,     FALSE ),
    TRAINERMON(  SPECIES_SNEASEL,  16, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,  MOVE_RETURN,     MOVE_KNOCK_OFF,       MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_ZUBAT,    15, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,  MOVE_RETURN,     MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// BRAWLY — Ginásio 2 (Terra/Luta) — 6 mons
// ---------------------------------------------------------------
// Species: Typhlosion=157, Hitmonlee=106, Onix=95, Golem=76,
//          Rhyhorn=111, Rhydon=112 (via Porygon2-like)
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_DEF_BOLD=18
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_brawly_party[] = {
    TRAINERMON(  SPECIES_TYPHLOSION, 19, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_JOLLY,     MOVE_FLAMETHROWER,MOVE_CROSS_CHOP,      MOVE_QUICK_ATTACK,  MOVE_FIRE_SPIN,     FALSE ),
    TRAINERMON(  SPECIES_HITMONLEE, 18, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_DIVING_PUNCH,MOVE_RETURN,         MOVE_KNOCK_OFF,     MOVE_COUNTER,       FALSE ),
    TRAINERMON(  SPECIES_ONIX,      18, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_ROCK_SLIDE,  MOVE_EARTHPOWER,      MOVE_HYPER_BEAM,    MOVE_ENDURE,        FALSE ),
    TRAINERMON(  SPECIES_GOLEM,     19, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_ROCK_BLAST,  MOVE_EARTHPOWER,      MOVE_ROCK_SLIDE,    MOVE_SELF_DESTRUCT, FALSE ),
    TRAINERMON(  SPECIES_RHYHORN,   17, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_EARTHPOWER,  MOVE_FIRE_BLAST,      MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_RHYDON,    18, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_POLTERGEIST, MOVE_HYPER_BEAM,    MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// WATSON — Ginásio 3 (Elétrico) — 6 mons
// ---------------------------------------------------------------
// Species: Raichu=26, Skarmory=227, Jolteon=135, Electabuzz=125,
//          Magnemite=81 (×2), Flaaffy=180
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_DEF_BOLD=18
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_watson_party[] = {
    TRAINERMON(  SPECIES_RAICHU,    22, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_THUNDER,     MOVE_RETURN,         MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_SKARMORY,  22, IT_EVIOLITE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_AERIAL_ACE,  MOVE_RETURN,         MOVE_ROCK_SLIDE,    MOVE_CALM_MIND,     FALSE ),
    TRAINERMON(  SPECIES_JOLTEON,   21, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_JOLLY,     MOVE_RETURN,      MOVE_THUNDER,        MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_ELECTABUZZ,21, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_JOLLY,     MOVE_RETURN,      MOVE_THUNDER,        MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_MAGNETONE, 20, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_RETURN,      MOVE_DISCHARGE,       MOVE_RETURN,        MOVE_STEEL_WING,    FALSE ),
    TRAINERMON(  SPECIES_FLAFFY,    20, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_JOLLY,     MOVE_RETURN,      MOVE_RETURN,          MOVE_THUNDER,       MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// FLANNERY — Ginásio 4 (Fogo) — 6 mons
// ---------------------------------------------------------------
// Species: Typhlosion=157, Magmar=126, Crobat=169, Rynerior=?,
//          Ninetales=38, Arcanine=59
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_SPDEF_Calm=19
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_flannery_party[] = {
    TRAINERMON(  SPECIES_TYPHLOSION, 24, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_JOLLY,     MOVE_FLAMETHROWER,MOVE_CROSS_CHOP,      MOVE_QUICK_ATTACK,  MOVE_FIRE_SPIN,     FALSE ),
    TRAINERMON(  SPECIES_MAGMAR,    23, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_FIRE_BLAST,  MOVE_RETURN,         MOVE_EARTHPOWER,    MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_CROBAT,    23, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_GOLDEEN,   23, IT_NONE, 0, 19,  0, EV_NONE, 0, 0, 0, 0, 252,    NR_CALM,       MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_SURF,          FALSE ),
    TRAINERMON(  SPECIES_NINETALES, 23, IT_NONE, 0, 10,  0, EV_NONE, 4, 0, 0, 252, 0, 252, NR_TIMID,      MOVE_FIRE_BLAST,  MOVE_RETURN,          MOVE_RETURN,        MOVE_AURORA_BEAM,   FALSE ),
    TRAINERMON(  SPECIES_ARCANINE,  24, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_FIRE_BLAST,      MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// NORMAN — Ginásio 5 (Terra) — 6 mons
// ---------------------------------------------------------------
// Species: Tyrogue=236, Hitmonchan=107, Donphan=232, Quagsire=195,
//          Dugtrio=51, Rhydon=112
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_DEF_BOLD=18
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_norman_party[] = {
    TRAINERMON(  SPECIES_TYROGUE,   23, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_KARATE_CHOP,   FALSE ),
    TRAINERMON(  SPECIES_HITMONCHAN,22, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_BALD,      MOVE_REVERSAL,    MOVE_KARATE_CHOP,     MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_DONPHAN,   23, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_ROCK_SLIDE,  MOVE_RETURN,          MOVE_CROSSLY,       MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_QUAGSIRE,  23, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_EARTHPOWER,  MOVE_BODY_SLAM,       MOVE_HEAD_SMASH,    MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_DUGTRIO,   22, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_TIMID,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_RHYDON,    23, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_POLTERGEIST, MOVE_HYPER_BEAM,    MOVE_RETURN,        MOVE_EARTHPOWER,    FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// WALLACE — Ginásio 6 (Água) — 6 mons, SEMPRE CHEIO
// ---------------------------------------------------------------
// Species: Stuclops=296, Ampharos=181, Quagsire=195, Gyarados=130,
//          Lanturn=171, Gorebyss=326
// SPREAD_31_IV_SPATK_SPEED_MODEST=14, SPREAD_31_IV_HP_DEF_BOLD=18
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_wallace_party[] = {
    TRAINERMON(  SPECIES_STUCLOPS,   39, IT_CHOICE_B, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_AMPHAROS,   40, IT_CHOICE_S, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_THUNDERTACK, MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_QUAGSIRE,   39, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_EARTHPOWER,  MOVE_HEAD_SMASH,      MOVE_BODY_SLAM,     MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_GYARADOS,   40, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_ICEFANG,     MOVE_EARTHPOWER,      MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_LANTURN,    40, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_GOREBYSS,   39, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// TATE & LIZA — Ginásio 7 (Controle do Tempo) — 6 mons
// ---------------------------------------------------------------
// Species: Tyrannitar=248, Larvitar=246, Pupitar=247
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_ATK_BRAVE=12
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_tate_liza_party[] = {
    TRAINERMON(  SPECIES_TYRANITAR,  29, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_LARVITAR,   28, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_PUPITAR,    29, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_TYROGUE,    30, IT_NONE, 0, 12,  0, EV_4, 252, 4, 0, 0, 0,   NR_BRAVE,      MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_KARATE_CHOP,   FALSE ),
    TRAINERMON(  SPECIES_HITMONTOP,  30, IT_NONE, 0, 12,  0, EV_4, 252, 4, 0, 0, 0,   NR_BRAVE,      MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_HITMONCHAN, 29, IT_NONE, 0, 12,  0, EV_4, 252, 4, 0, 0, 0,   NR_BRAVE,      MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// JUAN — Ginásio 8 (Lago verde) — 6 mons
// ---------------------------------------------------------------
// Species: Sneasel=198, Skarmory=227, Crobat=169, Starmie=121,
//          Lanturn=171, Electabuzz=125 (ou Electrike=309 se existir)
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_SPDEF_Calm=19
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_juan_party[] = {
    TRAINERMON(  SPECIES_SNEASEL,    31, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,     MOVE_KNOCK_OFF,       MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_SKARMORY,   32, IT_EVIOLITE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_AERIAL_ACE,  MOVE_RETURN,         MOVE_ROCK_SLIDE,    MOVE_CALM_MIND,     FALSE ),
    TRAINERMON(  SPECIES_CROBAT,     31, IT_QUICK_C, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_JOLLY,     MOVE_RETURN,      MOVE_RETURN,          MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_STARMIE,    31, IT_NONE, 0, 19,  0, EV_NONE, 0, 0, 0, 0, 252,    NR_CALM,       MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_LANTURN,    32, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_ELECTABUZZ, 31, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_JOLLY,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// SIDNEY — Elite Four Pos 1 (Luta) — 6 mons, SEMPRE CHEIO
// ---------------------------------------------------------------
// Species: Hitmontop=237, Hitmonchan=107, Hitmonlee=106,
//          Rhyperior=?, Rhydon=112, Donphan=232
// SPREAD_31_IV_SHORT_EV=31_IV_ATK_SPEED_ADAMANT=10
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_sidney_party[] = {
    TRAINERMON(  SPECIES_HITMONTOP,  38, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_KARATE_CHOP, MOVE_RETURN,         MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_HITMONCHAN, 37, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_BALD,      MOVE_REVERSAL,    MOVE_KARATE_CHOP,     MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_HITMONLEE,  38, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_DIVING_PUNCH,MOVE_RETURN,         MOVE_KNOCK_OFF,     MOVE_COUNTER,       FALSE ),
    TRAINERMON(  SPECIES_RHYDON,     39, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_POLTERGEIST, MOVE_HYPER_BEAM,    MOVE_RETURN,        MOVE_EARTHPOWER,    FALSE ),
    TRAINERMON(  SPECIES_DONPHAN,    37, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_CROSSLY,         MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_RHYDON,     38, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_POLTERGEIST, MOVE_HYPER_BEAM,    MOVE_RETURN,        MOVE_EARTHPOWER,    FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// PHOEBE — Elite Four Pos 2 (Veneno) — 6 mons, SEMPRE CHEIO
// ---------------------------------------------------------------
// Species: Venomoth=49, Maletos=?, Weavile=?, Cloyster=91,
//          Seadra=117, Seaking=119
// SPREAD_31_IV_SPATK_SPEED_MODEST=14, SPREAD_31_IV_HP_SPDEF_Calm=19
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_phoebe_party[] = {
    TRAINERMON(  SPECIES_VENOMOTH,   34, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_SLUDGE_BOMB,    MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_CLOYSTER,   35, IT_NONE, 0, 19,  0, EV_NONE, 0, 0, 0, 0, 252,    NR_CALM,       MOVE_ICICLE_SPEAR, MOVE_RETURN,       MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_SEASICK,    35, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_ICE_MOMBLOW,    MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_SAKING,     34, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_VENOMOTH,   35, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_VENOMOTH,   34, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// GLACIA — Elite Four Pos 3 (Gelo) — 6 mons, SEMPRE CHEIO
// ---------------------------------------------------------------
// Species: Weavile=?, Sneasel=198, Cloyster=91,
//          Piloswine=221, Lickitung=108, Lapras=131
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_HP_DEF_BOLD=18
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_gloria_party[] = {
    TRAINERMON(  SPECIES_CLOYSTER,   36, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_ICICLE_SPEAR, MOVE_RETURN,       MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_WEAVILE,    35, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_KNOCK_OFF,       MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_PILOSWINE,  35, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_LICKTUNG,  34, IT_NONE, 0, 18,  0, EV_252, 0, 252, 0, 0, 0,  NR_BALD,      MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_LAPRAS,     35, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_SNEASEL,    34, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_KNOCK_OFF,       MOVE_QUICK_ATTACK,  MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// DRAKE — Elite Four Pos 4 (Dragão) — 6 mons, SEMPRE CHEIO
// ---------------------------------------------------------------
// Species: Salamence=?, Dragonite=149 (×2), Dragonair=148,
//          Onix=95, Rhydon=112 (zwei), Arcanine=59 (ou Skarmory=227)
// SPREAD_31_IV_SPATK_SPEED_MODEST=14, SPREAD_31_IV_HP_ATK_BRAVE=12
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_drake_party[] = {
    TRAINERMON(  SPECIES_SALAME,     39, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_DRAGON_PULSE, MOVE_DRAGON_DANCE,  MOVE_EARTHPOWER,    MOVE_HYPER_BEAM,    FALSE ),
    TRAINERMON(  SPECIES_DRAGONITE,  40, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_HYPER_BEAM,    FALSE ),
    TRAINERMON(  SPECIES_DRAGONAIR,  39, IT_NONE, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_ONIX,      38, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_ROCK_SLIDE,  MOVE_EARTHPOWER,      MOVE_HYPER_BEAM,    MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_RHYDON,     39, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_POLTERGEIST, MOVE_HYPER_BEAM,    MOVE_RETURN,        MOVE_EARTHPOWER,    FALSE ),
    TRAINERMON(  SPECIES_ARCANINE,   38, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_RETURN,      MOVE_RETURN,          MOVE_RETURN,        MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// STEVEN — Campeão — 6 mons, SEMPRE CHEIO
// ---------------------------------------------------------------
// Species: Metagross=?, Salamence=?, Empoleon=?, Lucario=?,
//          Gyarados=130, Gengar=94
// SPREAD_31_IV_ATK_SPEED_ADAMANT=10, SPREAD_31_IV_ATK_SPDEF=45
// ---------------------------------------------------------------
static const TrainerMonItemCustomMoves pewc_steven_party[] = {
    TRAINERMON(  SPECIES_METAGROSS,  50, IT_CHOICE_B, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_IRON_HEAD,   MOVE_RETURN,         MOVE_RETURN,        MOVE_PAY_DAY,       FALSE ),
    TRAINERMON(  SPECIES_SALAME,     51, IT_CHOICE_S, 0, 14,  0, EV_NONE, 0, 0, 0, 252, 4, 252, NR_MODEST,     MOVE_DRAGON_PULSE, MOVE_DRAGON_DANCE,  MOVE_EARTHQUAKE,    MOVE_HYPER_BEAM,    FALSE ),
    TRAINERMON(  SPECIES_EMPOLEON,   50, IT_CHOICE_B, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_HYDRO_PUMP,  MOVE_CROSSLY,        MOVE_METAL_CLAW,    MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_LUCARIO,    51, IT_CHOICE_S, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_CLOSE_FIGHT, MOVE_DARK_PULSE,     MOVE_EARTHQUAKE,    MOVE_RETURN,        FALSE ),
    TRAINERMON(  SPECIES_GYARADOS,   50, IT_RAIN_DISH, 0, 10, 0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_EARTHPOWER,  MOVE_POLTERGEIST,    MOVE_RETURN,        MOVE_HYPER_BEAM,    FALSE ),
    TRAINERMON(  SPECIES_GENGAR,     52, IT_NONE, 0, 10,  0, EV_NONE, 252, 0, 0, 0, 252,  NR_ADAMANT,   MOVE_HYPER_BEAM,  MOVE_RETURN,         MOVE_GIGA_DISCHARGE,MOVE_RETURN,        FALSE ),
    TRAINERMON_TERM
};

// ============================================================
// DADOS EXTERNOS — array de treinadores competitivos
// ---------------------------------------------------------------
// Indexação:
//   0: ROXANNE, 1: BRAWLY, 2: WATSON, 3: FLANNERY,
//   4: NORMAN,  5: WALLACE, 6: TATE_LIZA, 7: JUAN,
//   8: SIDNEY, 9: PHOEBE, 10: GLACIA, 11: DRAKE, 12: STEVEN
// ---------------------------------------------------------------

extern const struct {
    u8  trainerId;             // TRAINER_ID do constants/trainers.h
    const TrainerMonItemCustomMoves *party;
    u8  partySize;             // 6 para E4/Wallace/Steven; variável para rotas
    bool8 alwaysFull;          // TRUE para E4, Wallace, Steven, rivais fixos
    bool8 doubleAfter4Gym;     // apenas para ginásios relevantes
} gPewcTrainerMap[];

extern const u8 gPewcNumTrainers;

// ============================================================
// INICIALIZAÇÃO
// ---------------------------------------------------------------
// Função que popula gTrainers[] com os dados de pewc_trainers.h
// (implementada em src/pewc_trainers.c).
// ---------------------------------------------------------------
void PEWC_InitTrainerData(void);

#endif // PEWC_TRAINERS_H
