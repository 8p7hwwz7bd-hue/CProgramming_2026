#include <stdio.h>

// プロトタイプ宣言
int my_strlen(char *s);
void my_strcpy(char *s, char *t);
int my_strcmp(char *s, char *t);

int main(void)
{
    printf("=== 5.4 Character Pointers and Functions Examples ===\n\n");

    // 1. strlen のテスト
    char *msg = "Hello, Pointers!";
    printf("1. my_strlen(\"%s\") = %d\n", msg, my_strlen(msg));

    // 2. strcpy のテスト
    char src[] = "Copy Source";
    char dest[50];
    my_strcpy(dest, src);
    printf("2. my_strcpy result: \"%s\"\n", dest);

    // 3. strcmp のテスト
    char *str1 = "Apple";
    char *str2 = "Banana";
    int cmp = my_strcmp(str1, str2);
    printf("3. my_strcmp(\"%s\", \"%s\") = %d\n\n", str1, str2, cmp);

    return 0;
}

int my_strlen(char *s)
{
    char *p = s;
    while (*p != '\0') {
        p++;
    }
    return p - s;
}

void my_strcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

int my_strcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}