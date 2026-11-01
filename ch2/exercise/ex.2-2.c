#include <stdio.h>

#define LIM 1000

int main(void) {
    int i, c;
    char s[LIM];

    for (i = 0; i < LIM - 1; ++i) {
        c = getchar();
        if (c == EOF) {
            break;
        }
        if (c == '\n') {
            break;
        }
        s[i] = c;
    }
    s[i] = '\0';

    printf("Input string: %s\n", s);
    return 0;
}
