#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_SIZE 26
int modulo(int a, int b) {
    return (a % b + b) % b;
}
// 2x2
void encrypt2x2(char plaintext[], int key[2][2]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        int p1 = plaintext[i] - 'A';
        int p2 = (i + 1 < len) ? plaintext[i + 1] - 'A' : 0;
        int c1 = modulo((key[0][0] * p1 + key[0][1] * p2), ALPHABET_SIZE);
        int c2 = modulo((key[1][0] * p1 + key[1][1] * p2), ALPHABET_SIZE);
        printf("%c%c", c1 + 'A', c2 + 'A');
    }
    printf("\n");
}
// Function to encrypt using a 3x3 matrix key
void encrypt3x3(char plaintext[], int key[3][3]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 3) {
        int p1 = plaintext[i] - 'A';
        int p2 = (i + 1 < len) ? plaintext[i + 1] - 'A' : 0; 
        int p3 = (i + 2 < len) ? plaintext[i + 2] - 'A' : 0; 
        int c1 = modulo((key[0][0] * p1 + key[0][1] * p2 + key[0][2] * p3), ALPHABET_SIZE);
        int c2 = modulo((key[1][0] * p1 + key[1][1] * p2 + key[1][2] * p3), ALPHABET_SIZE);
        int c3 = modulo((key[2][0] * p1 + key[2][1] * p2 + key[2][2] * p3), ALPHABET_SIZE);
        printf("%c%c%c", c1 + 'A', c2 + 'A', c3 + 'A');
    }
    printf("\n");
}
int main() {
    char plaintext[] = "CAT";
    int key2x2[2][2] = {
        {5, 7},
        {3, 8}
    };
    int key3x3[3][3] = {
        {3,2,1},
        {4,3,2},
        {1,2,4}
    };
    printf("Encrypting using 2x2 matrix:\n");
    encrypt2x2(plaintext, key2x2);
    printf("Encrypting using 3x3 matrix:\n");
    encrypt3x3(plaintext, key3x3);
    return 0;
}
