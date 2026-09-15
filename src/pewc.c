#include "global.h"
#include "pewc.h"
#include "save.h"
#include "event_data.h"

// ============================================================
// PEWC Ruleset
// ============================================================
// O PEWC opera em um único modo de jogo competitivo.
// A detecção é baseada na versão do save (CURRENT_GAME_VERSION)
// e na ausência de flags de outras modalidades.

bool8 IsPewcRuleset(void) {
    // Verifica se é um save válido do PEWC
    if (gSaveBlock2Ptr->saveVersion != CURRENT_GAME_VERSION) {
        return FALSE;
    }
    // O PEWC não usa os modos de dificuldade antigos
    // Se o save tiver qualquer flag de dificuldade específica, não é PEWC
    // Mas como o PEWC define seu próprio save version, isso já basta
    return TRUE;
}

// ============================================================
// Player Level Limit — sem cap por insígnia
// ============================================================

u8 GetPlayerLevelLimit(void) {
    // O jogador pode subir até MAX_LEVEL (100) sem restrições
    return MAX_LEVEL;
}

// ============================================================
// Campaign Progression Level
// ============================================================
// Usado para:
// - Nível dos adversários (training scaling)
// - Preços das lojas
// - Nível de Pokémon dados por NPCs
// - Balanceamento geral
// Baseado nas insígnias conquistadas, não no level do jogador.

u8 GetCampaignProgressionLevel(void) {
    u16 badgeCount = 0;
    u8 progressionLevel;

    // Conta quantas insígnias foram conquistadas
    if (FlagGet(FLAG_BADGE01_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE02_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE03_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE04_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE05_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE06_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE07_GET)) badgeCount++;
    if (FlagGet(FLAG_BADGE08_GET)) badgeCount++;

    // Tabela de progressão: nível base + incremento por insígnia
    // Nível 5 no início, +5 por insígnia até nível 40 após a 8ª
    // Depois da Liga, progressionLevel = 50 (Wallace desbloqueado)
    static const u8 progressionTable[] = {
        5,   // 0 insígnias (início)
        10,  // 1 insígnia (após Roxanne)
        15,  // 2 insígnias (após Brawly)
        20,  // 3 insígnias (após Wattson)
        25,  // 4 insígnias (após Flannery)
        30,  // 5 insígnias (após Norman)
        35,  // 6 insígnias (após Winona)
        38,  // 7 insígnias (após Tate & Liza)
        40,  // 8 insígnias (após Juan)
        50,  // Pós-League (Wallace/Hall da Fama)
    };

    if (badgeCount >= ARRAY_COUNT(progressionTable)) {
        progressionLevel = 50; // Pós-League
    } else {
        progressionLevel = progressionTable[badgeCount];
    }

    // Steven só está disponível pós-game, após Wallace
    // SeFLAG_HALL_OF_FAME_GET estiver setado, seu nível é 55
    if (FlagGet(FLAG_HALL_OF_FAME_GET)) {
        progressionLevel = 55;
    }

    return progressionLevel;
}

// ============================================================
// IsMonFainted
// ============================================================

bool8 IsMonFainted(const struct Pokemon *mon) {
    if (mon == NULL) return TRUE;
    return (GetMonData(mon, MON_DATA_HP) == 0);
}
