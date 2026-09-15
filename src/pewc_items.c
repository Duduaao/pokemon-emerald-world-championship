// =====================================================
// PEWC — Sistema de Itens da Nurse Joy (corrigido)
// =====================================================
#include "global.h"
#include "scrcmd.h"
#include "data.h"
#include "pewc.h"

// Medicamentos e cura de status — 10 unidades cada
// Usa apenas items válidos do ItemEnum.proto:
//   ITEM_POTION=28, ITEM_SUPER_POTION=37, ITEM_HYPER_POTION=36,
//   ITEM_MAX_POTION=35, ITEM_FULL_RESTORE=34, ITEM_REVIVE=39,
//   ITEM_MAX_REVIVE=40, ITEM_ANTIDOTE=29, ITEM_PARALYZE_HEAL=33,
//   ITEM_BURN_HEAL=30, ITEM_ICE_HEAL=31, ITEM_AWAKENING=32
static const ItemEnum sPewcNurseJoyMedicine[] = {
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_HYPER_POTION,
    ITEM_MAX_POTION,
    ITEM_FULL_RESTORE,
    ITEM_REVIVE,
    ITEM_MAX_REVIVE,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
};

#define PEWC_NURSE_JOY_MEDICINE_COUNT ARRAY_COUNT(sPewcNurseJoyMedicine)

// Berries — 10 unidades cada (apenas berries que existem no ItemEnum.proto)
// ItemEnum: ITEM_ORAN_BERRY=76, ITEM_SITRUS_BERRY=79,
//           ITEM_PERSIM_BERRY=77, ITEM_LUM_BERRY=78
static const ItemEnum sPewcNurseJoyBerries[] = {
    ITEM_ORAN_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_PERSIM_BERRY,
    ITEM_LUM_BERRY,
};

#define PEWC_NURSE_JOY_BERRY_COUNT ARRAY_COUNT(sPewcNurseJoyBerries)

// Poké Balls — 10 unidades cada (apenas balls que existem no ItemEnum.proto)
// ItemEnum: ITEM_POKE_BALL=4, ITEM_GREAT_BALL=3, ITEM_ULTRA_BALL=2,
//           ITEM_SAFARI_BALL=5
// Exclui Master Ball (ITEM_MASTER_BALL=1) da entrega.
static const ItemEnum sPewcNurseJoyBalls[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_SAFARI_BALL,
};

#define PEWC_NURSE_JOY_BALL_COUNT ARRAY_COUNT(sPewcNurseJoyBalls)

// Itens competitivos iniciais — 10 unidades cada
// Apenas itens válidos do ItemEnum.proto:
//   ITEM_EXP_SHARE=243, ITEM_FOCUS_SASH=287, ITEM_QUICK_CLAW=244,
//   ITEM_SCOPE_LENS=256
static const ItemEnum sPewcNurseJoyCompetitive[] = {
    ITEM_EXP_SHARE,
    ITEM_FOCUS_SASH,
    ITEM_QUICK_CLAW,
    ITEM_SCOPE_LENS,
};

#define PEWC_NURSE_JOY_COMPETE_COUNT ARRAY_COUNT(sPewcNurseJoyCompetitive)

// Pacote único da Nurse Joy — entrega uma vez, sem reposição
struct NurseJoyPackage {
    const ItemEnum *items;
    u8 count;
    u8 quantityPerItem;
    bool8 delivered;
};

static struct NurseJoyPackage gPewcNurseJoyPackage = {
    .items = NULL,
    .count = 0,
    .quantityPerItem = 10,
    .delivered = FALSE,
};

void PEWC_NurseJoyInit(void) {
    u8 totalItems = PEWC_NURSE_JOY_MEDICINE_COUNT
                   + PEWC_NURSE_JOY_BERRY_COUNT
                   + PEWC_NURSE_JOY_BALL_COUNT
                   + PEWC_NURSE_JOY_COMPETE_COUNT;

    static ItemEnum sPewcCombinedPackage[PEWC_NURSE_JOY_MEDICINE_COUNT
                                        + PEWC_NURSE_JOY_BERRY_COUNT
                                        + PEWC_NURSE_JOY_BALL_COUNT
                                        + PEWC_NURSE_JOY_COMPETE_COUNT];

    u8 idx = 0;
    for (u8 i = 0; i < PEWC_NURSE_JOY_MEDICINE_COUNT; i++)
        sPewcCombinedPackage[idx++] = sPewcNurseJoyMedicine[i];
    for (u8 i = 0; i < PEWC_NURSE_JOY_BERRY_COUNT; i++)
        sPewcCombinedPackage[idx++] = sPewcNurseJoyBerries[i];
    for (u8 i = 0; i < PEWC_NURSE_JOY_BALL_COUNT; i++)
        sPewcCombinedPackage[idx++] = sPewcNurseJoyBalls[i];
    for (u8 i = 0; i < PEWC_NURSE_JOY_COMPETE_COUNT; i++)
        sPewcCombinedPackage[idx++] = sPewcNurseJoyCompetitive[i];

    gPewcNurseJoyPackage.items = sPewcCombinedPackage;
    gPewcNurseJoyPackage.count = totalItems;
}

void PEWC_NurseJoyDeliver(void) {
    if (gPewcNurseJoyPackage.delivered) return;
    for (u8 i = 0; i < gPewcNurseJoyPackage.count; i++)
        AddBagItem(gPewcNurseJoyPackage.items[i], gPewcNurseJoyPackage.quantityPerItem);
    gPewcNurseJoyPackage.delivered = TRUE;
}
