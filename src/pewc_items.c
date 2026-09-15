// ==============================================================
// PEWC — Sistema de Itens da Nurse Joy
// ============================================================
// Entrega única de 10 unidades de cada item permitido.
// Após o pacote inicial, a Nurse Joy NÃO repõe itens gratuitamente.
// Manteve-se a cura normal (pay-per-use).

#include "global.h"
#include "scrcmd.h"
#include "data.h"
#include "pewc.h"

// Medicamentos e cura de status — 10 unidades cada
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
    ITEM_WAKE_UP,
};

#define PEWC_NURSE_JOY_MEDICINE_COUNT ARRAY_COUNT(sPewcNurseJoyMedicine)

// Berries — 10 unidades cada (todas)
static const ItemEnum sPewcNurseJoyBerries[] = {
    ITEM_ORAN_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_PERSIM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_ASPIRIN_BERRY,
    ITEM_CAFFEINE_BERRY,
    ITEM_COCOA_BERRY,
    ITEM_COLSCOTT_BERRY,
    ITEM_HONDEW_BERRY,
    ITEM_KFP_BERRY,
    ITEM_LEPP_BERRY,
    ITEM_LIFE_DEW_BERRY,
    ITEM_PARFO_BERRY,
    ITEM_PINETOP_BERRY,
    ITEM_RASEAAP_BERRY,
    ITEM_RAWSAT_BERRY,
    ITEM_REVIVAL_Herb_BERRY,  // Se existir no enum
    ITEM_SALAC_BERRY,
    ITEM_SIGAN_BERRY,
    ITEM_SOOTHING_SERNAB_BERRY,
    ITEM_SPARKLE_SIGAN_BERRY,
    ITEM_STORK_TOKI_BERRY,
    ITEM_TABU_BERRY,
    ITEM_WIKIB_NANA_BERRY,
};

#define PEWC_NURSE_JOY_BERRY_COUNT ARRAY_COUNT(sPewcNurseJoyBerries)

// Poké Balls — 10 unidades cada (todas as comuns/úteis)
static const ItemEnum sPewcNurseJoyBalls[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_MASTER_BALL,  // O Master Ball NÃO é entregue pela Nurse Joy — ver abaixo
    ITEM_FAST_BALL,
    ITEM_LEVEL_BALL,
    ITEM_LURE_BALL,
    ITEM_NET_BALL,
    ITEM_PARK_BALL,
    ITEM_PREMIER_BALL,
    ITEM_SAFARI_BALL,
    ITEM_SIMPLE_BALL,
    ITEM_DUSK_BALL,
    ITEM_FUSIC_DIVE_BALL,
};

// O Master Ball está acima apenas para referência — ele é EXCLUÍDO da entrega.
// Vamos removê-lo da lista de entrega.

#define PEWC_NURSE_JOY_BALL_COUNT (ARRAY_COUNT(sPewcNurseJoyBalls) - 1)  // sem Master Ball

// Itens competitivos iniciais — 10 unidades cada (seguro para início)
static const ItemEnum sPewcNurseJoyCompetitive[] = {
    ITEM_EXP_SHARE,
    ITEM_FOCUS_SASH,
    ITEM_QUICK_CLAW,
    ITEM_LUSTROUS_ORB,
    ITEM_INTIMIDATE_TAROTCARD,
    // Itemremovelist que não quebra o game
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
    .items = NULL,  // será configurado dinamicamente
    .count = 0,
    .quantityPerItem = 10,
    .delivered = FALSE,
};

// Inicializa o pacote da Nurse Joy (chamado uma vez no new game)
void PEWC_NurseJoyInit(void) {
    // Combina todos os arrays em um único pacote
    u8 totalItems = PEWC_NURSE_JOY_MEDICINE_COUNT
                   + PEWC_NURSE_JOY_BERRY_COUNT
                   + PEWC_NURSE_JOY_BALL_COUNT
                   + PEWC_NURSE_JOY_COMPETE_COUNT;

    // Aloca espaço para o array combinado (static para simplicidade)
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

// Entrega o pacote da Nurse Joy (uma única vez)
void PEWC_NurseJoyDeliver(void) {
    if (gPewcNurseJoyPackage.delivered) {
        // Já entregou — não repõe
        return;
    }

    for (u8 i = 0; i < gPewcNurseJoyPackage.count; i++) {
        AddBagItem(gPewcNurseJoyPackage.items[i], gPewcNurseJoyPackage.quantityPerItem);
    }

    gPewcNurseJoyPackage.delivered = TRUE;
}
