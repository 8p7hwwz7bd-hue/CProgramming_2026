#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// 最小フィールド幅 w を指定できる itoa
void itoa(int n, char s[], int w) {
    int i, sign;

    sign = n;
    i = 0;
    do {
        int digit = n % 10;
        if (digit < 0) {
            digit = -digit;
        }
        s[i++] = digit + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    // 指定幅 w に達するまでスペースを追加する
    while (i < w) {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];

    itoa(123, s, 8);
    printf(" 123 (幅8) : \"%s\"\n", s);

    itoa(-456, s, 8);
    printf("-456 (幅8) : \"%s\"\n", s);

    itoa(123456, s, 4);
    printf(" 123456(幅4): \"%s\"\n", s);

    return 0;
}
