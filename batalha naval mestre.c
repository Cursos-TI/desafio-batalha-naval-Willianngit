#include <stdio.h>

#define TAMANHO 10

// Função para inicializar o tabuleiro com água (0)
int inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    return 0;
}

// exibir o tabuleiro
int exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  ");
    for (int i = 0; i < TAMANHO; i++) printf("%c ", linha[i]);
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            // Exibe os valores numéricos
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Função Cruz (tamanho 5x5)
int aplicarCruz(int tabuleiro[TAMANHO][TAMANHO]) {
    int origemX = 0, origemY = 1; 
    
    // desenho cruz numero 3
    for (int j = origemY; j < origemY + 5; j++) {
        if (j >= 0 && j < TAMANHO) {
            tabuleiro[origemX + 2][j] = 3; 
        }
    }
    
    
    for (int i = origemX; i < origemX + 5; i++) {
        if (i >= 0 && i < TAMANHO) {
            tabuleiro[i][origemY + 2] = 3; 
        }
    }
    
    return 0;
}

// Função habilidade Cone
int aplicarCone(int tabuleiro[TAMANHO][TAMANHO]) {
    int origemX = 6, origemY = 2; 
    
    // Desenho do cone com o número 1
    for (int i = 0; i < 3; i++) { 
        for (int j = -i; j <= i; j++) { 
            int x = origemX + i;
            int y = origemY + j;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                tabuleiro[x][y] = 1; 
            }
        }
    }
    
    return 0;
}

// Função habilidade Octaedro
int aplicarOctaedro(int tabuleiro[TAMANHO][TAMANHO]) {
    int origemX = 4, origemY = 7; 
    
    // octaedro com o numero 2
    int padrao[3][5] = {
        {0, 0, 2, 0, 0},
        {0, 2, 2, 2, 0},
        {0, 0, 2, 0, 0}
    };
    
    // Aplicando no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX + i - 1;
            int y = origemY + j - 2;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                tabuleiro[x][y] = padrao[i][j];
            }
        }
    }
    return 0;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    inicializarTabuleiro(tabuleiro);

    // Aplicar habilidade Cruz 
    aplicarCruz(tabuleiro);

    // Aplicar habilidade Cone 
    aplicarCone(tabuleiro);

    // Aplicar habilidade Octaedro 
    aplicarOctaedro(tabuleiro);

    // Exibir tabuleiro 
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
