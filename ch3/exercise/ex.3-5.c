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

// 整数 n を b 進数表記に変換して s に格納する
void itob(int n, char s[], int b) {
    int i, sign;
    
    sign = n;
    i = 0;
    do {
        int digit = n % b;
        if (digit < 0) {
            digit = -digit;
        }
        // 10以上の値（16進数など）は 'a'〜'f'（または 'A'〜'F'）に変換
        s[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
    } while ((n /= b) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    int num = 255;

    itob(num, s, 2);
    printf("255 (2進数)  : %s\n", s);

    itob(num, s, 8);
    printf("255 (8進数)  : %s\n", s);

    itob(num, s, 16);
    printf("255 (16進数) : %s\n", s);

    return 0;
}
