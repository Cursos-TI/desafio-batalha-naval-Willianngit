#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};  

    // Criando tabuleiro matriz 10x10 e inicializando com 0 (água)
    int tabuleiro[10][10] = {0}; // Inicializando todas as células com 0

    // Posiciona o navio horizontal (tamanho 3) na linha 2, coluna 3
    int linhaHorizontal = 2, colunaHorizontal = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;  
    }

    // Posiciona o navio vertical (tamanho 3) na coluna H e nas linhas 6, 7 e 8 
    int linhaVertical = 5, colunaVertical = 7; 
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;  
    }

    // Posiciona o navio na diagonal principal na coluna A até C, nas linhas 6, 7 e 8
    int linhaDiagonalPrincipal = 5;  
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiagonalPrincipal + i][i] = 3;  
    }

    // Posiciona o navio na diagonal secundária (tamanho 3) nas colunas J, I e H, e nas linhas 2, 3 e 4
    int linhaDiagonalSecundaria = 1;  
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiagonalSecundaria + i][9 - i] = 3;  
    }

    printf("TABULEIRO BATALHA NAVAL\n");

    // Exibe as colunas (A-J) usando o vetor 'linha'
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);  
    }
    printf("\n");

    // Exibe o tabuleiro com linhas numeradas de 1 a 10
    for (int i = 0; i < 10; i++) {  // Loop para as 10 linhas
        printf("%2d ", i + 1);  
        for (int j = 0; j < 10; j++) {  
            printf("%d ", tabuleiro[i][j]);  
        }
        printf("\n");
    }

    return 0;
}

