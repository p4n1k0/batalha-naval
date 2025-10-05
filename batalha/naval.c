#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tabuleiro[10][10];
    int cone[5][5], cruz[5][5], octaedro[5][5];
    int i, j;

    // --- Inicializa o tabuleiro com 0 (água) ---
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // --- Navio 1 (horizontal) ---
    for (j = 1; j <= 3; j++)
        tabuleiro[2][j] = 3;

    // --- Navio 2 (vertical) ---
    for (i = 5; i <= 7; i++)
        tabuleiro[i][6] = 3;

    // --- Navio 3 (diagonal principal) ---
    for (i = 0; i < 3; i++)
        tabuleiro[i][i] = 3;

    // --- Navio 4 (diagonal secundária) ---
    for (i = 0; i < 3; i++)
        tabuleiro[4 + i][9 - i] = 3;

    // ===================================================
    // === MATRIZES DE HABILIDADES ESPECIAIS (5x5) ===
    // ===================================================

    // --- Cone ---
    // Padrão: vértice no topo, expandindo para baixo
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i >= j - 2 && i >= 2 - j) // cria formato triangular
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // --- Cruz ---
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // --- Octaedro ---
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ===================================================
    // === APLICAÇÃO DAS HABILIDADES NO TABULEIRO ===
    // ===================================================

    int origemConeLinha = 1, origemConeColuna = 5;
    int origemCruzLinha = 6, origemCruzColuna = 2;
    int origemOctLinha = 7, origemOctColuna = 7;

    // --- Função de sobreposição simplificada ---
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int linha, coluna;

            // --- Cone ---
            linha = origemConeLinha + i - 2;
            coluna = origemConeColuna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && cone[i][j] == 1)
                tabuleiro[linha][coluna] = 5;

            // --- Cruz ---
            linha = origemCruzLinha + i - 2;
            coluna = origemCruzColuna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && cruz[i][j] == 1)
                tabuleiro[linha][coluna] = 5;

            // --- Octaedro ---
            linha = origemOctLinha + i - 2;
            coluna = origemOctColuna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && octaedro[i][j] == 1)
                tabuleiro[linha][coluna] = 5;
        }
    }

    // ===================================================
    // === EXIBE O TABULEIRO FINAL ===
    // ===================================================

    printf("\n=== TABULEIRO BATALHA NAVAL - NIVEL MESTRE ===\n\n");
    printf("Legenda: 0 = Agua | 3 = Navio | 5 = Habilidade\n\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
