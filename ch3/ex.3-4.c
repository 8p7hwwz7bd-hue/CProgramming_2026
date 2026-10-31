#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// 最小の負の数にも対応した itoa
void itoa(int n, char s[]) {
    int i, sign;

    sign = n;
    i = 0;
    do {
        int digit = n % 10;
        if (digit < 0) {
            digit = -digit; // 符号反転ではなく余り側を正にする
        }
        s[i++] = digit + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];

    // 通常の数値
    itoa(1234, s);
    printf("1234               : %s\n", s);

    // 最小の負の数 (INT_MIN: -2147483648)
    itoa(INT_MIN, s);
    printf("INT_MIN (-2147483648): %s\n", s);

    return 0;
}
