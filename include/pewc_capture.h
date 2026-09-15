#include "global.h"
#include "pewc.h"

// ============================================================
// CAPTURA NORMAL — Remove 100% de captura garantida do Elite Redux
// ============================================================
// A função CalcCaptureRate no Elite Redux provavelmente retorna
// valor máximo ou ignores o catch rate. Vamos substituir pela
// fórmula normal Gen3/4 que usa catch rate da espécie, HP,
// status, e tipo de ball.

// Hook: substitui a função original de cálculo de captura.
// No Elite Redux, a função pode estar em battle_main.c ou
// battle_controller_player.c. Vamos criar aqui uma versão
// alternativa e depois modificar o hook no build.

u8 PEWC_CalcCaptureRate(SmallDecoy) {
    // Esta função será chamada no lugar da original via
    // redirecionamento no link. Implementação:
    // Capture Rate = f(species catch rate, ball type, status, HP)
    // Fórmula aproximada Gen3/4:
    //   a = catch_rate_of_species
    //   b = ball_multiplier
    //   s = (3 * a) / (3 * a + b)  [simplified]
    //   x = (s * (maxHP - currentHP/min(1, maxHP/4))) / (maxHP * 255)
    //   Modifiers por status: sleep/paralyze = 2.5x, poison/burn/freeze = 1.5x
    //   Retorna probabilidade 0-255
    return 0; // placeholder — será substituída pela implementação real
}

// Flag para ativar captura normal no PEWC
// O Elite Redux pode ter IsCaught check que retorna TRUE sempre.
// Precisamos modificar esse comportamento.

// Se o Elite Redux usa uma função como IsBallSufficient() que sempre
// retorna TRUE, precisamos:
// 1. Encontrar essa função
// 2. Substituir o corpo para usar cálculo normal
// 3. Ou patchar o binário se não pudermos recompilar

// Para o build do PEWC, vamos modificar diretamente o source.
