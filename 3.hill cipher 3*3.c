#include <stdio.h>
#include <string.h>
#define MATRIX_SIZE 2
void matrixMultiply(int key[MATRIX_SIZE][MATRIX_SIZE], int input[MATRIX_SIZE], int result[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i] += key[i][j] * input[j];
    }
        result[i] %= 26; 
    }
}
int main() {
    int key[MATRIX_SIZE][MATRIX_SIZE] = {{2,1}, {3,4}}; 
    char plaintext[100];
    int input[MATRIX_SIZE], result[MATRIX_SIZE];
    printf("Enter the plaintext (uppercase letters only): ");
    scanf("%s", plaintext);
    int len = strlen(plaintext);
    int padding = len % MATRIX_SIZE; 
    if (padding != 0) {
        for (int i = 0; i < MATRIX_SIZE - padding; i++) {
            plaintext[len + i] = 'X'; 
        }
        plaintext[len + MATRIX_SIZE - padding] = '\0'; 
    }
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i += MATRIX_SIZE) {
        input[0] = plaintext[i] - 'A';
        input[1] = plaintext[i + 1] - 'A';
        matrixMultiply(key, input, result);
        printf("%c%c", result[0] + 'A', result[1] + 'A');
    }
    printf("\n");
    return 0;
}
