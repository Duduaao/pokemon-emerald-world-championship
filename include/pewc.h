// ============================================================
// PEWC — Declarações do Sistema Competitivo
// ============================================================
// include/pewc.h

#ifndef GUARD_PEWC_H
#define GUARD_PEWC_H

#include "global.h"

// ---- Regras PEWC ----
bool8 IsPewcRuleset(void);

// ---- Level ----
u8 GetPlayerLevelLimit(void);
u8 GetCampaignProgressionLevel(void);

// ---- Sistema de treinadores PEWC ----
// Init chamado uma vez no início do jogo
void PEWC_InitTrainerData(void);

// ---- Editor competitivo ----
// Abrir editor para Pokémon específico (chamado da party menu)
void PEWC_OpenEditor(u8 partyIndex);
// Fecha editor e salva mudanças
void PEWC_CloseEditor(void);
// Verifica se editor está aberto
bool8 PEWC_IsEditorActive(void);
// Retorna o Pokémon sendo editado
struct Pokemon* PEWC_GetEditingMon(void);

// ---- Items em batalha ----
// Checa se item é permitido durante batalha (PEWC)
bool8 PEWC_BattleItemAllowed(ItemEnum item);

// ---- TMs ----
// TEmove reutilizável: checa se TM pode ser usado novamente
bool8 PEWC_TMReusable(void);
// Marcar TM como usado (para tracking de reutilização)
void PEWC_TMMarkUsed(ItemEnum item);

// ---- Move Reminder ----
// Retorna TRUE se Move Reminder é gratuito sob PEWC
bool8 PEWC_MoveReminderFree(void);

// ---- Rare Candy por rival ----
// Conceder 6 Rare Candies ao derrotar um rival
void PEWC_GiveRareCandyForRival(void);
// Verificar se treinador é rival (para TROPHEE/EXPANDED battle)
bool8 PEWC_IsRivalTrainer(u16 trainerId);

#endif
