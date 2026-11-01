#include <stdio.h>

// プロトタイプ宣言
int strend(char *s, char *t);

int main(void)
{
    printf("=== Exercise 5-4: strend function ===\n");

    char *s = "Programming in C";
    char *t1 = "in C";
    char *t2 = "Java";

    printf("strend(\"%s\", \"%s\") -> %d\n", s, t1, strend(s, t1)); // 1 が期待される
    printf("strend(\"%s\", \"%s\") -> %d\n", s, t2, strend(s, t2)); // 0 が期待される

    return 0;
}

int strend(char *s, char *t)
{
    char *bs = s;
    char *bt = t;

    // s と t の末尾までポインタを進める
    while (*s != '\0')
        s++;
    while (*t != '\0')
        t++;

    // 後ろから前へ文字を比較していく
    for ( ; s >= bs && t >= bt; s--, t--) {
        if (*s != *t) {
            return 0; // 一致しなかった
        }
        if (t == bt) {
            return 1; // t の先頭まで完全に一致して到達した
        }
    }
    return 0;
}