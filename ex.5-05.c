#include <stdio.h>

// プロトタイプ宣言
void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main(void)
{
    printf("=== Exercise 5-5: strncpy, strncat, strncmp ===\n");

    char dest[50] = "Hi, ";
    char *src = "123456789";

    // strncpy のテスト
    my_strncpy(dest, src, 3);
    printf("1. strncpy (n=3): \"%s\"\n", dest);

    // strncat のテスト
    char dest2[50] = "Hello";
    my_strncat(dest2, " World!", 3);
    printf("2. strncat (n=3): \"%s\"\n", dest2);

    // strncmp のテスト
    int cmp = my_strncmp("ABCDE", "ABXYZ", 2);
    printf("3. strncmp (n=2) result: %d\n", cmp);

    return 0;
}

void my_strncpy(char *s, char *t, int n)
{
    while (n > 0 && (*s++ = *t++) != '\0') {
        n--;
    }
    while (n > 0) { // 残りがあれば '\0' で埋める
        *s++ = '\0';
        n--;
    }
}

void my_strncat(char *s, char *t, int n)
{
    while (*s != '\0') {
        s++;
    }
    while (n > 0 && (*s++ = *t++) != '\0') {
        n--;
    }
    *s = '\0';
}

int my_strncmp(char *s, char *t, int n)
{
    for ( ; n > 0 && *s == *t; s++, t++, n--) {
        if (*s == '\0' || n == 1) {
            return 0;
        }
    }
    return *s - *t;
}