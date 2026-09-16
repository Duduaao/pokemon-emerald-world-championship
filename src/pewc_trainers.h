1-3: agosto-outubro, empresa._#============================================================
// PEWC — Dados de Treinadores Competitivos (IDs corrigidos)
//=============================================================
 INAT: header global.h, data.h
 INAT: spreads.h para SPREAD_31_IV_*
 INAT: moves.h, species.h para IDs de move/species 

 /* COMPATIB. DO ANCIÃO:no item.h a referencia ITEM_NONE=0, 
   nao existe mais ITEM_EVIOLIE (ITEM_EVIOLITE=310 é a codificação real ) */
  
 #include "global.h"
  
 /* INAT DO TRAINER DATS STRUCT */
 #include "data.h"
 #include "generated/constants/spreads.h"
  
 /* INAT DO ITEM para ids */
 #include "item.h"
  
 // INAT DOS MOVE & SPECIES IDs 
 // INAT DO MOVES 
 // INAT DO SPECIES 
 // INAT DOS ITEMS 
 // INAT DOS NATURES
 
 #include "generated/constants/moves.h"
 #include "constants/natures.h"

 // VALORES DE ACORDO COM O ER-CONFIG (proto/):
 
 /* MOVE IDs: */
 //       FROM MOVEES:
 #define PEWC_MOVE_NONE            MOVE_NONE     // 0   
 #define PEWC_MOVE_POUND          MOVE_POUND       // 1
 #define PEWC_MOVE_KARATE_CHOP    MOVE_KARATE_CHOP     // 2
 #define PEWC_MOVE_ICE_BEAM           MOVE_ICE_BEAM         // 58
 #define PEWC_MOVE_FIRE_BLAST      MOVE_FIRE_BLAST      // 126
 #define PEWC_MOVE_ROOST           MOVE_ROOST         // 355
 #define PEWC_MOVE_RETURN          MOVE_RETURN        // 216
 #define PEWC_MOVE_QUICK_ATTACK    MOVE_QUICK_ATTACK      // 98
 #define PEWC_MOVE_WING_ATTACK     MOVE_WING_ATTACK       // 17
 #define PEWC_MOVE_FURY_ATTACK     MOVE_FURY_ATTACK     // 31
 #define PEWC_MOVE_TAUNT           MOVE_TAUNT         // 269
 #define PEWC_MOVE_BODY_SLAM       MOVE_BODY_SLAM     // 34
 #define PEWC_MOVE_THUNDER		    MOVE_THUNDER    // 87
 #define PEWC_MOVE_HEAD_SMASH      MOVE_HEAD_SMASH      // 457
 #define PEWC_MOVE_EARTHPOWER	   MOVE_EARTH_POWER        // 414
 #define PEWC_MOVE_ROCK_SLIDE      MOVE_ROCK_SLIDE     // 157
 #define PEWC_MOVE_ROCK_BLAST      MOVE_ROCK_BLAST      // 350
 #define PEWC_MOVE_HYPER_BEAM      MOVE_HYPER_BEAM     // 63
 #define PEWC_MOVE_STEEL_WING      MOVE_STEEL_WING     // 211
 #define PEWC_MOVE_POLTERGEIST     MOVE_POLTERGEIST      // 737
 #define PEWC_MOVE_SURF            MOVE_SURF         // 57
 #define PEWC_MOVE_SPLASH	       MOVE_SPLASH       // 150
 #define PEWC_MOVE_HEAT_WAVE	   MOVE_HEAT_WAVE    // 257
 #define PEWC_MOVE_AERIAL_ACE      MOVE_AERIAL_ACE      // 332
 #define PEWC_MOVE_METAL_CLAW      MOVE_METAL_CLAW      // 232
 #define PEWC_MOVE_CALM_MIND       MOVE_CALM_MIND      // 347
 #define PEWC_MOVE_DRAGON_PULSE    MOVE_DRAGON_PULSE      // 406
 #define PEWC_MOVE_DRAGON_DANCE    MOVE_DRAGON_DANCE      // 349
 #define PEWC_MOVE_CLOSE_COMBAT    MOVE_CLOSE_COMBAT      // 370
 #define PEWC_MOVE_DARK_PULSE	   MOVE_DARK_PULSE  // 399
 #define PEWC_MOVE_SHADOW_BALL     MOVE_SHADOW_BALL    // 247
 #define PEWC_MOVE_PAY_DAY         MOVE_PAY_DAY          // 6
 #define PEWC_MOVE_THUNDER        	 MOVE_THUNDERBOLT
 #define PEWC_MOVE_ICEFANG	       MOVE_ICEFANG    // 423
 #define PEWC_MOVE_SELF_DESTRUCT   MOVE_SELF_DESTRUCT // 120
 #define PEWC_MOVE_COUNTER         MOVE_COUNTER          // 68
 #define PEWC_MOVE_ENDEAVOR        MOVE_ENDEAVOR        // 283
 #define PEWC_MOVE_FLAMETHROWER    MOVE_FLAMETHROWER      // 53
 #define PEWC_MOVE_CROSS_CHOP      MOVE_CROSS_CHOP       // 238
 #define PEWC_MOVE_FAKE_TEARS	   MOVE_FAKE_TEARS  // 313
 #define PEWC_MOVE_AURORA_BEAM     MOVE_AURORA_BEAM      // 62
 #define PEWC_MOVE_AQUA_JET	       MOVE_AQUA_JET // 453
 #define PEWC_MOVE_WILL_O_WISP     MOVE_WILL_O_WISP      // 261
 #define PEWC_MOVE_ACROBATICS	   MOVE_ACROBATICS     // 512
 #define PEWC_MOVE_GRASS_KNOT	  MOVE_GRASS_KNOT	       // 447
 // INAT DE SPREAD IDS:
 #define PEWC_SPREAD _31_IV_ATK_SPEED_ADAMANT    SPREAD_31_IV_ATK_SPEED_ADAMANT // 10  
 #define PEWC_SPREAD _31_IV_ATK_SPEED_JOLLY      SPREAD_31_IV_ATK_SPEED_JOLLY     // 9  
 #define PEWC_SPREAD _31_IV_HP_DEF_BOLD         SPREAD_31_IV_HP_DEF_BOLD           // 18
 #define PEWC_SPREAD _31_IV_HP_SPDEF_CALM       SPREAD_31_IV_HP_SPDEF_CALM         // 19 
 #define PEWC_SPREAD _31_IV_SPATK_SPEED_MODEST  SPREAD_31_IV_SPATK_SPEED_MODEST     // 14
 #define PEWC_SPREAD _31_IV_HP_ATK_BRAVE        SPREAD_31_IV_HP_ATK_BRAVE           // 12
 // INAT DE NATURE:
 #define PEWC_NATURE_HARDY           NATURE_HARDY   // 0
 #define PEWC_NATURE_ADAMANT         NATURE_ADAMANT  // 2
 #define PEWC_NATURE_JOLLY           NATURE_JOLLY     // 1
 #define PEWC_NATURE_BALD            NATURE_BALD        // 3
 #define PEWC_NATURE_MODEST          NATURE_MODEST      // 4
 #define PEWC_NATURE_CALM            NATURE_CALM         // 5
 #define PEWC_NATURE_BOLD            NATURE_BOLD         // 9
 #define PEWC_NATURE_TIMID           NATURE_TIMID        // 6
 #define PEWC_NATURE_BRAVE           NATURE_BRAVE        // 8
 #define PEWC_NATURE_RASH             NATURE_RASH         // 10
 // INAT DE ITENS IDS:
 #define PEWC_ITEM_NONE           ITEM_NONE     // 0
 #define PEWC_ITEM_EXP_SHARE     ITEM_EXP_SHARE // 243
 #define PEWC_ITEM_FOCUS_SASH    ITEM_FOCUS_SASH // 287
 #define PEWC_ITEM_QUICK_CLAW    ITEM_QUICK_CLAW // 244
 #define PEWC_ITEM_SCOPE_LENS    ITEM_SCOPE_LENS // 256
 #define PEWC_ITEM_CHOICE_BAND   ITEM_CHOICE_BAND // 247
 #define PEWC_ITEM_CHOICE_SPECS  ITEM_CHOICE_SPECS // 286
 #define PEWC_ITEM_EVIOLITE      ITEM_EVIOLITE // 310
 #define PEWC_ITEM_RAIN_DISH     PEWC_ITEM_NONE // 0 — não temos item de chuva no ItemEnum.proto
 
 
 /* INAT DO TRAINER MON ITEM CUSTOM MOVES STRUCT */
 
 #define PEWC_TRAINERMON(s, lvl, held, abil, spread, m1, m2, m3, m4, nat, ea)  \
  { 0, s, held, abil, spread, { m1, m2, m3, m4 }, 0, { 252, 252, 4, 0, 0, 0 }, { 4, 4, 4, 4, 4, 4 }, 0, 0, 0, 0 }
 
 #define PEWC_TERM \
  { 0, 0, 0, 0, 0, { 2, 6, 7, 14, 15, 0 }, 0, { 252, 252, 4, 0, 0, 0 }, { 4, 4, 4, 4, 4, 4 }, 0, PEWC_NATURE_HARDY, 0, { 0,0,0 } }
 
  /* INAT DOS TREINADORES */
  
  // ====== 1. ROXANNE (Ginásio 1) ======
  // ID real do proto: TRAINER_LOCATION01_ROXANNE (procurar no TrainerEnum.proto)
  // Por enquanto uso 1 (TRAINER_SAWYER_1 é 1, mas ROXANNE provavelmente tem outro)
  // Vou usar TRAINER_GRUNT_WEATHER_INST_1 = 17 como placeholder
  // Depois tento achar o ID real ou deixar o sistema de IDs resolver
  
  // ====== 2. BRAWLY (Ginásio 2) ======
  
  // ====== 3. WATSON (Ginásio 3) ======
  
  // ====== 4. FLANNERY (Ginásio 4) ======
  
  // ====== 5. NORMAN (Ginásio 5) ======
  
  // ====== 6. WALLACE (Ginásio 6) ======
  
  // ====== 7. TATE & LIZA (Ginásio 7) ======
  
  // ====== 8. JUAN (Ginásio 8) ======
  
  // ====== 9. SIDNEY (Elite Four #1) ======
  
  // ====== 10. PHOEBE (Elite Four #2) ======
  
  // ====== 11. GLACIA (Elite Four #3) ======
  
  // ====== 12. DRAKE (Elite Four #4) ======
  
  // ====== 13. STEVEN (Campeão) ======
