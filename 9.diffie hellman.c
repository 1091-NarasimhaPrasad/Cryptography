#include <stdio.h>
#include <math.h>
int main() {
    int a, q, xa, xb, ya, yb, ka, kb;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of q: ");
    scanf("%d", &q);
    printf("Enter the value of xa: ");
    scanf("%d", &xa);
    printf("Enter the value of xb: ");
    scanf("%d", &xb);
    ya = fmod(pow(a, xa), q);
    yb = fmod(pow(a, xb), q);
    ka = fmod(pow(yb, xa), q);
    kb = fmod(pow(ya, xb), q);
    printf("Secret key of user A: %d\n", ka);
    printf("Secret key of user B: %d\n", kb);
    return 0;
}
