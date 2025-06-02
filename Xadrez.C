#include <stdio.h>
#include <stdlib.h>

// Define o tamanho do tabuleiro 8x8
#define BOARD_SIZE 8

// Verifica se a posição (r, c) é válida no tabuleiro
int isValid(int r, int c) {
    return (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE);
}

// Movimentos da torre

void moveTorre(int row, int col) {
    printf("\nMovimentos da Torre a partir da posicao (%d, %d):\n", row, col);

    // Movimento horizontal para a direita
    for (int c = col + 1; c < BOARD_SIZE; c++) {
        printf("(%d, %d) ", row, c);
    }
    // Movimento horizontal para a esquerda
    for (int c = col - 1; c >= 0; c--) {
        printf("(%d, %d) ", row, c);
    }
    // Movimento vertical para cima
    for (int r = row - 1; r >= 0; r--) {
        printf("(%d, %d) ", r, col);
    }
    // Movimento vertical para baixo
    for (int r = row + 1; r < BOARD_SIZE; r++) {
        printf("(%d, %d) ", r, col);
    }
    printf("\n");
}

// Movimentos do bispo
// Uso de loop while para percorrer cada direção até que a posição seja inválida
void moveBispo(int row, int col) {
    printf("\nMovimentos do Bispo a partir da posicao (%d, %d):\n", row, col);
    int r, c;
    
    // Diagonal superior esquerda
    r = row - 1, c = col - 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r--; c--;
    }
    
    // Diagonal superior direita
    r = row - 1, c = col + 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r--; c++;
    }
    
    // Diagonal inferior esquerda
    r = row + 1, c = col - 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r++; c--;
    }
    
    // Diagonal inferior direita
    r = row + 1, c = col + 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r++; c++;
    }
    printf("\n");
}

// Movimentos da rainha

void moveRainha(int row, int col) {
    printf("\nMovimentos da Rainha a partir da posicao (%d, %d):\n", row, col);
    int r, c;
    
    // Movimentos da torre 
    for (int c = col + 1; c < BOARD_SIZE; c++) {
        printf("(%d, %d) ", row, c);
    }
    for (int c = col - 1; c >= 0; c--) {
        printf("(%d, %d) ", row, c);
    }
    for (r = row - 1; r >= 0; r--) {
        printf("(%d, %d) ", r, col);
    }
    for (r = row + 1; r < BOARD_SIZE; r++) {
        printf("(%d, %d) ", r, col);
    }
    
    // Movimentos do bispo
    // Diagonal superior esquerda
    r = row - 1, c = col - 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r--; c--;
    }
    // Diagonal superior direita
    r = row - 1, c = col + 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r--; c++;
    }
    // Diagonal inferior esquerda
    r = row + 1, c = col - 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r++; c--;
    }
    // Diagonal inferior direita
    r = row + 1, c = col + 1;
    while(isValid(r, c)) {
        printf("(%d, %d) ", r, c);
        r++; c++;
    }
    printf("\n");
}

// Movimentos do cavalo
// Uso de loops aninhados para percorrer as possibilidades de deslocamento no intervalo [-2,2]

void moveCavalo(int row, int col) {
    printf("\nMovimentos do Cavalo a partir da posicao (%d, %d):\n", row, col);
    
    // Dois laços aninhados iteram sobre os deslocamentos possíveis
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            // Verifica se o movimento é em L
            if ((abs(i) == 1 && abs(j) == 2) || (abs(i) == 2 && abs(j) == 1)) {
                int newRow = row + i;
                int newCol = col + j;
                if (isValid(newRow, newCol)) {
                    printf("(%d, %d) ", newRow, newCol);
                }
            }
        }
    }
    printf("\n");
}

// Função avançada do bispo: explora uma dada direção diagonal (dr, dc)
void recursivoBishop(int row, int col, int dr, int dc) {
    int newRow = row + dr;
    int newCol = col + dc;
    if (!isValid(newRow, newCol))
        return;
    
    printf("(%d, %d) ", newRow, newCol);
    
    // Chamada recursiva para continuar na mesma direção
    recursivoBishop(newRow, newCol, dr, dc);
}

// Função que agrupa os movimentos avançados do bispo (em todas as diagonais)
void moveAvancadoBispo(int row, int col) {
    printf("\nMovimentos avançados do Bispo (usando recursividade) a partir da posicao (%d, %d):\n", row, col);
    
    printf("Diagonal superior esquerda: ");
    recursivoBishop(row, col, -1, -1);
    
    printf("\nDiagonal superior direita: ");
    recursivoBishop(row, col, -1, 1);
    
    printf("\nDiagonal inferior esquerda: ");
    recursivoBishop(row, col, 1, -1);
    
    printf("\nDiagonal inferior direita: ");
    recursivoBishop(row, col, 1, 1);
    
    printf("\n");
}

int main() {
    int escolha;
    int row, col;
    
    printf("Simulador de Movimentos no Tabuleiro de Xadrez\n");
    printf("------------------------------------------------\n");
    printf("Selecione a peça:\n");
    printf("1. Torre\n");
    printf("2. Bispo\n");
    printf("3. Rainha\n");
    printf("4. Cavalo\n");
    printf("5. Movimento Avancado do Bispo (Recursivo)\n");
    
    printf("Escolha: ");
    scanf("%d", &escolha);

    printf("Digite a posicao inicial (linha e coluna, valores de 0 a 7): ");
    scanf("%d %d", &row, &col);
    if (!isValid(row, col)) {
        printf("Posicao invalida. O tabuleiro varia de 0 a 7.\n");
        return 1;
    }
    
    // Chama a função correspondente à peça selecionada
    switch(escolha) {
        case 1:
            moveTorre(row, col);
            break;
        case 2:
            moveBispo(row, col);
            break;
        case 3:
            moveRainha(row, col);
            break;
        case 4:
            moveCavalo(row, col);
            break;
        case 5:
            moveAvancadoBispo(row, col);
            break;
        default:
            printf("Opcao invalida.\n");
    }
    
    return 0;
}