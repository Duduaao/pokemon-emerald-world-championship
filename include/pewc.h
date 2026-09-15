#ifndef GUARD_PEWC_H
#define GUARD_PEWC_H

#include "global.h"

// PEWC Ruleset: retorna TRUE quando o jogo está rodando sob as regras do PEWC
bool8 IsPewcRuleset(void);

// Level máximo do jogador (sem cap por insígnia)
u8 GetPlayerLevelLimit(void);

// Nível de progressão da campanha (para escalonamento de adversários, lojas, etc.)
u8 GetCampaignProgressionLevel(void);

// Verifica se o Pokémon está desmaiado
bool8 IsMonFainted(const struct Pokemon *mon);

#endif // GUARD_PEWC_H
