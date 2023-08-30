#include <stdio.h>
#include <math.h>
int main() {
    int p, q, m, n, dn, e, c, d, x, y;
    printf("Enter the value of p: ");
    scanf("%d", &p);
    printf("Enter the value of q: ");  
    scanf("%d", &q);
    printf("Enter the value of m: ");
    scanf("%d", &m);
    printf("Enter the value of e: ");
    scanf("%d", &e);
    n = p * q;
    dn = (p - 1) * (q - 1);
    for (d = 1; d < dn; d++) {
        if ((e * d) % dn == 1) {
            break;
        }
    }
    c = fmod(pow(m, e), n);
    x = fmod(pow(c, d), n);
    printf("Encrypted text: %d\n", c);
    printf("Decrypted text: %d\n", (int)x);
    return 0;
}
