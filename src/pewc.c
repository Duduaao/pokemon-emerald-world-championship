// ============================================================
// PEWC — Sistema Competitivo (implementação)
// ============================================================

#include "global.h"
#include "pewc.h"
#include "save.h"
#include "event_data.h"
#include "data.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_script_commands.h"
#include "item.h"
#include "party_menu.h"
#include "shop.h"
#include "move_relearner.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "rng.h"

// ============================================================
// Regras PEWC
// ============================================================

bool8 IsPewcRuleset(void) {
    if (gSaveBlock2Ptr->saveVersion != CURRENT_GAME_VERSION)
        return FALSE;
    return TRUE;
}

// ============================================================
// Level
// ============================================================

u8 GetPlayerLevelLimit(void) {
    return MAX_LEVEL;
}

u8 GetCampaignProgressionLevel(void) {
    u16 badgeCount = 0;
    u8 progressionLevel;

    if (FlagGet(FLAG_BADGE01_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE02_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE03_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE04_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE05_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE06_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE07_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE08_GET)) badgeCount++;

    static const u8 progressionTable[] = {
        5, 10, 15, 20, 25, 30, 35, 38, 40, 50
    };

    if (badgeCount >= ARRAY_COUNT(progressionTable))
        progressionLevel = 50;
    else
        progressionLevel = progressionTable[badgeCount];

    if (FlagGet(FLAG_HALL_OF_FAME_GET))
        progressionLevel = 55;

    return progressionLevel;
}

// ============================================================
// Shiny 79%
// ============================================================

#define PEWC_SHINY_CHANCE 202  // 79% ≈ 202 em 256

u8 GetPewcShinyChance(void) {
    return PEWC_SHINY_CHANCE;
}

bool8 PEWC_IsShiny79(void) {
    u8 randomValue = Random();
    return (randomValue < PEWC_SHINY_CHANCE);
}

// ============================================================
// Editor competitivo (versão mínima funcional)
// ============================================================

static EWRAM_DATA u8 gPewcEditPartyIndex = 0;
static EWRAM_DATA bool8 gPewcEditorActive = FALSE;

void PEWC_OpenEditor(u8 partyIndex) {
    if (!IsPewcRuleset()) return;
    gPewcEditPartyIndex = partyIndex;
    gPewcEditorActive = TRUE;
}

void PEWC_CloseEditor(void) {
    gPewcEditorActive = FALSE;
    gPewcEditPartyIndex = 0;
}

bool8 PEWC_IsEditorActive(void) {
    return gPewcEditorActive;
}

struct Pokemon* PEWC_GetEditingMon(void) {
    if (!gPewcEditorActive) return NULL;
    return &gPlayerParty[gPewcEditPartyIndex];
}

// ============================================================
// Items em batalha (PEWC)
// ============================================================

static const bool8 sPewcBattleItemsAllowed[ITEMS_COUNT] = {
    // Balls — permitidos
    [ITEM_POKE_BALL]        = TRUE,
    [ITEM_GREAT_BALL]       = TRUE,
    [ITEM_ULTRA_BALL]       = TRUE,
    [ITEM_MASTER_BALL]      = TRUE,
    [ITEM_SAFARI_BALL]      = TRUE,
    [ITEM_NET_BALL]         = TRUE,
    [ITEM_DIVE_BALL]        = TRUE,
    [ITEM_NEST_BALL]        = TRUE,
    [ITEM_REPEAT_BALL]      = TRUE,
    [ITEM_TIMER_BALL]       = TRUE,
    [ITEM_LUXURY_BALL]      = TRUE,
    [ITEM_DUSK_BALL]        = TRUE,
    [ITEM_HEAL_BALL]        = TRUE,
    [ITEM_QUICK_BALL]       = TRUE,
    [ITEM_CHERISH_BALL]     = TRUE,
    [ITEM_FAST_BALL]        = TRUE,
    [ITEM_LEVEL_BALL]       = TRUE,
    [ITEM_LURE_BALL]        = TRUE,
    [ITEM_HEAVY_BALL]       = TRUE,
    [ITEM_LOVE_BALL]        = TRUE,
    [ITEM_FRIEND_BALL]      = TRUE,
    [ITEM_MOON_BALL]        = TRUE,
    [ITEM_SPORT_BALL]       = TRUE,
    [ITEM_PARK_BALL]        = TRUE,
    [ITEM_DREAM_BALL]       = TRUE,
    [ITEM_BEAST_BALL]       = TRUE,
    [ITEM_PREMIER_BALL]     = TRUE,
    // Status — permitidos
    [ITEM_ANTIDOTE]         = TRUE,
    [ITEM_PARALYZE_HEAL]    = TRUE,
    [ITEM_BURN_HEAL]        = TRUE,
    [ITEM_ICE_HEAL]         = TRUE,
    [ITEM_AWAKENING]        = TRUE,
    // Cura de HP — proibidos
    [ITEM_POTION]           = FALSE,
    [ITEM_SUPER_POTION]     = FALSE,
    [ITEM_HYPER_POTION]     = FALSE,
    [ITEM_MAX_POTION]       = FALSE,
    [ITEM_FULL_RESTORE]     = FALSE,
    [ITEM_REVIVE]           = FALSE,
    [ITEM_MAX_REVIVE]       = FALSE,
    // Todos os outros — FALSE
};

bool8 PEWC_BattleItemAllowed(ItemEnum item) {
    if (!IsPewcRuleset()) return TRUE;
    if (item < ITEMS_COUNT)
        return sPewcBattleItemsAllowed[item];
    return FALSE;
}

// ============================================================
// TMs reutilizáveis
// ============================================================

bool8 PEWC_TMReusable(void) {
    return TRUE; // PEWC: TMs nunca se esgotam
}

void PEWC_TMMarkUsed(ItemEnum item) {
    // PEWC: não faz nada — TMs são reutilizáveis
    (void)item;
}

// ============================================================
// Move Reminder gratuito
// ============================================================

bool8 PEWC_MoveReminderFree(void) {
    return TRUE; // PEWC: gratuito
}

// ============================================================
// Rare Candy por rival derrotado
// ============================================================

static EWRAM_DATA bool8 gPewcRivalDefeated = FALSE;

void PEWC_GiveRareCandyForRival(void) {
    if (!IsPewcRuleset()) return;
    if (gPewcRivalDefeated) return;
    AddBagItem(ITEM_RARE_CANDY, 6);
    gPewcRivalDefeated = TRUE;
}

void PEWC_ClearRivalRareCandyFlag(void) {
    gPewcRivalDefeated = FALSE;
}

// ============================================================
// Verificar se treinador é rival
// ============================================================
// Os IDs de rival no Elite Redux estão em constants/opponents.h.
// Para não depender desse arquivo aqui, usamos uma abordagem:
// qualquer treinador cujo ID é < um limiar específico é rival.
// O código base já tem flags TRAINER_IS_RIVAL em alguns lugares.
// Por enquanto, retornamos FALSE e deixamos para o sistema de
// batalha decidir quando chamar PEWC_GiveRareCandyForRival().

bool8 PEWC_IsRivalTrainer(u16 trainerId) {
    // Placeholder: no código real, verifica se trainerId é um rival
    // conhecido via constants/opponents.h ou flag de rival.
    (void)trainerId;
    return FALSE;
}

// ============================================================
// Init do sistema PEWC
// ============================================================

void PEWC_Init(void) {
    gPewcRivalDefeated = FALSE;
}

// ============================================================
// Init de dados de treinadores PEWC
// ============================================================
// Não implementada aqui — popule os gTrainers[] diretamente
// no lugar onde são definidos, ou use o arquivo pewc_trainers.h
// que já tem os dados (se os IDs forem válidos).

void PEWC_InitTrainerData(void) {
    // Placeholder: neste momento, não populamos gTrainers[]
    // porque os IDs de species/moves/items em pewc_trainers.h
    // podem não corresponder aos do proto do Elite Redux.
    // Quando os IDs forem corrigidos, esta função popula
    // os dados de treinadores competitivos.
}
