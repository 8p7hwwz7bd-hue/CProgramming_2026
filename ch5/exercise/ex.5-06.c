#include <stdio.h>

// プロトタイプ宣言
void pointer_reverse(char *s);
int my_strlen_ex(char *s);

int main(void)
{
    printf("=== Exercise 5-6: Pointer version of reverse ===\n");

    char text[50] = "Hello, C language!";
    printf("Before reverse: \"%s\"\n", text);

    pointer_reverse(text);

    printf("After reverse:  \"%s\"\n", text);

    return 0;
}

void pointer_reverse(char *s)
{
    char *end = s;
    char temp;

    // end ポインタを文字列の最後の文字（'\0'の直前）まで進める
    while (*end != '\0') {
        end++;
    }
    end--; 

    // s（先頭）と end（末尾）を交換しながら中央へ向かって進む
    while (s < end) {
        temp = *s;
        *s = *end;
        *end = temp;
        s++;
        end--;
    }
}
