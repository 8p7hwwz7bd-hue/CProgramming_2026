#include <stdio.h>

// プロトタイプ宣言
void pointer_strcat(char *s, char *t);

int main(void)
{
    printf("=== Exercise 5-3: Pointer version of strcat ===\n");

    char s[100] = "Hello, ";
    char *t = "World!";

    printf("Before: s = \"%s\", t = \"%s\"\n", s, t);
    pointer_strcat(s, t);
    printf("After:  s = \"%s\"\n", s);

    return 0;
}

void pointer_strcat(char *s, char *t)
{
    while (*s != '\0') {
        s++;
    }
    while ((*s++ = *t++) != '\0')
        ;
}
