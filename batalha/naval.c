#include <stdio.h>

int main()
{
    int tabuleiro[10][10];
    int i, j;

    // Inicializa tudo com 0 (água)
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona um navio horizontal (linha 2, colunas 3, 4 e 5)
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Posiciona um navio vertical (coluna 7, linhas 5, 6 e 7)
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Mostra o tabuleiro
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
