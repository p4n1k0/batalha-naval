#include <stdio.h>

int main()
{
    int tabuleiro[10][10];
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
    // Linha 2, colunas 1 a 3
    for (j = 1; j <= 3; j++)
    {
        tabuleiro[2][j] = 3;
    }

    // --- Navio 2 (vertical) ---
    // Coluna 6, linhas 5 a 7
    for (i = 5; i <= 7; i++)
    {
        tabuleiro[i][6] = 3;
    }

    // --- Navio 3 (diagonal principal: linha e coluna aumentam juntas) ---
    // Começa em (0,0)
    for (i = 0; i < 3; i++)
    {
        tabuleiro[i][i] = 3;
    }

    // --- Navio 4 (diagonal secundária: linha aumenta, coluna diminui) ---
    // Começa em (4,9)
    for (i = 0; i < 3; i++)
    {
        tabuleiro[4 + i][9 - i] = 3;
    }

    // --- Exibe o tabuleiro ---
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
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
