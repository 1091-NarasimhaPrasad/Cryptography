#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char message[], int rails) {
    int len = strlen(message);
    char encrypted[len];
    int index = 0;
    for (int i = 0; i < rails; i++) {
    	for(int j = i; j < len; j += rails * 2 - 2) {
            encrypted[index++] = message[j];
            if (i != 0 && i != rails - 1 && j + (rails - i - 1) * 2 < len) {
                encrypted[index++] = message[j + (rails - i - 1) * 2];
            }
        }
    }
    encrypted[index] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}
int main() {
    char message[100];
    int rails;
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    railFenceEncrypt(message, rails);
    return 0;
}
